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

       model->setHeaderData(0, Qt::Horizontal, tr("Lohko"));
       model->setHeaderData(1, Qt::Horizontal, tr("Rivi"));
       model->setHeaderData(2, Qt::Horizontal, tr("Paikka"));
       model->setHeaderData(3, Qt::Horizontal, tr("Etunimi"));
       model->setHeaderData(4, Qt::Horizontal, tr("Sukunimi"));

       QTableView *view = new QTableView;
       view->setModel(model);
       view->resizeColumnsToContents();

       lisaaIhminenButton = new QPushButton(tr("lisää"));
       lisaaIhminenButton->setDefault(true);
       submitButton = new QPushButton(tr("Submit"));
       submitButton->setDefault(true);
       revertButton = new QPushButton(tr("&revert"));
       quitButton = new QPushButton(tr("Quit"));

       buttonBox = new QDialogButtonBox(Qt::Vertical);
           buttonBox->addButton(lisaaIhminenButton, QDialogButtonBox::ActionRole);
           //buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
           buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
           buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

                connect(lisaaIhminenButton, &QPushButton::clicked,this, &MainWindow::add);
               // connect(submitButton, &QPushButton::clicked, this, &MainWindow::submit);
               connect(revertButton, &QPushButton::clicked,  model, &QSqlTableModel::revertAll);
               connect(quitButton, &QPushButton::clicked, this, &MainWindow::close);
               connect(addPtr, SIGNAL(lisaaTietokantaan()), this, SLOT(submit()));
               connect(addPtr,SIGNAL(lahetaHenkilo(QString,QString,QString)),this, SLOT(aseta(QString, QString, QString)));

               QHBoxLayout *mainLayout = new QHBoxLayout;
                  mainLayout->addWidget(view);
                  mainLayout->addWidget(buttonBox);
                  setLayout(mainLayout);

                  setWindowTitle(tr("Cached Table"));






}
MainWindow::~MainWindow()
{

}

void MainWindow::submit()

{
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

void MainWindow::add()
{

addPtr->show();



}
void MainWindow::aseta(QString stretu, QString strSuku, QString lohkoN)
{
    int row = 4;
    model->insertRows(row, 1);
    model->setData(model->index(row, 0),lohkoN);
    model->setData(model->index(row, 1),stretu);
    model->setData(model->index(row, 2), strSuku);


}
