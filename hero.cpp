#include "hero.h"

Hero::Hero(QObject *parent) : GameObject(parent)
{
    image = new QImage("resources/img/ZRFM_HERO.png");
}

void Hero::hit()
{
    health -= 10;
}
