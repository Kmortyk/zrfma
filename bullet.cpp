#include "bullet.h"

bullet::bullet(char letter, QObject *parent) : GameObject(parent)
{
    this->letter = letter;
    image = new QImage(":/img/ZRFM_BULLET.png");
}

void bullet::update()
{
    float ang = angle * (3.14 / 180);
    float x = speed * qCos(ang) + position.x();
    float y = speed * qSin(ang) + position.y();

    if(qAbs(x) + qAbs(y) > maxDistance) isActive = false;

    position.setX(x);
    position.setY(y);
    updateBounds();
}


