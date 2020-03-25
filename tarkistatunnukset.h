#ifndef TARKISTATUNNUKSET_H
#define TARKISTATUNNUKSET_H

#include <QDialog>
#include <QListView>

namespace Ui {
class tarkistaTunnukset;
}

class tarkistaTunnukset : public QDialog
{
    Q_OBJECT

public:
    explicit tarkistaTunnukset(QWidget *parent = 0);
    ~tarkistaTunnukset();

private:
    Ui::tarkistaTunnukset *ui;
};

#endif // TARKISTATUNNUKSET_H
