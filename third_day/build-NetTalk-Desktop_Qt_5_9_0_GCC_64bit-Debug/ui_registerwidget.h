/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *spacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEditPassword;
    QSpacerItem *horizontalSpacer_6;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_register;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QStringLiteral("RegisterWidget"));
        RegisterWidget->resize(359, 193);
        layoutWidget = new QWidget(RegisterWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 292, 74));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(spacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));

        horizontalLayout_6->addWidget(label_3);

        lineEditUser = new QLineEdit(layoutWidget);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));
        lineEditUser->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        lineEditUser->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(lineEditUser);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));

        horizontalLayout_7->addWidget(label_4);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        lineEditPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lineEditPassword);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        layoutWidget_2 = new QWidget(RegisterWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 120, 174, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButton_register = new QPushButton(layoutWidget_2);
        pushButton_register->setObjectName(QStringLiteral("pushButton_register"));
        pushButton_register->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));

        horizontalLayout_8->addWidget(pushButton_register);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QDialog *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QApplication::translate("RegisterWidget", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterWidget", "\345\270\220    \345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterWidget", "\345\257\206    \347\240\201", Q_NULLPTR));
        pushButton_register->setText(QApplication::translate("RegisterWidget", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
