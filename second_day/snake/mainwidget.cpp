#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent) : QWidget(parent) {
  this->resize(480, 270);
  this->setMaximumSize(480, 270);
  this->setMinimumSize(480, 270);

  QString img_path = QString(tr(":/new/prefix1/img"));
  this->setWindowIcon(QIcon(tr("%1/icon.png").arg(img_path)));
  this->setWindowTitle(tr("贪吃蛇"));

  //添加背景图片
  QPalette paletteThis;
  paletteThis.setBrush(
      QPalette::Background,
      QBrush(QPixmap(tr("%1/back.jpg").arg(img_path)).scaled(480, 270)));
  this->setPalette(paletteThis);
#if 0
  //添加确定按钮
  pushButtonSureIcon;
  pushButtonSureIcon = new QIcon(tr("%1/start.png").arg(img_path));
  QPushButton *pushButtonSure = new QPushButton();
  pushButtonSure->setIcon(*pushButtonSureIcon);
  pushButtonSure->setIconSize(QSize(30, 30));
  pushButtonSure->setFlat(true);
  pushButtonSure->setParent(this);
  pushButtonSure->setGeometry(400, 200, 30, 30);
#endif
#if 0
  //设置确定键
  QPixmap pushButtonSurePixmap(tr("%1/start.png").arg(img_path));
  pushButtonSureIcon = new QIcon(pushButtonSurePixmap);
  pushButtonSure = new QPushButton();
  pushButtonSure->setGeometry(250, 150,
                              pushButtonSurePixmap.rect().size().height(),
                              pushButtonSurePixmap.rect().size().width());
  pushButtonSure->setIcon(*pushButtonSureIcon);
  pushButtonSure->setIconSize(pushButtonSurePixmap.rect().size());
  pushButtonSure->setFlat(true);
  pushButtonSure->setParent(this);
  //设置退出键
  QPixmap pushButtonExitPixmap(tr("%1/quit.png").arg(img_path));
  pushButtonExitIcon = new QIcon(pushButtonExitPixmap);
  pushButtonExit = new QPushButton();
  pushButtonExit->setIcon(pushButtonExitPixmap);
  pushButtonExit->setIconSize(pushButtonSurePixmap.rect().size());
  pushButtonExit->setFlat(true);
  pushButtonExit->setParent(this);
  pushButtonExit->setGeometry(350, 150,
                              pushButtonSurePixmap.rect().size().height(),
                              pushButtonSurePixmap.rect().size().width());
#endif

#if 1
  pushButtonSure = new QPushButton(this);
  pushButtonSure->setGeometry(250, 170, 75, 75);
  pushButtonSure->setIcon(QIcon(tr("%1/start.png").arg(img_path)));
  pushButtonSure->setIconSize(QSize(75, 75));
  pushButtonSure->setFlat(true);

  pushButtonExit = new QPushButton(this);
  pushButtonExit->setGeometry(350, 170, 75, 75);
  pushButtonExit->setIcon(QIcon(tr("%1/quit.png").arg(img_path)));
  pushButtonExit->setIconSize(QSize(75, 75));
  pushButtonExit->setFlat(true);
#endif

  lable = new QLabel(this);
  lable->setText(tr("Welcom to snake world!"));
  lable->setGeometry(10, 10, 400, 50);
  QFont font;
  font.setPixelSize(20);
  font.setBold(true);
  lable->setFont(font);

  //信号与槽
  connect(pushButtonSure, SIGNAL(clicked()), this,
          SLOT(onPushButtonSureSlot()));
  connect(pushButtonExit, SIGNAL(clicked()), this,
          SLOT(onPushButtonExitSlot()));
}

mainWidget::~mainWidget() {
  delete pushButtonExit;
  delete pushButtonSure;
  delete lable;
}

void mainWidget::onPushButtonSureSlot() {
  game = new GameWidget(this);
  game->show();
}
void mainWidget::onPushButtonExitSlot() {
  if (QMessageBox::question(this, QString(tr("退出游戏")),
                            QString(tr("确定退出?")), QMessageBox::Yes,
                            QMessageBox::No) == QMessageBox::Yes) {
    exit(0);
  }
}
