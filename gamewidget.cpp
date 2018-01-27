#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    hero = new Hero(this);
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(100, 100, *(hero->image));
}
