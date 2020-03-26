#include "mainwindow.h"
#include <tarkistatunnukset.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    if(!createConnection())
    {
        return 1;
    }

//tarkistaTunnukset t("kayttajatable");
//t.show();

   MainWindow w;


    return a.exec();

}
