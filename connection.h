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

       db.setHostName(" ");
       db.setDatabaseName("henkilotietokanta");
       db.setUserName("*******");
       db.setPassword("*****");
       bool okay = db.open();
       qDebug() << "hei" << okay;
       if (!okay) {

           QMessageBox::critical(nullptr, QObject::tr("Cannot open database1"),
               QObject::tr("unable to establish a database connection.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
           return false;
       }
    return true;
}



#endif // CONNECTION_H
