#include "registerwidget.h"
#include "protocal.h"
#include "ui_registerwidget.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <cstring>

RegisterWidget::RegisterWidget(QWidget *parent)
	: QDialog(parent), ui(new Ui::RegisterWidget) {
  ui->setupUi(this);
  this->setWindowTitle("注册");
  this->setWindowIcon(QIcon(":/img/img/register.ico"));

  socket = new QUdpSocket(this);

/**
*qt4
*qt5 不需要做
*/
#if 0
	socket->bind(0);
#endif
  connect(socket, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
}

RegisterWidget::~RegisterWidget() { delete ui; }

void RegisterWidget::on_pushButton_register_clicked() {
  //获取帐号密码=>服务器
  struct rgs_st sendbuf;
  QString cntStr = ui->lineEditUser->text();
  QByteArray cntArr = cntStr.toLatin1();
  const char *c = cntArr.data();
  strncpy(sendbuf.count, c, SIZE);

  QString pwdStr = ui->lineEditPassword->text();
  QByteArray pwdArr = pwdStr.toLatin1();
  pwdArr = QCryptographicHash::hash(pwdArr, QCryptographicHash::Md5);
  pwdArr = pwdArr.toHex();
  char *p = pwdArr.data();
  strncpy(sendbuf.password, p, SIZE);
  socket->writeDatagram(reinterpret_cast<const char *>(&sendbuf),
						QHostAddress(REGISTER_SEVER_IP), REGISTER_SEVER_PORT);
  qDebug() << sendbuf.count << " " << sendbuf.password;
}

void RegisterWidget::readyReadSlot() {
  struct rgs_st rcvbuf;
  socket->readDatagram(reinterpret_cast<char *>(&rcvbuf), sizeof(rcvbuf));
  switch (rcvbuf.statues) {
  case REGISTER_STATUS_OK:
	if (QMessageBox::information(this, QString("注册结果"),
								 QString("恭喜!注册成功"),
								 QMessageBox::Yes) == QMessageBox::Yes) {
	  // TODO
	}
	break;
  case REGISTER_STATUS_FAIL:
	if (QMessageBox::question(this, QString("注册结果"),
							  QString("失败,是否重新注册?"), QMessageBox::Yes,
							  QMessageBox::No) == QMessageBox::No) {
	  close();
	}
	break;
  default:
	break;
  }
}
