#ifndef ENEMY_H
#define ENEMY_H

#include "gameobject.h"

class enemy : public GameObject
{
    Q_OBJECT
public:
    explicit enemy(char letter, QObject *parent = nullptr);
    void hit(char letter);

signals:

public slots:
};

#endif // ENEMY_H
