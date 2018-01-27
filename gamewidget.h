#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QList>
#include <QPainter>
#include "hero.h"
#include "enemy.h"
#include "bullet.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void drawHero();
    void drawBullets();
    void drawEnemies();
    void drawLetter(QPainter &painter, GameObject *o, QPointF point);

private:
    Hero *hero;
    QList<enemy *> enemiesList;
    QList<bullet *> bulletsList;

    void updateCollision();
    void addEnemy(const char &letter, const QPointF &position, const float &angle = 0);

signals:

public slots:
    void updateGame();
};

#endif // GAMEWIDGET_H
