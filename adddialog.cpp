#include "adddialog.h"
#include "ui_adddialog.h"


addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);


    ui->arkkuBox->setChecked(true);
    ui->counterLaatikko->setVisible(false);
    ui->counterTeksti->setVisible(false);

    setInputTypes();

}

addDialog::~addDialog()
{
    delete ui;
}
void addDialog::asetaCounter(int arvo)
{
    counter = arvo;

}
int addDialog::annaCounter() const
{
    return counter;
}

void addDialog::on_lahetaNappi_clicked()
{



    QString strEtu = ui->etuNimiLaatikko->text();
    QString strSuku = ui->sukunimiLaatikko->text();
    QString lohkoNum = ui->lohkoLaatikko->text();
    QString riviNum = ui->riviLaatikko->text();
    QString paikkaNum = ui->paikkaLaatikko->text();

    bool arkku = true;
    if(ui->uurnaBox->isChecked())
    {
        arkku = false;
    }

    //if all wanted data is not given, msgbox is spawned
    if(ui->etuNimiLaatikko->isModified() && ui->sukunimiLaatikko->isModified()
            && ui->lohkoLaatikko->isModified() && ui->riviLaatikko->isModified()
            && ui->paikkaLaatikko->isModified())

    {
        emit lahetaHenkilo(strEtu, strSuku, lohkoNum, riviNum, paikkaNum, arkku);


        /*counter related
        *counter++;
        *QString laskuri = QString::number(annaCounter());
        *ui->counterLaatikko->setText(laskuri);

        *     //show counter
        *ui->counterTeksti->setVisible(true);
        *ui->counterLaatikko->setVisible(true);
        */

        //empty fields for new entry
        ui->etuNimiLaatikko->setText("");
        ui->lohkoLaatikko->setText("");
        ui->sukunimiLaatikko->setText("");
        ui->paikkaLaatikko->setText("");
        ui->riviLaatikko->setText("");
    }
    else{
        QMessageBox::information(this, tr("Huomio"),tr("Kaikkia tarvittavia tietoja ei annettu laatikoihin."));
    }





}

void addDialog::on_arkkuBox_clicked()
{

    ui->uurnaBox->setChecked(false);
}

void addDialog::on_uurnaBox_clicked()
{
    ui->arkkuBox->setChecked(false);
}



void addDialog::on_tyhjennaNappi_clicked()
{

    ui->etuNimiLaatikko->setText("");
    ui->lohkoLaatikko->setText("");
    ui->sukunimiLaatikko->setText("");
    ui->paikkaLaatikko->setText("");
    ui->riviLaatikko->setText("");

}

void addDialog::setInputTypes()
{

    ui->etuNimiLaatikko->setInputMask("AAAAAAAA");
    ui->sukunimiLaatikko->setInputMask("AAAAAAAAA");
    ui->lohkoLaatikko->setInputMask("000");
    ui->riviLaatikko->setInputMask("000");
    ui->paikkaLaatikko->setInputMask("000");

}
