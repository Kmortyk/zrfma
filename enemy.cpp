#include "enemy.h"
#include <QDebug>

enemy::enemy(char letter, QObject *parent) : GameObject(parent)
{
    this->letter = letter;
    image = new QImage(":/img/ZRFM_ENEMY.png");
}

void enemy::setTarget(GameObject *target) { this->target = target; }

void enemy::hit(char letter)
{
    if(this->letter == letter){ isActive = false; }
}

void enemy::update()
{
    if(target != nullptr)
    {
       QPointF t_position = target->position;
       QPointF delta = t_position - position;

       position += delta * speed;
       angle = qAtan2((double) delta.y(), (double) delta.x()) * (180.0 / 3.14);
       updateBounds();
    }
}

