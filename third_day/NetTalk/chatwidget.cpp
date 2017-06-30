#include "chatwidget.h"
#include "accountwidget.h"
#include "ui_chatwidget.h"
#include <QDateTime>

ChatWidget::ChatWidget(QWidget *parent)
	: QDialog(parent), ui(new Ui::ChatWidget) {
  ui->setupUi(this);
  this->setWindowTitle("正在聊天");
  this->setWindowIcon(QIcon(":/img/img/chat.ico"));
  ui->pushButton_setting->setIcon(QIcon(":/img/img/setting.png"));
  ui->pushButton_setting->setIconSize(ui->pushButton_setting->size());
  ui->pushButton_setting->setFlat(true);
  ui->pushButton_addFriens->setIcon(QIcon(":/img/img/add.png"));
  ui->pushButton_addFriens->setIconSize(ui->pushButton_addFriens->size());
  ui->pushButton_addFriens->setFlat(true);

  timer = new QTimer(this);
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

ChatWidget::~ChatWidget() { delete ui; }

void ChatWidget::showChat() {
  show();
  timeoutSlot();
}

void ChatWidget::timeoutSlot() {
  QDateTime date = QDateTime::currentDateTime();
  QString dateStr = date.toString(QString("yyyy-MM-dd hh:mm:ss"));
  ui->lcdNumber->display(dateStr);
}

void ChatWidget::on_pushButton_addFriens_clicked() {
  AccountWidget *acc = new AccountWidget();
  acc->show();
}
