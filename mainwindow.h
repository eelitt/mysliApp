#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <adddialog.h>
#include <henkilotietokanta.h>
#include <tarkistatunnukset.h>
#include <QMainWindow>
#include <connection.h>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);




    ~MainWindow();

signals:



private slots:

private:

        henkiloTietokanta *tietokantaOlio;
        tarkistaTunnukset *tunnusOlio;




};




#endif // MAINWINDOW_H
