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

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->resize(400, 300);
        etuNimiLaatikko = new QLineEdit(addDialog);
        etuNimiLaatikko->setObjectName(QStringLiteral("etuNimiLaatikko"));
        etuNimiLaatikko->setGeometry(QRect(100, 90, 113, 21));
        sukunimiLaatikko = new QLineEdit(addDialog);
        sukunimiLaatikko->setObjectName(QStringLiteral("sukunimiLaatikko"));
        sukunimiLaatikko->setGeometry(QRect(100, 150, 113, 21));
        lohkoLaatikko = new QLineEdit(addDialog);
        lohkoLaatikko->setObjectName(QStringLiteral("lohkoLaatikko"));
        lohkoLaatikko->setGeometry(QRect(100, 200, 113, 21));
        lohkolappu = new QLabel(addDialog);
        lohkolappu->setObjectName(QStringLiteral("lohkolappu"));
        lohkolappu->setGeometry(QRect(130, 180, 47, 13));
        sukunimilappu = new QLabel(addDialog);
        sukunimilappu->setObjectName(QStringLiteral("sukunimilappu"));
        sukunimilappu->setGeometry(QRect(120, 130, 47, 13));
        etulappu = new QLabel(addDialog);
        etulappu->setObjectName(QStringLiteral("etulappu"));
        etulappu->setGeometry(QRect(120, 70, 47, 13));
        lahetaNappi = new QPushButton(addDialog);
        lahetaNappi->setObjectName(QStringLiteral("lahetaNappi"));
        lahetaNappi->setGeometry(QRect(250, 140, 80, 21));
        arkkuBox = new QCheckBox(addDialog);
        arkkuBox->setObjectName(QStringLiteral("arkkuBox"));
        arkkuBox->setGeometry(QRect(100, 240, 72, 19));
        uurnaBox = new QCheckBox(addDialog);
        uurnaBox->setObjectName(QStringLiteral("uurnaBox"));
        uurnaBox->setGeometry(QRect(190, 240, 72, 19));

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
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
