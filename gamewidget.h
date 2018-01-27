#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPainter>
#include "hero.h"
#include "enemy.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Hero *hero;
    QList<enemy *> enemyList;

signals:

public slots:
};

#endif // GAMEWIDGET_H
