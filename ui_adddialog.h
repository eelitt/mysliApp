/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QLineEdit *etuNimiLaatikko;
    QLineEdit *sukunimiLaatikko;
    QLineEdit *lohkoLaatikko;
    QLabel *lohkolappu;
    QLabel *sukunimilappu;
    QLabel *etulappu;
    QPushButton *lahetaNappi;
    QCheckBox *arkkuBox;
    QCheckBox *uurnaBox;
    QLabel *riviLappu;
    QLabel *paikkaLAppu;
    QLineEdit *riviLaatikko;
    QLineEdit *paikkaLaatikko;
    QLabel *counterLaatikko;
    QLabel *counterTeksti;
    QPushButton *tyhjennaNappi;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->resize(518, 366);
        etuNimiLaatikko = new QLineEdit(addDialog);
        etuNimiLaatikko->setObjectName(QStringLiteral("etuNimiLaatikko"));
        etuNimiLaatikko->setGeometry(QRect(50, 90, 113, 21));
        sukunimiLaatikko = new QLineEdit(addDialog);
        sukunimiLaatikko->setObjectName(QStringLiteral("sukunimiLaatikko"));
        sukunimiLaatikko->setGeometry(QRect(50, 140, 113, 21));
        lohkoLaatikko = new QLineEdit(addDialog);
        lohkoLaatikko->setObjectName(QStringLiteral("lohkoLaatikko"));
        lohkoLaatikko->setGeometry(QRect(220, 90, 113, 21));
        lohkolappu = new QLabel(addDialog);
        lohkolappu->setObjectName(QStringLiteral("lohkolappu"));
        lohkolappu->setGeometry(QRect(270, 60, 47, 13));
        sukunimilappu = new QLabel(addDialog);
        sukunimilappu->setObjectName(QStringLiteral("sukunimilappu"));
        sukunimilappu->setGeometry(QRect(90, 120, 47, 13));
        etulappu = new QLabel(addDialog);
        etulappu->setObjectName(QStringLiteral("etulappu"));
        etulappu->setGeometry(QRect(90, 60, 47, 13));
        lahetaNappi = new QPushButton(addDialog);
        lahetaNappi->setObjectName(QStringLiteral("lahetaNappi"));
        lahetaNappi->setGeometry(QRect(40, 250, 441, 81));
        lahetaNappi->setTabletTracking(false);
        lahetaNappi->setFocusPolicy(Qt::StrongFocus);
        arkkuBox = new QCheckBox(addDialog);
        arkkuBox->setObjectName(QStringLiteral("arkkuBox"));
        arkkuBox->setGeometry(QRect(50, 190, 72, 19));
        uurnaBox = new QCheckBox(addDialog);
        uurnaBox->setObjectName(QStringLiteral("uurnaBox"));
        uurnaBox->setGeometry(QRect(110, 190, 72, 19));
        riviLappu = new QLabel(addDialog);
        riviLappu->setObjectName(QStringLiteral("riviLappu"));
        riviLappu->setGeometry(QRect(270, 120, 47, 13));
        paikkaLAppu = new QLabel(addDialog);
        paikkaLAppu->setObjectName(QStringLiteral("paikkaLAppu"));
        paikkaLAppu->setGeometry(QRect(260, 170, 47, 13));
        riviLaatikko = new QLineEdit(addDialog);
        riviLaatikko->setObjectName(QStringLiteral("riviLaatikko"));
        riviLaatikko->setGeometry(QRect(220, 140, 113, 21));
        paikkaLaatikko = new QLineEdit(addDialog);
        paikkaLaatikko->setObjectName(QStringLiteral("paikkaLaatikko"));
        paikkaLaatikko->setGeometry(QRect(220, 190, 113, 21));
        counterLaatikko = new QLabel(addDialog);
        counterLaatikko->setObjectName(QStringLiteral("counterLaatikko"));
        counterLaatikko->setGeometry(QRect(390, 70, 31, 16));
        counterTeksti = new QLabel(addDialog);
        counterTeksti->setObjectName(QStringLiteral("counterTeksti"));
        counterTeksti->setGeometry(QRect(420, 70, 47, 13));
        tyhjennaNappi = new QPushButton(addDialog);
        tyhjennaNappi->setObjectName(QStringLiteral("tyhjennaNappi"));
        tyhjennaNappi->setGeometry(QRect(400, 150, 80, 41));
        tyhjennaNappi->setFocusPolicy(Qt::ClickFocus);

        retranslateUi(addDialog);

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QApplication::translate("addDialog", "Dialog", Q_NULLPTR));
        lohkolappu->setText(QApplication::translate("addDialog", "lohko", Q_NULLPTR));
        sukunimilappu->setText(QApplication::translate("addDialog", "Sukunimi", Q_NULLPTR));
        etulappu->setText(QApplication::translate("addDialog", "etunimi", Q_NULLPTR));
        lahetaNappi->setText(QApplication::translate("addDialog", "l\303\244het\303\244", Q_NULLPTR));
        arkkuBox->setText(QApplication::translate("addDialog", "Arkku", Q_NULLPTR));
        uurnaBox->setText(QApplication::translate("addDialog", "Uurna", Q_NULLPTR));
        riviLappu->setText(QApplication::translate("addDialog", "Rivi", Q_NULLPTR));
        paikkaLAppu->setText(QApplication::translate("addDialog", "Paikka", Q_NULLPTR));
        counterLaatikko->setText(QString());
        counterTeksti->setText(QApplication::translate("addDialog", "l\303\244hetetty", Q_NULLPTR));
        tyhjennaNappi->setText(QApplication::translate("addDialog", "Tyhjenn\303\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
