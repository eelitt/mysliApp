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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *uurnaBox;
    QLabel *counterLaatikko;
    QLineEdit *etuNimiLaatikko;
    QLabel *riviLappu;
    QLineEdit *sukunimiLaatikko;
    QLineEdit *lohkoLaatikko;
    QLineEdit *paikkaLaatikko;
    QLabel *etulappu;
    QLabel *sukunimilappu;
    QLabel *lohkolappu;
    QLineEdit *riviLaatikko;
    QLabel *paikkaLAppu;
    QCheckBox *arkkuBox;
    QPushButton *tyhjennaNappi;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName(QStringLiteral("addDialog"));
        addDialog->resize(518, 366);
        lahetaNappi = new QPushButton(addDialog);
        lahetaNappi->setObjectName(QStringLiteral("lahetaNappi"));
        lahetaNappi->setGeometry(QRect(40, 250, 441, 81));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        lahetaNappi->setFont(font);
        lahetaNappi->setTabletTracking(false);
        lahetaNappi->setFocusPolicy(Qt::StrongFocus);
        layoutWidget = new QWidget(addDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 80, 314, 145));
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        layoutWidget->setFont(font1);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        uurnaBox = new QCheckBox(layoutWidget);
        uurnaBox->setObjectName(QStringLiteral("uurnaBox"));
        uurnaBox->setFont(font1);

        gridLayout->addWidget(uurnaBox, 5, 1, 1, 1);

        counterLaatikko = new QLabel(layoutWidget);
        counterLaatikko->setObjectName(QStringLiteral("counterLaatikko"));
        counterLaatikko->setFont(font1);

        gridLayout->addWidget(counterLaatikko, 0, 4, 1, 1);

        etuNimiLaatikko = new QLineEdit(layoutWidget);
        etuNimiLaatikko->setObjectName(QStringLiteral("etuNimiLaatikko"));
        etuNimiLaatikko->setFont(font1);

        gridLayout->addWidget(etuNimiLaatikko, 1, 0, 1, 2);

        riviLappu = new QLabel(layoutWidget);
        riviLappu->setObjectName(QStringLiteral("riviLappu"));
        riviLappu->setFont(font1);

        gridLayout->addWidget(riviLappu, 2, 2, 1, 1);

        sukunimiLaatikko = new QLineEdit(layoutWidget);
        sukunimiLaatikko->setObjectName(QStringLiteral("sukunimiLaatikko"));
        sukunimiLaatikko->setFont(font1);

        gridLayout->addWidget(sukunimiLaatikko, 3, 0, 1, 2);

        lohkoLaatikko = new QLineEdit(layoutWidget);
        lohkoLaatikko->setObjectName(QStringLiteral("lohkoLaatikko"));
        lohkoLaatikko->setFont(font1);

        gridLayout->addWidget(lohkoLaatikko, 1, 2, 1, 1);

        paikkaLaatikko = new QLineEdit(layoutWidget);
        paikkaLaatikko->setObjectName(QStringLiteral("paikkaLaatikko"));
        paikkaLaatikko->setFont(font1);

        gridLayout->addWidget(paikkaLaatikko, 5, 2, 1, 1);

        etulappu = new QLabel(layoutWidget);
        etulappu->setObjectName(QStringLiteral("etulappu"));
        etulappu->setFont(font1);

        gridLayout->addWidget(etulappu, 0, 0, 1, 2);

        sukunimilappu = new QLabel(layoutWidget);
        sukunimilappu->setObjectName(QStringLiteral("sukunimilappu"));
        sukunimilappu->setFont(font1);

        gridLayout->addWidget(sukunimilappu, 2, 0, 1, 2);

        lohkolappu = new QLabel(layoutWidget);
        lohkolappu->setObjectName(QStringLiteral("lohkolappu"));
        lohkolappu->setFont(font1);

        gridLayout->addWidget(lohkolappu, 0, 2, 1, 1);

        riviLaatikko = new QLineEdit(layoutWidget);
        riviLaatikko->setObjectName(QStringLiteral("riviLaatikko"));
        riviLaatikko->setFont(font1);

        gridLayout->addWidget(riviLaatikko, 3, 2, 1, 1);

        paikkaLAppu = new QLabel(layoutWidget);
        paikkaLAppu->setObjectName(QStringLiteral("paikkaLAppu"));
        paikkaLAppu->setFont(font1);

        gridLayout->addWidget(paikkaLAppu, 4, 2, 1, 1);

        arkkuBox = new QCheckBox(layoutWidget);
        arkkuBox->setObjectName(QStringLiteral("arkkuBox"));
        arkkuBox->setFont(font1);

        gridLayout->addWidget(arkkuBox, 5, 0, 1, 1);

        tyhjennaNappi = new QPushButton(layoutWidget);
        tyhjennaNappi->setObjectName(QStringLiteral("tyhjennaNappi"));
        tyhjennaNappi->setFont(font1);
        tyhjennaNappi->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(tyhjennaNappi, 3, 3, 1, 1);

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
        lahetaNappi->setText(QApplication::translate("addDialog", "lis\303\244\303\244 tietokantaan", Q_NULLPTR));
        uurnaBox->setText(QApplication::translate("addDialog", "Uurna", Q_NULLPTR));
        counterLaatikko->setText(QString());
        riviLappu->setText(QApplication::translate("addDialog", "Rivi", Q_NULLPTR));
        etulappu->setText(QApplication::translate("addDialog", "etunimi", Q_NULLPTR));
        sukunimilappu->setText(QApplication::translate("addDialog", "Sukunimi", Q_NULLPTR));
        lohkolappu->setText(QApplication::translate("addDialog", "lohko", Q_NULLPTR));
        paikkaLAppu->setText(QApplication::translate("addDialog", "Paikka", Q_NULLPTR));
        arkkuBox->setText(QApplication::translate("addDialog", "Arkku", Q_NULLPTR));
        tyhjennaNappi->setText(QApplication::translate("addDialog", "Tyhjenn\303\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
