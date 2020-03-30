#include <henkilotietokanta.h>
#include <connection.h>

henkiloTietokanta::henkiloTietokanta(const QString &tablename, QWidget *parent) :
    QWidget(parent)

{

    //mainwindow setup
    resize(460, 350);
    setWindowTitle(tr("Henkilötietokanta"));
    QPixmap pixMapIcon(":/resurssit/karsamakivaakuna.jpg");
    QIcon windowIcon(pixMapIcon);
    setWindowIcon(windowIcon);

    //menu
    menuPalkki = new QMenuBar;
    mainMenu = new QMenu(tr("&file"), this);

    menuPalkki->addMenu(mainMenu);


    model = new QSqlTableModel(this);
    addPtr = new addDialog(this);


    //create viewable table
    model->setTable(tablename);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("Lohko"));
    model->setHeaderData(1, Qt::Horizontal, tr("Rivi"));
    model->setHeaderData(2, Qt::Horizontal, tr("Paikka"));
    model->setHeaderData(3, Qt::Horizontal, tr("Etunimi"));
    model->setHeaderData(4, Qt::Horizontal, tr("Sukunimi"));
    model->setHeaderData(5, Qt::Horizontal, tr("arkku/uurna"));

    //show database
    view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();
    view->setSortingEnabled(true);



    //create buttons
    lisaaIhminenButton = new QPushButton(tr("lisää"));
    lisaaIhminenButton->setDefault(true);
    submitButton = new QPushButton(tr("tallenna muutokset"));
    lisaaIhminenButton->setDefault(true);
    removeRowButton = new QPushButton(tr("poista"));
    revertButton = new QPushButton(tr("&revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(lisaaIhminenButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(removeRowButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    QPixmap pixmap(":/resurssit/bin-icon.jpg");
    QIcon buttonIcon(pixmap);
    removeRowButton->setIcon(buttonIcon);
    removeRowButton->setIconSize(pixmap.rect().size());

    //tietokanta connects
    connect(lisaaIhminenButton, &QPushButton::clicked,this, &henkiloTietokanta::add);
    connect(submitButton, &QPushButton::clicked, this, &henkiloTietokanta::submit);
    connect(removeRowButton, &QPushButton::clicked, this, &henkiloTietokanta::removeRow);
    connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
    connect(quitButton, &QPushButton::clicked, this, &henkiloTietokanta::close);


    //add-window connects
    connect(this, SIGNAL(lisaaTietokantaan()), this, SLOT(submit()));
    connect(addPtr,SIGNAL(lahetaHenkilo(QString&, QString&, QString&, QString&, QString&, bool&)),this, SLOT(aseta(QString&, QString&, QString&,QString&, QString&, bool&)));

    //add widgets and menubar
    mainLayout = new QHBoxLayout;
    mainLayout->setMenuBar(menuPalkki);
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

}

henkiloTietokanta::~henkiloTietokanta()
{

    delete model;
    delete addPtr;
    delete lisaaIhminenButton;
    delete quitButton;
    delete revertButton;
    delete submitButton;
    delete removeRowButton;

}

void henkiloTietokanta::submit()

{
    //save data straight to database
    qDebug() << model->database();
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}
void henkiloTietokanta::removeRow()

{
    //removes row according to user input
    QModelIndex index;
    //get selected indexes
    QModelIndexList indexes = view->selectionModel()->selectedIndexes();
    //getting wanted row index
    for(int i = 0; i < indexes.count(); i++)
    {
        index = indexes.at(i);

    }

    //spawning a messagebox
    msgBox.setText("Oot poistamassa henkilöä tietokannasta.");
    msgBox.setInformativeText("Ootko varma?");

    QPushButton *yesButton = msgBox.addButton(tr("kyllä"), QMessageBox::ActionRole);
    QPushButton *backButton = msgBox.addButton(tr("takaisin"), QMessageBox::RejectRole);
    msgBox.exec();
    if(msgBox.clickedButton() == yesButton)
    {
        model->removeRow(index.row());
        model->submitAll();
    }
    else if(msgBox.clickedButton() == backButton)
    {


    }


    delete yesButton;
    delete backButton;
}


void henkiloTietokanta::add()
{
    //show second (insert)window
    addPtr->show();



}
void henkiloTietokanta::aseta(QString &stretu, QString &strSuku, QString &lohkoN, QString &riviNum, QString &paikkaNum, bool &arkku)
{

    QSqlRecord record;
    bool teeRecord;

    //insert data to database...
    //..if row and place values are different

    for(int i = 0;i < model->rowCount(); i++)
    {

record = model->record(i);




       // qDebug() << "Rivi" <<model->record(i).value("Rivi").toString();
        //qDebug() << "paikka" <<model->record(i).value("Paikka").toString();
        qDebug() <<"lupa: " <<teeRecord;

       if(model->record(i).value("Rivi") == riviNum && model->record(i).value("Paikka") == paikkaNum)
        {
            QMessageBox::information(this, tr("Huomio"),tr("tarkista, onko samalla rivilla ja paikalla jo henkilo."));
            teeRecord = false;
            break;


        }
        else
        {
          teeRecord = true;
        }
    }

    if(teeRecord == true)
    {
        qDebug() << model->rowCount();
        QSqlRecord newRecord = model->record();
        newRecord.setValue("lohko", lohkoN);
        newRecord.setValue("Rivi", riviNum);
        newRecord.setValue("Paikka", paikkaNum);
        newRecord.setValue("firstname", stretu);
        newRecord.setValue("lastname", strSuku);

        if(arkku)
        {
            QString metodi = "Arkku";
            newRecord.setValue("burialmethod", metodi);

        }
        else
        {
            QString uurna = "Uurna";
            newRecord.setValue("burialmethod", uurna);

        }
        model->insertRecord(model->rowCount(), newRecord);
        emit lisaaTietokantaan();
    }


}

void henkiloTietokanta::saveToExcel(const QString &tablename)
{


}



