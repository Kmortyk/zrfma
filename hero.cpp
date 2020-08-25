#include "hero.h"

Hero::Hero(QObject *parent) : GameObject(parent)
{
    image = new QImage(":/img/ZRFM_HERO.png");
    setPosition(QPointF(0,0));
    letter = 'A';
}

void Hero::hit()
{
    health -= 10;
}
