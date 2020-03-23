#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>

static bool createConnection()
{

       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(":memory:");
       if (!db.open()) {
           QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
               QObject::tr("Unable to establish a database connection.\n"
                           "This example needs SQLite support. Please read "
                           "the Qt SQL driver documentation for information how "
                           "to build it.\n\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
           return false;
       }

       QSqlQuery query;
       query.exec("create table henkilot "
                 "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "rivi int," "paikka int,"
                  "firstname varchar(20), lastname varchar(20), burialmethod varchar(20))");
       query.exec("insert into henkilot values(101,1,1, 'Danny', 'Young', 'arkku')");
       query.exec("insert into henkilot values(102,2,2, 'Christine', 'Holand','uurna')");
       query.exec("insert into henkilot values(103,3,3, 'Lars', 'Gordon', 'uurna')");
       query.exec("insert into henkilot values(104,4,4, 'Roberto', 'Robitaille','arkku')");
       query.exec("insert into henkilot values(105,5,5, 'Maria', 'Papadopoulos','arkku')");


       return true;
}




#endif // CONNECTION_H
