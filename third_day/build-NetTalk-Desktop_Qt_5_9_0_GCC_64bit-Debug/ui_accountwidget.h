/********************************************************************************
** Form generated from reading UI file 'accountwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTWIDGET_H
#define UI_ACCOUNTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccountWidget
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AccountWidget)
    {
        if (AccountWidget->objectName().isEmpty())
            AccountWidget->setObjectName(QStringLiteral("AccountWidget"));
        AccountWidget->resize(323, 174);
        pushButton = new QPushButton(AccountWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 110, 87, 26));
        pushButton->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        label = new QLabel(AccountWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(41, 50, 38, 22));
        label->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(AccountWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(101, 50, 152, 30));
        lineEdit->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));

        retranslateUi(AccountWidget);

        QMetaObject::connectSlotsByName(AccountWidget);
    } // setupUi

    void retranslateUi(QDialog *AccountWidget)
    {
        AccountWidget->setWindowTitle(QApplication::translate("AccountWidget", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AccountWidget", "\347\241\256\350\256\244\346\267\273\345\212\240", Q_NULLPTR));
        label->setText(QApplication::translate("AccountWidget", "\345\270\220\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AccountWidget: public Ui_AccountWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTWIDGET_H
