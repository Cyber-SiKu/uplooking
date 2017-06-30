#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  //设置编码方式为utf-8
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  QTextCodec::setCodecForLocale(codec);
  mainWidget w;
  w.show();

  return a.exec();
}
