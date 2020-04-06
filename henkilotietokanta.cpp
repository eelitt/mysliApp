#include <henkilotietokanta.h>



henkiloTietokanta::henkiloTietokanta(const QString &tablename, QWidget *parent) :
    QWidget(parent)

{


    mainWindowSetup();

    createMenuActions();
    createMenu();


    addPtr = new addDialog(this);

    setSqlTableModel(tablename);
    showDatabase(model);

    createButtons();

    connectFunctions();

    setMainlayout();
    setStyleSheets();

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
    delete mainMenu;
    delete menuPalkki;
    delete saveToExel;
    delete etsiButton;


}
void henkiloTietokanta::mainWindowSetup()
{

    setFont(QFont("Verdana", 8));
    resize(490, 400);
    setWindowTitle(tr("Henkilötietokanta"));
    QPixmap pixMapIcon(":/resurssit/karsamakivaakuna.jpg");
    QIcon windowIcon(pixMapIcon);
    setWindowIcon(windowIcon);

}
void henkiloTietokanta::setSqlTableModel(const QString &tablename)
{
    //create viewable table
     model = new QSqlTableModel(this);
    model->setTable(tablename);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();



    std::string str1 = model->record().fieldName(0).toStdString();
    const char *lohko = str1.c_str();
    std::string str2 = model->record().fieldName(1).toStdString();
    const char *rivi = str2.c_str();
    std::string str3 = model->record().fieldName(2).toStdString();
    const char *paikka = str3.c_str();
    std::string str4 = model->record().fieldName(3).toStdString();
    const char *etunimi = str4.c_str();
    std::string str5 = model->record().fieldName(4).toStdString();
    const char *sukunimi = str5.c_str();
    std::string str6 = model->record().fieldName(5).toStdString();
    const char *hautaustapa = str6.c_str();

    model->setHeaderData(0, Qt::Horizontal, tr(lohko));
    model->setHeaderData(1, Qt::Horizontal, tr(rivi));
    model->setHeaderData(2, Qt::Horizontal, tr(paikka));
    model->setHeaderData(3, Qt::Horizontal, tr(etunimi));
    model->setHeaderData(4, Qt::Horizontal, tr(sukunimi));
    model->setHeaderData(5, Qt::Horizontal, tr(hautaustapa));

}
void henkiloTietokanta::showDatabase(QSqlTableModel *modeli)
{
    //show database
    view = new QTableView;
    view->setModel(modeli);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    view->setSortingEnabled(true);
    view->setFont(QFont("Verdana", 7));





}

void henkiloTietokanta::setMainlayout()
{

    //add widgets and menubar
    mainLayout = new QHBoxLayout;
    mainLayout->setMenuBar(menuPalkki);
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);


    setLayout(mainLayout);


}
void henkiloTietokanta::setStyleSheets()
{
    menuPalkki->setObjectName("menu");

    setObjectName("pohjamaali");

    setStyleSheet("QWidget#pohjamaali {background-color: qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(115, 109, 108, 255), stop:1 rgba(255, 255, 255, 255));}");
    menuPalkki->setStyleSheet("#menu {background-color: qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(115, 109, 108, 255), stop:1 rgba(255, 255, 255, 255));}");
    view->setStyleSheet("QHeaderView::section{background-color: qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(115, 109, 108, 255), stop:1 rgba(255, 255, 255, 255))}");
        //vastavaribackground-color: qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(232, 180, 171, 255), stop:1 rgba(255, 255, 255, 255));
}

void henkiloTietokanta::createButtons()
{

    lisaaIhminenButton = new QPushButton(tr("lisää"));
    lisaaIhminenButton->setDefault(true);
    submitButton = new QPushButton(tr("tallenna muutokset"));
    lisaaIhminenButton->setDefault(true);
    etsiButton = new QPushButton(tr(""));

    removeRowButton = new QPushButton(tr(""));
    revertButton = new QPushButton(tr("&Palauta muutokset"));


    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(lisaaIhminenButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(etsiButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(removeRowButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);



    setButtonIcons();

    connect(etsiButton, &QPushButton::clicked, this, &henkiloTietokanta::search);
    connect(lisaaIhminenButton, &QPushButton::clicked,this, &henkiloTietokanta::addDataToDatabase);
    connect(submitButton, &QPushButton::clicked, this, &henkiloTietokanta::submitDataToDatabase);
    connect(removeRowButton, &QPushButton::clicked, this, &henkiloTietokanta::removeRow);
    connect(revertButton, &QPushButton::clicked,  this, &henkiloTietokanta::revertAll);



}

void henkiloTietokanta::setButtonIcons()
{
    //removebutton icon
    QPixmap pixmap(":/resurssit/bin-icon.jpg");
    QIcon buttonIcon(pixmap);
    removeRowButton->setIcon(buttonIcon);
    removeRowButton->setIconSize(pixmap.rect().size());

    //etsibutton icon
    QPixmap pixmap2(":/resurssit/etsi.jpg");
    QIcon buttonIcon2(pixmap2);

    etsiButton->setIcon(buttonIcon2);




}

void henkiloTietokanta::submitDataToDatabase()

{

    qDebug() << model->database();
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("henkilotietokanta"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}
void henkiloTietokanta::revertAll()
{
    model->revertAll();

    for(int i = 0; i < model->rowCount(); i++)
    {


        if(view->isRowHidden(i))
        {
            view->showRow(i);
        }
    }
}

void henkiloTietokanta::createMenu()
{

    menuPalkki = new QMenuBar;
    mainMenu = new QMenu(tr("&file"), this);
    menuPalkki->addMenu(mainMenu);
    mainMenu->addAction(saveToExel);
    mainMenu->addAction(quitButton);

}

void henkiloTietokanta::createMenuActions()
{
    saveToExel = new QAction(tr("&Tallenna"), this);
    connect(saveToExel, &QAction::triggered, this, &henkiloTietokanta::saveToExcel);

    quitButton = new QAction(tr("&Quit"), this);
    connect(quitButton, &QAction::triggered, this, &henkiloTietokanta::close);


}

void henkiloTietokanta::removeRow()

{
    QMessageBox *msgBoxPtr;
    msgBoxPtr = &msgBox;
    setupWindowIcon(msgBoxPtr);
    msgBox.setObjectName("boxi");
    msgBox.setStyleSheet("#boxi {background-color:qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(115, 109, 108, 255), stop:1 rgba(255, 255, 255, 255));}");

    msgBox.setFont(QFont("Verdana",8));
    msgBox.setWindowTitle("Poista");
    QModelIndex index;
    QModelIndexList indexes = view->selectionModel()->selectedIndexes();

    if(indexes.count() != 0)
    {
    switch(indexes.count())
    {

    case 1:

    msgBox.setText("Oot poistamassa henkilöä tietokannasta.");
    msgBox.setInformativeText("Ootko varma?");
        break;

    default:
        msgBox.setText("Oot poistamassa henkilöitä tietokannasta.");
        msgBox.setInformativeText("Ootko varma?");
    }

    QPushButton *yesButton = msgBox.addButton(tr("kyllä"), QMessageBox::ActionRole);

    QPushButton *backButton = msgBox.addButton(tr("takaisin"), QMessageBox::RejectRole);
    msgBox.exec();
    if(msgBox.clickedButton() == yesButton)
    {
        for(int j = 0; j <indexes.count(); j++)
        {
            index = indexes.at(j);
            model->removeRow(index.row());
            model->submitAll();
        }

    }
    else if(msgBox.clickedButton() == backButton)
    {


    }


    delete yesButton;
    delete backButton;

    }

}

void henkiloTietokanta::search()
{

    QInputDialog *inputDialog = new QInputDialog;

    QString text;

    setupWindowIcon(inputDialog);
    inputDialog->setObjectName("etsilaatikko");
    inputDialog->setStyleSheet("#etsilaatikko {background-color: qconicalgradient(cx:0, cy:1, angle:348.3, stop:0 rgba(115, 109, 108, 255), stop:1 rgba(255, 255, 255, 255));}");
    inputDialog->setFont(QFont("Verdana", 8));
    inputDialog->setWindowFlags(inputDialog->windowFlags() & (~Qt::WindowContextHelpButtonHint));
    inputDialog->setWindowTitle("Etsi");    
    inputDialog->setLabelText("Anna etsittävä arvo");
    inputDialog->setOkButtonText("Etsi");
    inputDialog->setCancelButtonText("Takaisin");
    inputDialog->exec();


    text = inputDialog->textValue();
    if(!text.isEmpty())
    {
        for(int i = 0; i < model->rowCount(); i++)
        {

            if(model->record(i).value(model->record().fieldName(0)) != text ||
                    model->record(i).value(model->record().fieldName(1)) != text ||
                    model->record(i).value(model->record().fieldName(2)) != text ||
                    model->record(i).value(model->record().fieldName(3)) != text ||
                    model->record(i).value(model->record().fieldName(4)) != text ||
                    model->record(i).value(model->record().fieldName(5)) != text)
            {
                view->hideRow(i);
            }
            if(model->record(i).value(model->record().fieldName(0)) == text ||
                    model->record(i).value(model->record().fieldName(1)) == text ||
                    model->record(i).value(model->record().fieldName(2)) == text ||
                    model->record(i).value(model->record().fieldName(3)) == text ||
                    model->record(i).value(model->record().fieldName(4)) == text ||
                    model->record(i).value(model->record().fieldName(5)) == text)
            {
                view->showRow(i);
            }
        }
    }
    delete inputDialog;

}
void henkiloTietokanta::addDataToDatabase()
{

    addPtr->show();

}
void henkiloTietokanta::aseta(QString &stretu, QString &strSuku, QString &lohkoN, QString &riviNum, QString &paikkaNum, bool &arkku)
{

    bool teeRecord;

    /*insert data to database...
    *..if user given row and place values are not already in the database
    */
    for(int i = 0;i < model->rowCount(); i++)
    {
        if(model->record(i).value(model->record().fieldName(1)) == riviNum && model->record(i).value(model->record().fieldName(2)) == paikkaNum)
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

        QSqlRecord newRecord = model->record();
        newRecord.setValue(newRecord.fieldName(0), lohkoN);
        newRecord.setValue(newRecord.fieldName(1), riviNum);
        newRecord.setValue(newRecord.fieldName(2), paikkaNum);
        newRecord.setValue(newRecord.fieldName(3), stretu);
        newRecord.setValue(newRecord.fieldName(4), strSuku);

        if(arkku)
        {
            QString metodi = "Arkku";
            newRecord.setValue(newRecord.fieldName(5), metodi);

        }
        else
        {
            QString uurna = "Uurna";
            newRecord.setValue(newRecord.fieldName(5), uurna);

        }
        model->insertRecord(model->rowCount(), newRecord);
        emit lisaaTietokantaan();
    }


}
void henkiloTietokanta::connectFunctions()
{
    //add-window connects
    connect(this, SIGNAL(lisaaTietokantaan()), this, SLOT(submitDataToDatabase()));
    connect(addPtr,SIGNAL(lahetaHenkilo(QString&, QString&, QString&, QString&, QString&, bool&)),this, SLOT(aseta(QString&, QString&, QString&,QString&, QString&, bool&)));

}

void henkiloTietokanta::saveToExcel()
{

    QString filename = QFileDialog::getSaveFileName(this, "Tallenna tiedosto", "Tiedoston nimi.csv","CSV files(.csv);;Zip files(.zip, *.7z)", 0, 0);


    QFile data(filename);
    if(data.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream output(&data);
        output        << model->record().fieldName(0)
                      << ";" << model->record().fieldName(1)
                      << ";" << model->record().fieldName(2)
                      << ";" << model->record().fieldName(3)
                      << ";" << model->record().fieldName(4)
                      << ";" << model->record().fieldName(5)
                      << endl;

        for(int i = 0; i <model->rowCount(); i++)
        {
            output        << model->record(i).value(model->record().fieldName(0)).toInt()
                          << ";" << model->record(i).value(model->record().fieldName(1)).toInt()
                          << ";" << model->record(i).value(model->record().fieldName(2)).toInt()
                          << ";" << model->record(i).value(model->record().fieldName(3)).toString()
                          << ";" << model->record(i).value(model->record().fieldName(4)).toString()
                          << ";" << model->record(i).value(model->record().fieldName(5)).toString()
                          << endl;
        }


    }
    data.close();
}

void henkiloTietokanta::setupWindowIcon(QDialog *windowPtr)
{
    QPixmap pixmap(":/resurssit/karsamakivaakuna.jpg");
    QIcon searchWindowIcon(pixmap);

   windowPtr->setWindowIcon(searchWindowIcon);

}

