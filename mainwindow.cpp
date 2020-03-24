#include "mainwindow.h"
#include <connection.h>

MainWindow::MainWindow(const QString &tablename, QWidget *parent) :
    QWidget(parent)

{

    model = new QSqlTableModel(this);
    addPtr = new addDialog(this);


    model->setTable(tablename);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select();
    //create viewable table
    model->setHeaderData(0, Qt::Horizontal, tr("Lohko"));
    model->setHeaderData(1, Qt::Horizontal, tr("Rivi"));
    model->setHeaderData(2, Qt::Horizontal, tr("Paikka"));
    model->setHeaderData(3, Qt::Horizontal, tr("Etunimi"));
    model->setHeaderData(4, Qt::Horizontal, tr("Sukunimi"));
    model->setHeaderData(5, Qt::Horizontal, tr("arkku/uurna"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();

    //create buttons
    lisaaIhminenButton = new QPushButton(tr("lisää"));
    lisaaIhminenButton->setDefault(true);
    submitButton = new QPushButton(tr("tallenna muutokset"));
    lisaaIhminenButton->setDefault(true);
    removeRowButton = new QPushButton(tr("poista henkilö"));
    revertButton = new QPushButton(tr("&revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(lisaaIhminenButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(removeRowButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    //Mainwindow connects
    connect(lisaaIhminenButton, &QPushButton::clicked,this, &MainWindow::add);
    connect(submitButton, &QPushButton::clicked, this, &MainWindow::submit);
    connect(removeRowButton, &QPushButton::clicked, this, &MainWindow::removeRow);
    connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
    connect(quitButton, &QPushButton::clicked, this, &MainWindow::close);

    //add-window connects
    connect(addPtr, SIGNAL(lisaaTietokantaan()), this, SLOT(submit()));
    connect(addPtr,SIGNAL(lahetaHenkilo(QString,QString,QString, QString, QString, bool)),this, SLOT(aseta(QString, QString, QString,QString, QString, bool)));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Cached Table"));





}
MainWindow::~MainWindow()
{

    delete model;
    delete addPtr;
    delete buttonBox;
    delete lisaaIhminenButton;
    delete quitButton;
    delete revertButton;
    delete submitButton;
    delete removeRowButton;


}

void MainWindow::submit()

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
void MainWindow::removeRow()
{
   int row = 0;
    model->removeRow(row);

}

void MainWindow::add()
{
    //show second window
    addPtr->show();



}
void MainWindow::aseta(QString stretu, QString strSuku, QString lohkoN, QString riviNum, QString paikkaNum, bool arkku)
{

    int row = 0;
    model->insertRows(row, 1);
    model->setData(model->index(row, 0),lohkoN);

    model->setData(model->index(row, 1), riviNum);

    model->setData(model->index(row, 2), paikkaNum);

    model->setData(model->index(row, 3),stretu);

    model->setData(model->index(row, 4), strSuku);


    if(arkku)
    {
        QString metodi = "Arkku";
        model->setData(model->index(row, 5), metodi);

    }
    else
    {
        QString uurna = "Uurna";
        model->setData(model->index(row, 5), uurna);

    }
    row++;

}
