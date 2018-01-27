#include "gameobject.h"

GameObject::GameObject(QObject *parent) : QObject(parent)
{

}

void GameObject::setHealth(int health) { this->health = health; }
void GameObject::setLetter(char letter) { this->letter = letter; }

void GameObject::rotate(float angle)
{
    QPoint center = image->rect().center();
    QMatrix matrix;
    matrix.translate(center.x(), center.y());
    matrix.rotate(90);
    *image = image->transformed(matrix);
}
