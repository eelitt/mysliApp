#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


 if(!createConnection())
 {
     return 1;
 }

   MainWindow w;


    return a.exec();

}
