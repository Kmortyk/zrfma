#ifndef HERO_H
#define HERO_H

#include <QMouseEvent>
#include "gameobject.h"

class Hero : public GameObject
{
    Q_OBJECT
public:
    explicit Hero(QObject *parent = nullptr);
    void hit();

signals:

public slots:
};

#endif // HERO_H
