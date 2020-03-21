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
       query.exec("create table person (id int primary key, " "rivi varchar(20), paikka varchar(20)"
                  "firstname varchar(20), lastname varchar(20))");
       query.exec("insert into person values(1, 1, 101, 'Danny', 'Young')");
       query.exec("insert into person values(2, 2,102, 'Christine', 'Holand')");
       query.exec("insert into person values(3, 3,103, 'Lars', 'Gordon')");
       query.exec("insert into person values(4, 4,104, 'Roberto', 'Robitaille')");
       query.exec("insert into person values(5, 5,105, 'Maria', 'Papadopoulos')");

       query.exec("create table items (id int primary key,"
                                                "imagefile int,"
                                                "itemtype varchar(20),"
                                                "itemtype varchar(20),"
                                                "itemtype varchar(20),"
                                                "description varchar(100))");
       return true;
}




#endif // CONNECTION_H
