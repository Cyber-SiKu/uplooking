#include "loginwidget.h"
#include "chatwidget.h"
#include "registerwidget.h"
#include "ui_loginwidget.h"

loginWidget::loginWidget(QWidget *parent)
	: QWidget(parent), ui(new Ui::loginWidget) {
  ui->setupUi(this);
  this->setWindowTitle("登录");
  this->setWindowIcon(QIcon(":/img/img/login.ico"));
  // logo图片
  QPixmap logoMap = QPixmap(":/img/img/logo.png");
  logoMap =
	  logoMap.scaled(ui->TextLabel_logo->width(), ui->TextLabel_logo->height());
  ui->TextLabel_logo->setPixmap(logoMap);
  // 头像图片
  QPixmap headPhotoMap = QPixmap(":/img/img/head_photo.png");
  headPhotoMap = headPhotoMap.scaled(ui->TextLabel_head_photo->width(),
									 ui->TextLabel_head_photo->height());
  ui->TextLabel_head_photo->setPixmap(headPhotoMap);
}

loginWidget::~loginWidget() { delete ui; }

void loginWidget::on_pushButton_logIn_clicked() {
  ChatWidget *chat = new ChatWidget;
  chat->setAttribute(Qt::WA_DeleteOnClose);
  chat->showChat();
}

void loginWidget::on_pushButton_logUp_clicked() {
  RegisterWidget *re = new RegisterWidget();
  re->setAttribute(Qt::WA_DeleteOnClose);
  re->show();
}
