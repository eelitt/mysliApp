#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();

    void asetaCounter(int);
    int annaCounter() const;

signals:
    void lahetaHenkilo(QString, QString, QString, QString, QString, bool);
    void lisaaTietokantaan();

private slots:
    void on_lahetaNappi_clicked();

    void on_arkkuBox_clicked();

    void on_uurnaBox_clicked();



    void on_tyhjennaNappi_clicked();

private:
    Ui::addDialog *ui;
    int counter = 0;
};

#endif // ADDDIALOG_H
