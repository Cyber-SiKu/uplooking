#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QDialog {
  Q_OBJECT

public:
  explicit ChatWidget(QWidget *parent = 0);
  ~ChatWidget();

  void showChat();
  QTimer *timer;

private slots:
  void on_pushButton_addFriens_clicked();
  void timeoutSlot();

private:
  Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
