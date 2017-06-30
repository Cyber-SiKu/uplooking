#include "accountwidget.h"
#include "ui_accountwidget.h"

AccountWidget::AccountWidget(QWidget *parent)
	: QDialog(parent), ui(new Ui::AccountWidget) {
  ui->setupUi(this);
  this->setWindowTitle("添加好友");
}

AccountWidget::~AccountWidget() { delete ui; }
