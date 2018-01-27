#include "enemy.h"

enemy::enemy(char letter, QObject *parent) : GameObject(parent)
{
    this->letter = letter;
    image = new QImage("resources/img/ZRFM_ENEMY.png");
}

void enemy::hit(char letter)
{
    if(this->letter == letter){
        delete this;
    }
}

