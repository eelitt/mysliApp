#include "mainwindow.h"
#include <connection.h>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)

{


    tunnusOlio = new tarkistaTunnukset("kayttajatable");


    tunnusOlio->show();
    qDebug() << tunnusOlio->getIdentification();
    tunnusOlio->exec();



qDebug() << tunnusOlio->getIdentification();

    if(tunnusOlio->getIdentification())
    {
    tunnusOlio->close();
    tietokantaOlio = new henkiloTietokanta("henkilot");
    tietokantaOlio->show();
    }
    }




MainWindow::~MainWindow()
{



    delete tunnusOlio;
    delete tietokantaOlio;


}

