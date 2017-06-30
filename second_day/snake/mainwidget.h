#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "gamewidget.h"
#include <QIcon>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextCodec>
#include <QWidget>

class mainWidget : public QWidget {
  Q_OBJECT

public:
  mainWidget(QWidget *parent = 0);
  ~mainWidget();

private:
  QPushButton *pushButtonSure;
  QIcon *pushButtonSureIcon;
  QPushButton *pushButtonExit;
  QIcon *pushButtonExitIcon;
  QLabel *lable;
  GameWidget *game;
private slots:
  void onPushButtonSureSlot();
  void onPushButtonExitSlot();
};

#endif // MAINWIDGET_H
