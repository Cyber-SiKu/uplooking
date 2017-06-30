/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QLabel *TextLabel_logo;
    QLabel *TextLabel_head_photo;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_password;
    QLabel *label_user;
    QLabel *label_password;
    QRadioButton *radioButton_remenberPassword;
    QPushButton *pushButton_logIn;
    QPushButton *pushButton_logUp;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->resize(250, 350);
        loginWidget->setStyleSheet(QStringLiteral("selection-background-color: qlineargradient(spread:pad, x1:0.479839, y1:0.125, x2:1, y2:0, stop:0.0362694 rgba(117, 80, 123, 255), stop:1 rgba(255, 255, 255, 255));"));
        TextLabel_logo = new QLabel(loginWidget);
        TextLabel_logo->setObjectName(QStringLiteral("TextLabel_logo"));
        TextLabel_logo->setGeometry(QRect(0, 0, 250, 50));
        TextLabel_logo->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        TextLabel_logo->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        TextLabel_logo->setAlignment(Qt::AlignCenter);
        TextLabel_head_photo = new QLabel(loginWidget);
        TextLabel_head_photo->setObjectName(QStringLiteral("TextLabel_head_photo"));
        TextLabel_head_photo->setGeometry(QRect(80, 80, 91, 91));
        TextLabel_head_photo->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        TextLabel_head_photo->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        TextLabel_head_photo->setAlignment(Qt::AlignCenter);
        lineEdit_user = new QLineEdit(loginWidget);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(120, 200, 113, 26));
        lineEdit_user->setFocusPolicy(Qt::StrongFocus);
        lineEdit_user->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        lineEdit_user->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit_user->setMaxLength(11);
        lineEdit_user->setEchoMode(QLineEdit::Normal);
        lineEdit_user->setAlignment(Qt::AlignCenter);
        lineEdit_password = new QLineEdit(loginWidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(120, 230, 113, 26));
        lineEdit_password->setFocusPolicy(Qt::StrongFocus);
        lineEdit_password->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_password->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        lineEdit_password->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit_password->setMaxLength(11);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_password->setAlignment(Qt::AlignCenter);
        label_user = new QLabel(loginWidget);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setGeometry(QRect(30, 200, 64, 18));
        label_user->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label_user->setTextFormat(Qt::AutoText);
        label_user->setAlignment(Qt::AlignCenter);
        label_password = new QLabel(loginWidget);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(30, 230, 64, 18));
        label_password->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label_password->setAlignment(Qt::AlignCenter);
        radioButton_remenberPassword = new QRadioButton(loginWidget);
        radioButton_remenberPassword->setObjectName(QStringLiteral("radioButton_remenberPassword"));
        radioButton_remenberPassword->setGeometry(QRect(50, 270, 109, 24));
        radioButton_remenberPassword->setFocusPolicy(Qt::StrongFocus);
        radioButton_remenberPassword->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        radioButton_remenberPassword->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pushButton_logIn = new QPushButton(loginWidget);
        pushButton_logIn->setObjectName(QStringLiteral("pushButton_logIn"));
        pushButton_logIn->setGeometry(QRect(10, 310, 87, 26));
        pushButton_logIn->setFocusPolicy(Qt::StrongFocus);
        pushButton_logIn->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        pushButton_logIn->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pushButton_logUp = new QPushButton(loginWidget);
        pushButton_logUp->setObjectName(QStringLiteral("pushButton_logUp"));
        pushButton_logUp->setGeometry(QRect(140, 310, 87, 26));
        pushButton_logUp->setFocusPolicy(Qt::StrongFocus);
        pushButton_logUp->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));
        pushButton_logUp->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        retranslateUi(loginWidget);

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QApplication::translate("loginWidget", "loginWidget", Q_NULLPTR));
        TextLabel_logo->setText(QApplication::translate("loginWidget", "TextLabel", Q_NULLPTR));
        TextLabel_head_photo->setText(QApplication::translate("loginWidget", "TextLabel", Q_NULLPTR));
        lineEdit_user->setPlaceholderText(QApplication::translate("loginWidget", "SiKu", Q_NULLPTR));
        lineEdit_password->setText(QString());
        label_user->setText(QApplication::translate("loginWidget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_password->setText(QApplication::translate("loginWidget", "\345\257\206\347\240\201", Q_NULLPTR));
        radioButton_remenberPassword->setText(QApplication::translate("loginWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_logIn->setText(QApplication::translate("loginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_logUp->setText(QApplication::translate("loginWidget", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
