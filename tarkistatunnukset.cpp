#include "tarkistatunnukset.h"
#include "ui_tarkistatunnukset.h"

tarkistaTunnukset::tarkistaTunnukset(const QString &tablename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarkistaTunnukset)
{

    setupUi();

    setUsedSqlTableModel(tablename);
    setupInfoBoxes();
    setBackground();
    connects();

}

tarkistaTunnukset::~tarkistaTunnukset()
{
    delete ui;
    delete model;

}
void tarkistaTunnukset::setupUi()
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint));

}
void tarkistaTunnukset::setUsedSqlTableModel(const QString &tablename)
{

    model = new QSqlTableModel(this);
    model->setTable(tablename);
    model->select();

}

void tarkistaTunnukset::haeTunnukset(QString &tunnus, QString &salasana)
{
    bool nameTest = false;
    bool passwordTest = false;


    for(int i = 0; i < model->rowCount(); i++)
    {

        QSqlRecord record = model->record(i);

        QString accountName = record.value("kayttaja").toString();

        if(tunnus == accountName)
        {

            nameTest = true;
            break;
        }else
        {
            failInfoBoxAnimations(ui->failPassOrNameBox);
        }
    }

    for(int j = 0; j <model->rowCount(); j++)
    {

        QSqlRecord record = model->record(j);

        QString password = record.value("salasana").toString();


        if(salasana == password)
        {

            passwordTest = true;
            break;
        }else
        {
            failInfoBoxAnimations(ui->failPassOrNameBox);


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
void tarkistaTunnukset::connects()
{

    this->connect(this, SIGNAL(tunnusHaku(QString&,QString&)), this, SLOT(haeTunnukset(QString&, QString&)));
}
void tarkistaTunnukset::setupInfoBoxes()
{
    ui->failPassOrNameBox->setVisible(false);

}

void tarkistaTunnukset::failInfoBoxAnimations(QLabel *Label)

{
    Label->setVisible(true);
    QGraphicsOpacityEffect *endEffect = new QGraphicsOpacityEffect();
    Label->setGraphicsEffect(endEffect);
    QPropertyAnimation *endAnim = new QPropertyAnimation(endEffect, "opacity");
    endAnim->setDuration(2500);
    endAnim->setStartValue(Label->windowOpacity());
    endAnim->setEndValue(0.0);
    endAnim->setEasingCurve(QEasingCurve::OutQuad);
    connect(endAnim, &QPropertyAnimation::finished,[=](){});
    endAnim->start(QAbstractAnimation::DeleteWhenStopped);

}

void tarkistaTunnukset::setBackground()
{

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
