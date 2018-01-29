#include "gameobject.h"

GameObject::GameObject(QObject *parent) : QObject(parent)
{
    bounds = new QRectF();
}

void GameObject::setHealth(int health) { this->health = health; }
void GameObject::setLetter(char letter) { this->letter = letter; }

void GameObject::setPosition(QPointF position)
{
    this->position = position;
    updateBounds();
}

QPointF GameObject::getDrawablePosition()
{
    return position - image->rect().center();
}

QPointF GameObject::getDrawableDelta()
{
    return -image->rect().center();
}

void GameObject::updateBounds()
{
    float w = image->width() / 2;
    float h = image->height() / 2;
    bounds->setRect(position.x() - w/2, position.y() - h/2, w, h);
}

char GameObject::getRandomChar()
{
    int diff = 'Z'-'A';
    return 'A'+(rand() % diff);
}
