#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();
signals:
    void lahetaHenkilo(QString, QString, QString);
    void lisaaTietokantaan();

private slots:
    void on_lahetaNappi_clicked();

    void on_arkkuBox_clicked();

    void on_uurnaBox_clicked();

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
