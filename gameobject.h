#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QPointF>
#include <QTransform>
#include <QtMath>

class GameObject : public QObject
{
    Q_OBJECT
public:
    explicit GameObject(QObject *parent = nullptr);

    QImage *image;
    float angle;
    float speed;
    QPointF position;
    QRectF *bounds;
    bool isActive = true;

    int health = 1;
    char letter;
    void setHealth(int health);
    void setLetter(char letter);
    void setPosition(QPointF position);
    QPointF getDrawablePosition();
    QPointF getDrawableDelta();

    static char getRandomChar();
protected:
    void updateBounds();

signals:

public slots:
};

#endif // GAMEOBJECT_H
