#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class loginWidget;
}

class loginWidget : public QWidget {
  Q_OBJECT

public:
  explicit loginWidget(QWidget *parent = 0);
  ~loginWidget();

private slots:
  void on_pushButton_logIn_clicked();

  void on_pushButton_logUp_clicked();

private:
  Ui::loginWidget *ui;
};

#endif // LOGINWIDGET_H
