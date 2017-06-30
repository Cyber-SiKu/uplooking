#include "gamewidget.h"
#include <QDebug>
#include <QMessageBox>
#include <stdlib.h>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
  this->setAutoFillBackground(true);
  this->resize(480, 270);
  this->setMaximumSize(480, 270);
  this->setMinimumSize(480, 270);
  //添加背景图片
  QPalette paletteThis;
  QString img_path = QString(tr(":/new/prefix1/img"));
  paletteThis.setBrush(
      QPalette::Background,
      QBrush(QPixmap(tr("%1/green.jpg").arg(img_path)).scaled(480, 270)));
  this->setPalette(paletteThis);

  upButton = new QPushButton(this);
  upButton->setText("w");
  upButton->setGeometry(380, 90, 40, 30);

  downButton = new QPushButton(this);
  downButton->setText("s");
  downButton->setGeometry(380, 170, 40, 30);

  leftButton = new QPushButton(this);
  leftButton->setText("a");
  leftButton->setGeometry(340, 130, 40, 30);

  rightButton = new QPushButton(this);
  rightButton->setText("d");
  rightButton->setGeometry(420, 130, 40, 30);

  startButton = new QPushButton(this);
  startButton->setText("开始");
  startButton->setGeometry(350, 220, 40, 30);

  backButton = new QPushButton(this);
  backButton->setText("返回");
  backButton->setGeometry(410, 220, 40, 30);

  scoreLabel = new QLabel(QString(tr("分数")), this);
  scoreLabel->setGeometry(325, 1, 60, 30);

  scoreLabel = new QLabel(QString(tr("等级")), this);
  scoreLabel->setGeometry(325, 30, 60, 30);

  QFont font;
  font.setPixelSize(20);
  font.setBold(true);

  scoreStr = QString::number(score);
  scoreShow = new QLabel(this);
  scoreShow->setText(scoreStr);
  scoreShow->setGeometry(385, 1, 60, 30);
  scoreShow->setFont(font);

  levelShow = new QLabel(this);
  levelStr = QString::number(score);
  levelShow = new QLabel(this);
  levelShow->setText(levelStr);
  levelShow->setGeometry(385, 30, 60, 30);
  levelShow->setFont(font);
  //产生蛇头和食物的位置
  srand(time(NULL));
  foodx = rand() % COL;
  foody = rand() % ROW;
  snake[0][0] = rand() % COL;
  snake[0][1] = rand() % ROW;
  while (1) {
    if (foodx == snake[0][0] && foody == snake[0][1]) {
      snake[0][0] = rand() % COL;
      snake[0][1] = rand() % ROW;
    } else {
      break;
    }
  }
  foodcount = 0;
  direction = rand() % DIRECTION_NR;

  timer = new QTimer(this);
  timer->setInterval(500);
  connect(startButton, SIGNAL(clicked()), this, SLOT(startButtonSlot()));
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
  //连接方向键与槽
  connect(upButton, SIGNAL(clicked()), this, SLOT(onUpSlot()));
  connect(downButton, SIGNAL(clicked()), this, SLOT(onDownSlot()));
  connect(leftButton, SIGNAL(clicked()), this, SLOT(onLeftSlot()));
  connect(rightButton, SIGNAL(clicked()), this, SLOT(onRightSlot()));

  connect(this, SIGNAL(leftSignal()), leftButton, SLOT(click()));
  connect(this, SIGNAL(rightSignal()), rightButton, SLOT(click()));
  connect(this, SIGNAL(upSignal()), upButton, SLOT(click()));
  connect(this, SIGNAL(downSignal()), downButton, SLOT(click()));
}

//画图
void GameWidget::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  //画格子
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      painter.drawRect(QRect(j * 20, i * 20, 20, 20));
    }
  }

  QString img_path = QString(tr(":/new/prefix1/img"));

  //画食物
  painter.drawImage(foodx * 20, foody * 20,
                    QImage(tr("%1/apple.png").arg(img_path)).scaled(20, 20));

  //画蛇

  //画蛇头
  switch (direction) {
  case DIRECTION_UP:
    painter.drawImage(snake[0][0] * 20, snake[0][1] * 20,
                      QImage(tr("%1/headup.png").arg(img_path)).scaled(20, 20));
    break;
  case DIRECTION_DOWN:
    painter.drawImage(
        snake[0][0] * 20, snake[0][1] * 20,
        QImage(tr("%1/headdown.png").arg(img_path)).scaled(20, 20));
    break;
  case DIRECTION_LEFT:
    painter.drawImage(
        snake[0][0] * 20, snake[0][1] * 20,
        QImage(tr("%1/headleft.png").arg(img_path)).scaled(20, 20));
    break;
  case DIRECTION_RIGHT:
    painter.drawImage(
        snake[0][0] * 20, snake[0][1] * 20,
        QImage(tr("%1/headright.png").arg(img_path)).scaled(20, 20));
    break;
  default:
    break;
  }
  //蛇身
  for (int i = 1; i <= foodcount; i++) {
    if (foodcount == i) {
      //蛇尾
      if (snake[i][0] == snake[i - 1][0] &&
          snake[i][1] == snake[i - 1][1] + 1) {
        painter.drawImage(
            snake[foodcount][0] * 20, snake[foodcount][1] * 20,
            QImage(tr("%1/tailup.png").arg(img_path)).scaled(20, 20));
        break;
      } else if (snake[i][0] == snake[i - 1][0] &&
                 snake[i][1] == snake[i - 1][1] - 1) {
        painter.drawImage(
            snake[foodcount][0] * 20, snake[foodcount][1] * 20,
            QImage(tr("%1/taildown.png").arg(img_path)).scaled(20, 20));
        break;
      } else if (snake[i][0] == snake[i - 1][0] + 1 &&
                 snake[i][1] == snake[i - 1][1]) {
        painter.drawImage(
            snake[foodcount][0] * 20, snake[foodcount][1] * 20,
            QImage(tr("%1/tailleft.png").arg(img_path)).scaled(20, 20));
        break;
      } else if (snake[i][0] == snake[i - 1][0] - 1 &&
                 snake[i][1] == snake[i - 1][1]) {
        painter.drawImage(
            snake[foodcount][0] * 20, snake[foodcount][1] * 20,
            QImage(tr("%1/tailright.png").arg(img_path)).scaled(20, 20));
        break;
      }
    } else {
      if (((snake[i][0] == snake[i - 1][0] + 1 &&
            snake[i][1] == snake[i - 1][1]) &&
           (snake[i][0] == snake[i + 1][0] &&
            snake[i][1] == snake[i + 1][1] - 1)) ||
          ((snake[i][0] == snake[i + 1][0] + 1 &&
            snake[i][1] == snake[i + 1][1]) &&
           (snake[i][0] == snake[i - 1][0] &&
            snake[i][1] == snake[i - 1][1] - 1))) {
        //拐弯右上
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/tr_corner.png").arg(img_path)).scaled(20, 20));
      } else if (((snake[i][0] == snake[i - 1][0] + 1 &&
                   snake[i][1] == snake[i - 1][1]) &&
                  (snake[i][0] == snake[i + 1][0] &&
                   snake[i][1] == snake[i + 1][1] + 1)) ||
                 ((snake[i][0] == snake[i + 1][0] + 1 &&
                   snake[i][1] == snake[i + 1][1]) &&
                  (snake[i][0] == snake[i - 1][0] &&
                   snake[i][1] == snake[i - 1][1] + 1))) {
        //拐弯右下
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/br_corner.png").arg(img_path)).scaled(20, 20));
      } else if (((snake[i][0] == snake[i - 1][0] - 1 &&
                   snake[i][1] == snake[i - 1][1]) &&
                  (snake[i][0] == snake[i + 1][0] &&
                   snake[i][1] == snake[i + 1][1] - 1)) ||
                 ((snake[i][0] == snake[i + 1][0] - 1 &&
                   snake[i][1] == snake[i + 1][1]) &&
                  (snake[i][0] == snake[i - 1][0] &&
                   snake[i][1] == snake[i - 1][1] - 1))) {
        //拐弯左上
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/tl_corner.png").arg(img_path)).scaled(20, 20));
      } else if (((snake[i][0] == snake[i - 1][0] - 1 &&
                   snake[i][1] == snake[i - 1][1]) &&
                  (snake[i][0] == snake[i + 1][0] &&
                   snake[i][1] == snake[i + 1][1] + 1)) ||
                 ((snake[i][0] == snake[i + 1][0] - 1 &&
                   snake[i][1] == snake[i + 1][1]) &&
                  (snake[i][0] == snake[i - 1][0] &&
                   snake[i][1] == snake[i - 1][1] + 1))) {
        //拐弯左下
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/bl_corner.png").arg(img_path)).scaled(20, 20));
      } else if (snake[i][0] == snake[i - 1][0] &&
                 snake[i][0] == snake[i + 1][0]) {
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/v_body.png").arg(img_path)).scaled(20, 20));
      } else {
        painter.drawImage(
            snake[i][0] * 20, snake[i][1] * 20,
            QImage(tr("%1/h_body.png").arg(img_path)).scaled(20, 20));
      }
    }
  }
}
void GameWidget::startButtonSlot() {
  static int i = 0;
  if (i % 2 == 0) {
    timer->start();
    startButton->setText(tr("暂停"));
  } else {
    timer->stop();
    startButton->setText(tr("开始"));
  }
  i++;
}

void GameWidget::timeoutSlot() {
  this->update(); // paintEvent;
  if (foodx == snake[0][0] && foody == snake[0][1]) {
    foodcount++;
    srand(time(NULL));
    foodx = rand() % COL;
    foody = rand() % ROW;
    int i = 0;
    while (i <= foodcount) {
      if (foodx == snake[i][0] && foody == snake[i][1]) {
        srand(time(NULL));
        foodx = rand() % COL;
        foody = rand() % ROW;
        i = 0;
      }
      i++;
    }
    score++;
    scoreStr = QString::number(score);
    scoreShow->setText(scoreStr);
    switch (score / 10) {
    case 1:
      level = 1;
      break;
    case 2:
      level = 2;
      break;
    case 5:
      level = 3;
      break;
    default:
      break;
    }
    levelStr = QString::number(level);
    levelShow->setText(levelStr);
  }

  //蛇运动
  for (int i = foodcount; i > 0; --i) {
    snake[i][0] = snake[i - 1][0];
    snake[i][1] = snake[i - 1][1];
  }
  switch (direction) {
  case DIRECTION_UP:
    --snake[0][1];
    break;
  case DIRECTION_DOWN:
    ++snake[0][1];
    break;
  case DIRECTION_LEFT:
    --snake[0][0];
    break;
  case DIRECTION_RIGHT:
    ++snake[0][0];
    break;
  default:
    break;
  }
  // TODO:1.蛇是否碰到蛇身
  for (int i = 1; i < foodcount; i++) {
    if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
      if (QMessageBox::question(this, QString("退出游戏"),
                                QString("是否重新开始"), QMessageBox::Yes,
                                QMessageBox::No) == QMessageBox::Yes) {
        gameAgain();
      } else {
        delete this;
      }
    }
  }

  // TODO:2.蛇是否碰到边界
  if (snake[0][0] < 0 || snake[0][0] >= COL || snake[0][1] < 0 ||
      snake[0][1] >= ROW) {
    if (QMessageBox::question(this, QString("退出游戏"),
                              QString("是否重新开始"), QMessageBox::Yes,
                              QMessageBox::No) == QMessageBox::Yes) {
      gameAgain();
    } else {
      delete this;
    }
  }

  this->update(); // paintEvent;
}
void GameWidget::onUpSlot() {
  if (direction == DIRECTION_DOWN) {
    return;
  } else {
    direction = DIRECTION_UP;
  }
}
void GameWidget::onDownSlot() {
  if (direction == DIRECTION_UP) {
    return;
  } else {
    direction = DIRECTION_DOWN;
  }
}
void GameWidget::onLeftSlot() {
  if (direction == DIRECTION_RIGHT) {
    return;
  } else {
    direction = DIRECTION_LEFT;
  }
}
void GameWidget::onRightSlot() {
  if (direction == DIRECTION_LEFT) {
    return;
  } else {
    direction = DIRECTION_RIGHT;
  }
}
bool GameWidget::eatApple() {
  if (snake[0][0] == foodx && snake[0][1] == foody) {
    return true;
  }
  return false;
}

void GameWidget::keyPressEvent(QKeyEvent *k) {
  int key = k->key();
  switch (key) {
  case Qt::Key_A:
    emit leftSignal();
    break;
  case Qt::Key_D:
    emit rightSignal();
    break;
  case Qt::Key_W:
    emit upSignal();
    break;
  case Qt::Key_S:
    emit downSignal();
    break;
  default:
    break;
  }
}

void GameWidget::gameAgain() {
  level = 0;
  score = 0;
  scoreStr = QString::number(score);
  levelStr = QString::number(level);
  scoreShow->setText(scoreStr);
  levelShow->setText(levelStr);
  foodcount = 0;
  //产生蛇头和食物的位置
  srand(time(NULL));
  foodx = rand() % COL;
  foody = rand() % ROW;
  snake[0][0] = rand() % COL;
  snake[0][1] = rand() % ROW;
  while (1) {
    if (foodx == snake[0][0] && foody == snake[0][1]) {
      snake[0][0] = rand() % COL;
      snake[0][1] = rand() % ROW;
    } else {
      break;
    }
  }
  direction = rand() % DIRECTION_NR;
}
