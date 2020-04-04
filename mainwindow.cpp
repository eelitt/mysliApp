#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)

{


    tunnusOlio = new tarkistaTunnukset("kayttajatable", this);

    tunnusOlio->exec();


    if(tunnusOlio->getIdentification())
    {

        tietokantaOlio = new henkiloTietokanta("henkilot");
        tietokantaOlio->show();
    }
    else
    {
        exit(0);
    }
}




MainWindow::~MainWindow()
{



   delete tietokantaOlio;
   delete tunnusOlio;

}

