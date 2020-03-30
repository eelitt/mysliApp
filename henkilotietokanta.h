#ifndef HENKILOTIETOKANTA_H
#define HENKILOTIETOKANTA_H

#include <adddialog.h>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtSql/QSqlError>
#include <QtWidgets>
#include <QString>
#include <QDebug>
#include <QModelIndexList>
#include <QMenu>
#include <QBoxLayout>
#include <QmenuBar>
#include <QSqlRecord>

class henkiloTietokanta : public QWidget
{
    Q_OBJECT

public:
    explicit henkiloTietokanta(const QString &tablename, QWidget *parent = 0);




    ~henkiloTietokanta();

signals:
void lisaaTietokantaan();


private slots:

    void submit();
    void removeRow();
    void add();
    void aseta(QString&, QString&, QString&, QString&, QString&, bool&);
private:
        void createMenu();
        void createMenuActions();
        void saveToExcel(const QString &);
        QPushButton *lisaaIhminenButton;
        QPushButton *submitButton;
        QPushButton *revertButton;
        QPushButton *quitButton;
        QPushButton *removeRowButton;
        QDialogButtonBox *buttonBox;
        QSqlTableModel *model;
        addDialog *addPtr;
        QMessageBox msgBox;
        QHBoxLayout *mainLayout;
        QMenuBar *menuPalkki;
        QTableView *view;
        QMenu *mainMenu;
        QAction *saveToExel;





};




#endif // HENKILOTIETOKANTA_H
