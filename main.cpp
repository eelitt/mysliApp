#include "mainwindow.h"
#include <tarkistatunnukset.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return 1;

    MainWindow w("henkilot");
    tarkistaTunnukset t;
    t.show();

   // w.show();

    return a.exec();

}
