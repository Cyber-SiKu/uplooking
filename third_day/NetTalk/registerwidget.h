#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QDialog>
#include <QUdpSocket>

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QDialog {
  Q_OBJECT

public:
  explicit RegisterWidget(QWidget *parent = 0);
  ~RegisterWidget();

private slots:
  void on_pushButton_register_clicked();
  void readyReadSlot();

private:
  Ui::RegisterWidget *ui;
  QUdpSocket *socket;
};

#endif // REGISTERWIDGET_H
