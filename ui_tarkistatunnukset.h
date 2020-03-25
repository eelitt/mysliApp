/********************************************************************************
** Form generated from reading UI file 'tarkistatunnukset.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARKISTATUNNUKSET_H
#define UI_TARKISTATUNNUKSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tarkistaTunnukset
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *salasanaLaatikko;
    QLabel *label_3;
    QLineEdit *tunnusLaatikko;
    QLabel *label_2;

    void setupUi(QDialog *tarkistaTunnukset)
    {
        if (tarkistaTunnukset->objectName().isEmpty())
            tarkistaTunnukset->setObjectName(QStringLiteral("tarkistaTunnukset"));
        tarkistaTunnukset->resize(500, 500);
        tarkistaTunnukset->setMinimumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QStringLiteral("resurssit/karsamakivaakuna.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tarkistaTunnukset->setWindowIcon(icon);
        layoutWidget = new QWidget(tarkistaTunnukset);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 120, 181, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        salasanaLaatikko = new QLineEdit(layoutWidget);
        salasanaLaatikko->setObjectName(QStringLiteral("salasanaLaatikko"));

        gridLayout->addWidget(salasanaLaatikko, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        tunnusLaatikko = new QLineEdit(layoutWidget);
        tunnusLaatikko->setObjectName(QStringLiteral("tunnusLaatikko"));

        gridLayout->addWidget(tunnusLaatikko, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        layoutWidget->raise();
        label->raise();

        retranslateUi(tarkistaTunnukset);

        QMetaObject::connectSlotsByName(tarkistaTunnukset);
    } // setupUi

    void retranslateUi(QDialog *tarkistaTunnukset)
    {
        tarkistaTunnukset->setWindowTitle(QApplication::translate("tarkistaTunnukset", "Sis\303\244\303\244nkirjautuminen", Q_NULLPTR));
        label->setText(QApplication::translate("tarkistaTunnukset", "Kirjaudu", Q_NULLPTR));
        label_3->setText(QApplication::translate("tarkistaTunnukset", "Salasana", Q_NULLPTR));
        label_2->setText(QApplication::translate("tarkistaTunnukset", "Tunnus", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tarkistaTunnukset: public Ui_tarkistaTunnukset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARKISTATUNNUKSET_H
