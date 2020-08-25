#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class bullet : public GameObject
{
    Q_OBJECT
public:
    explicit bullet(char letter, QObject *parent = nullptr);
    float maxDistance = 1000;
    void update();

signals:

public slots:
};

#endif // BULLET_H
