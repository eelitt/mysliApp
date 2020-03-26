#include "tarkistatunnukset.h"
#include "ui_tarkistatunnukset.h"

tarkistaTunnukset::tarkistaTunnukset(const QString &tablename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarkistaTunnukset)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable(tablename);
    model->select();

    this->connect(this, SIGNAL(tunnusHaku(QString&,QString&)), this, SLOT(haeTunnukset(QString&, QString&)));



    //    QPixmap bkgnd(":/resurssit/karsamakivaakuna.jpg");


    /*QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    //resize(bkgnd.size());

    bkgnd.size

    QPalette gndPalette;
    gndPalette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(gndPalette);*/



}

tarkistaTunnukset::~tarkistaTunnukset()
{
    delete ui;
    delete model;

}

void tarkistaTunnukset::haeTunnukset(QString &tunnus, QString &salasana)
{
    bool nameTest =false;
    bool passwordTest =false;


    for(int i = 0; i < model->rowCount(); i++)
    {

        QSqlRecord record = model->record(i);

        QString accountName = record.value("kayttaja").toString();

        if(tunnus == accountName)
        {
            qDebug() << accountName;
            nameTest = true;
            break;
        }else
        {

        }
    }

    for(int j = 0; j <model->rowCount(); j++)
    {

        QSqlRecord record = model->record(j);

        QString password = record.value("salasana").toString();


        if(salasana == password)
        {
            qDebug() << password;
            passwordTest = true;
            break;
        }else
        {

        }
    }

    if(nameTest == true && passwordTest == true)
    {
      identification = true;

        this->close();
    }
    else
    {
        qDebug() << "haista paska";
    }



}

void tarkistaTunnukset::on_pushButton_clicked()
{

    QString tunnus = ui->tunnusLaatikko->text();

    QString salasana = ui->salasanaLaatikko->text();


        emit tunnusHaku(tunnus, salasana);



}
bool tarkistaTunnukset::getIdentification() const
{
    return identification;


}
