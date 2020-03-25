#include "tarkistatunnukset.h"
#include "ui_tarkistatunnukset.h"

tarkistaTunnukset::tarkistaTunnukset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tarkistaTunnukset)
{
    ui->setupUi(this);





    QPixmap bkgnd(":/resurssit/karsamakivaakuna.jpg");
    resize(bkgnd.size());

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette gndPalette;
    gndPalette.setBrush(QPalette::Window, bkgnd);

    this->setPalette(gndPalette);



}

tarkistaTunnukset::~tarkistaTunnukset()
{
    delete ui;
}
