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
#include <string>


class henkiloTietokanta : public QWidget
{
    Q_OBJECT

public:

    explicit henkiloTietokanta(const QString &tablename, QWidget *parent = 0);

    ~henkiloTietokanta();

signals:

void lisaaTietokantaan();



private slots:

    void submitDataToDatabase();
    void removeRow();
    void search();
    void revertAll();
    void addDataToDatabase();
    void aseta(QString&, QString&, QString&, QString&, QString&, bool&);

private:
        void setupWindowIcon(QDialog*);
        void connectFunctions();
        void showDatabase(QSqlTableModel *);
        void setSqlTableModel(const QString &);
        void setMainlayout();
        void createButtons();
        void setButtonIcons();
        void mainWindowSetup();
        void createMenu();
        void createMenuActions();
        void saveToExcel();
        void setStyleSheets();
        QPushButton *lisaaIhminenButton;
        QPushButton *submitButton;
        QPushButton *revertButton;
        QPushButton *removeRowButton;
        QPushButton *etsiButton;
        QDialogButtonBox *buttonBox;
        QSqlTableModel *model;
        addDialog *addPtr;
        QMessageBox msgBox;
        QHBoxLayout *mainLayout;
        QMenuBar *menuPalkki;
        QTableView *view;
        QMenu *mainMenu;
        QAction *saveToExel;
        QAction *quitButton;





};




#endif // HENKILOTIETOKANTA_H
