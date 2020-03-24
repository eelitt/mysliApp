#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>

static bool createConnection()
{

       QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("127.0.0.1");
       db.setDatabaseName("henkilotietokanta");
       db.setUserName("root");
       db.setPassword("asd");
       if (!db.open()) {
           QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
               QObject::tr("Unable to establish a database connection.\n"
                           "This example needs SQLite support. Please read "
                           "the Qt SQL driver documentation for information how "
                           "to build it.\n\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
           return false;
       }





       return true;
}




#endif // CONNECTION_H
