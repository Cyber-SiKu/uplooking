/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QTreeWidget *treeWidget;
    QLabel *label;
    QPushButton *pushButton_addFriens;
    QTextEdit *textEdit_chat;
    QLabel *label_3;
    QPushButton *pushButton_setting;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit_input;
    QPushButton *pushButton_send;

    void setupUi(QDialog *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(751, 408);
        treeWidget = new QTreeWidget(ChatWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(60, 0, 241, 411));
        label = new QLabel(ChatWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 61, 411));
        label->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0.238342 rgba(136, 138, 133, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_addFriens = new QPushButton(ChatWidget);
        pushButton_addFriens->setObjectName(QStringLiteral("pushButton_addFriens"));
        pushButton_addFriens->setGeometry(QRect(0, 290, 61, 61));
        textEdit_chat = new QTextEdit(ChatWidget);
        textEdit_chat->setObjectName(QStringLiteral("textEdit_chat"));
        textEdit_chat->setEnabled(false);
        textEdit_chat->setGeometry(QRect(300, 30, 451, 231));
        label_3 = new QLabel(ChatWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 240, 451, 41));
        label_3->setStyleSheet(QStringLiteral(""));
        pushButton_setting = new QPushButton(ChatWidget);
        pushButton_setting->setObjectName(QStringLiteral("pushButton_setting"));
        pushButton_setting->setGeometry(QRect(0, 350, 61, 61));
        lcdNumber = new QLCDNumber(ChatWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setEnabled(true);
        lcdNumber->setGeometry(QRect(300, 0, 451, 31));
        QFont font;
        font.setFamily(QStringLiteral("WenQuanYi Micro Hei"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QLatin1String("font: 75 11pt \"WenQuanYi Micro Hei\";\n"
"color: rgb(164, 0, 0);"));
        lcdNumber->setDigitCount(20);
        textEdit_input = new QTextEdit(ChatWidget);
        textEdit_input->setObjectName(QStringLiteral("textEdit_input"));
        textEdit_input->setGeometry(QRect(300, 280, 401, 131));
        pushButton_send = new QPushButton(ChatWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(696, 260, 61, 151));
        pushButton_send->setStyleSheet(QStringLiteral("font: 14pt \"WenQuanYi Micro Hei\";"));

        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QDialog *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "Dialog", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ChatWidget", "\346\210\221\347\232\204\345\245\275\345\217\213", Q_NULLPTR));
        label->setText(QString());
        pushButton_addFriens->setText(QString());
        label_3->setText(QString());
        pushButton_setting->setText(QString());
        pushButton_send->setText(QApplication::translate("ChatWidget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
