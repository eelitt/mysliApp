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
       query.exec("create table person (id int primary key, "
                  "firstname varchar(20), lastname varchar(20))");
       query.exec("insert into person values( 101, 'Danny', 'Young')");
       query.exec("insert into person values(102, 'Christine', 'Holand')");
       query.exec("insert into person values(103, 'Lars', 'Gordon')");
       query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
       query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

       query.exec("create table items (id int primary key,"
                                                "imagefile int,"
                                                "itemtype varchar(20),"
                                                "description varchar(100))");
       return true;
}




#endif // CONNECTION_H
