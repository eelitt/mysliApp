#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    ui->arkkuBox->setChecked(true);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_lahetaNappi_clicked()
{
QString strEtu = ui->etuNimiLaatikko->text();
QString strSuku = ui->sukunimiLaatikko->text();
QString lohkoNum = ui->lohkoLaatikko->text();

emit lahetaHenkilo(strEtu, strSuku, lohkoNum);
emit lisaaTietokantaan();

}

void addDialog::on_arkkuBox_clicked()
{


}

void addDialog::on_uurnaBox_clicked()
{
    ui->arkkuBox->setChecked(false);
}
