#include "registerwidget.h"
#include "ui_registerwidget.h"

RegisterWidget::RegisterWidget(QWidget *parent)
	: QDialog(parent), ui(new Ui::RegisterWidget) {
  ui->setupUi(this);
  this->setWindowTitle("注册");
  this->setWindowIcon(QIcon(":/img/img/register.ico"));
}

RegisterWidget::~RegisterWidget() { delete ui; }

void RegisterWidget::on_pushButton_register_clicked() {
  //获取帐号密码=>服务器
}
