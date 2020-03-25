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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addDialog
{
public:
    QPushButton *lahetaNappi;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *etulappu;
    QLabel *lohkolappu;
    QLabel *counterLaatikko;
    QLabel *counterTeksti;
    QLineEdit *etuNimiLaatikko;
    QLineEdit *lohkoLaatikko;
    QLabel *sukunimilappu;
    QLabel *riviLappu;
    QLineEdit *sukunimiLaatikko;
    QLineEdit *riviLaatikko;
    QPushButton *tyhjennaNappi;
    QLabel *paikkaLAppu;
    QCheckBox *arkkuBox;
    QCheckBox *uurnaBox;
    QLineEdit *paikkaLaatikko;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->resize(518, 366);
        lahetaNappi = new QPushButton(addDialog);
        lahetaNappi->setObjectName(QStringLiteral("lahetaNappi"));
        lahetaNappi->setGeometry(QRect(40, 250, 441, 81));
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        font.setBold(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        lahetaNappi->setFont(font);
        lahetaNappi->setTabletTracking(false);
        lahetaNappi->setFocusPolicy(Qt::StrongFocus);
        widget = new QWidget(addDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 80, 314, 137));
        widget->setFont(font);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        etulappu = new QLabel(widget);
        etulappu->setObjectName(QStringLiteral("etulappu"));
        etulappu->setFont(font);

        gridLayout->addWidget(etulappu, 0, 0, 1, 2);

        lohkolappu = new QLabel(widget);
        lohkolappu->setObjectName(QStringLiteral("lohkolappu"));
        lohkolappu->setFont(font);

        gridLayout->addWidget(lohkolappu, 0, 2, 1, 1);

        counterLaatikko = new QLabel(widget);
        counterLaatikko->setObjectName(QStringLiteral("counterLaatikko"));
        counterLaatikko->setFont(font);

        gridLayout->addWidget(counterLaatikko, 0, 3, 1, 1);

        counterTeksti = new QLabel(widget);
        counterTeksti->setObjectName(QStringLiteral("counterTeksti"));
        counterTeksti->setFont(font);

        gridLayout->addWidget(counterTeksti, 0, 4, 1, 1);

        etuNimiLaatikko = new QLineEdit(widget);
        etuNimiLaatikko->setObjectName(QStringLiteral("etuNimiLaatikko"));
        etuNimiLaatikko->setFont(font);

        gridLayout->addWidget(etuNimiLaatikko, 1, 0, 1, 2);

        lohkoLaatikko = new QLineEdit(widget);
        lohkoLaatikko->setObjectName(QStringLiteral("lohkoLaatikko"));
        lohkoLaatikko->setFont(font);

        gridLayout->addWidget(lohkoLaatikko, 1, 2, 1, 1);

        sukunimilappu = new QLabel(widget);
        sukunimilappu->setObjectName(QStringLiteral("sukunimilappu"));
        sukunimilappu->setFont(font);

        gridLayout->addWidget(sukunimilappu, 2, 0, 1, 2);

        riviLappu = new QLabel(widget);
        riviLappu->setObjectName(QStringLiteral("riviLappu"));
        riviLappu->setFont(font);

        gridLayout->addWidget(riviLappu, 2, 2, 1, 1);

        sukunimiLaatikko = new QLineEdit(widget);
        sukunimiLaatikko->setObjectName(QStringLiteral("sukunimiLaatikko"));
        sukunimiLaatikko->setFont(font);

        gridLayout->addWidget(sukunimiLaatikko, 3, 0, 1, 2);

        riviLaatikko = new QLineEdit(widget);
        riviLaatikko->setObjectName(QStringLiteral("riviLaatikko"));
        riviLaatikko->setFont(font);

        gridLayout->addWidget(riviLaatikko, 3, 2, 1, 1);

        tyhjennaNappi = new QPushButton(widget);
        tyhjennaNappi->setObjectName(QStringLiteral("tyhjennaNappi"));
        tyhjennaNappi->setFont(font);
        tyhjennaNappi->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(tyhjennaNappi, 3, 3, 2, 2);

        paikkaLAppu = new QLabel(widget);
        paikkaLAppu->setObjectName(QStringLiteral("paikkaLAppu"));
        paikkaLAppu->setFont(font);

        gridLayout->addWidget(paikkaLAppu, 4, 2, 1, 1);

        arkkuBox = new QCheckBox(widget);
        arkkuBox->setObjectName(QStringLiteral("arkkuBox"));
        arkkuBox->setFont(font);

        gridLayout->addWidget(arkkuBox, 5, 0, 1, 1);

        uurnaBox = new QCheckBox(widget);
        uurnaBox->setObjectName(QStringLiteral("uurnaBox"));
        uurnaBox->setFont(font);

        gridLayout->addWidget(uurnaBox, 5, 1, 1, 1);

        paikkaLaatikko = new QLineEdit(widget);
        paikkaLaatikko->setObjectName(QStringLiteral("paikkaLaatikko"));
        paikkaLaatikko->setFont(font);

        gridLayout->addWidget(paikkaLaatikko, 5, 2, 1, 1);

        QWidget::setTabOrder(etuNimiLaatikko, sukunimiLaatikko);
        QWidget::setTabOrder(sukunimiLaatikko, lohkoLaatikko);
        QWidget::setTabOrder(lohkoLaatikko, riviLaatikko);
        QWidget::setTabOrder(riviLaatikko, paikkaLaatikko);
        QWidget::setTabOrder(paikkaLaatikko, lahetaNappi);
        QWidget::setTabOrder(lahetaNappi, uurnaBox);
        QWidget::setTabOrder(uurnaBox, arkkuBox);

        retranslateUi(addDialog);

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QApplication::translate("addDialog", "Dialog", Q_NULLPTR));
        lahetaNappi->setText(QApplication::translate("addDialog", "l\303\244het\303\244", Q_NULLPTR));
        etulappu->setText(QApplication::translate("addDialog", "etunimi", Q_NULLPTR));
        lohkolappu->setText(QApplication::translate("addDialog", "lohko", Q_NULLPTR));
        counterLaatikko->setText(QString());
        counterTeksti->setText(QApplication::translate("addDialog", "l\303\244hetetty", Q_NULLPTR));
        sukunimilappu->setText(QApplication::translate("addDialog", "Sukunimi", Q_NULLPTR));
        riviLappu->setText(QApplication::translate("addDialog", "Rivi", Q_NULLPTR));
        tyhjennaNappi->setText(QApplication::translate("addDialog", "Tyhjenn\303\244", Q_NULLPTR));
        paikkaLAppu->setText(QApplication::translate("addDialog", "Paikka", Q_NULLPTR));
        arkkuBox->setText(QApplication::translate("addDialog", "Arkku", Q_NULLPTR));
        uurnaBox->setText(QApplication::translate("addDialog", "Uurna", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
