#ifndef TARKISTATUNNUKSET_H
#define TARKISTATUNNUKSET_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>




namespace Ui {
class tarkistaTunnukset;
}

class tarkistaTunnukset : public QDialog
{
    Q_OBJECT

public:
    explicit tarkistaTunnukset(const QString &tablename,QWidget *parent = 0);
    ~tarkistaTunnukset();

    bool getIdentification() const;

signals:
    void tunnusHaku(QString&, QString&);

private slots:
    void haeTunnukset(QString&, QString&);
    void on_pushButton_clicked();

private:

    Ui::tarkistaTunnukset *ui;
    bool identification = false;

    QSqlTableModel *model;

};

#endif // TARKISTATUNNUKSET_H
