#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QWidget>

#define ROW 13
#define COL 16

#define SNAKESIZE 200
#define DIRECTION_NR 4

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3

class GameWidget : public QWidget {
  Q_OBJECT
public:
  explicit GameWidget(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *);
  void keyPressEvent(QKeyEvent *);

  void gameAgain();
signals:
  void upSignal();
  void downSignal();
  void leftSignal();
  void rightSignal();

public slots:
private:
  QPushButton *upButton;
  QPushButton *downButton;
  QPushButton *leftButton;
  QPushButton *rightButton;
  QPushButton *startButton;
  QPushButton *backButton;
  QLabel *scoreLabel;
  QLabel *scoreShow;
  QLabel *levelLabel;
  QLabel *levelShow;
  int foodx, foody;
  int snake[SNAKESIZE][2];
  int foodcount = 0;
  int direction = 0;

  int score = 0, level = 0;
  QString scoreStr, levelStr;
  QTimer *timer;
private slots:
  void startButtonSlot();
  void timeoutSlot();
  void onUpSlot();
  void onDownSlot();
  void onLeftSlot();
  void onRightSlot();
  bool eatApple();
};

#endif // GAMEWIDGET_H
