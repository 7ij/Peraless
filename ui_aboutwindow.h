/********************************************************************************
** Form generated from reading UI file 'aboutwindowJqSZBV.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTWINDOWJQSZBV_H
#define ABOUTWINDOWJQSZBV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *lblAboutTxt;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(365, 111);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblAboutTxt = new QLabel(Form);
        lblAboutTxt->setObjectName(QString::fromUtf8("lblAboutTxt"));

        gridLayout->addWidget(lblAboutTxt, 0, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        lblAboutTxt->setText(QCoreApplication::translate("Form", "<html><head/><body><p align=\"center\">This is Another Khoi Vaja Vaji Project by</p><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Ashiqur Rahman Nayeem</span></p><p align=\"center\">Mathematics, SUST</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTWINDOWJQSZBV_H
