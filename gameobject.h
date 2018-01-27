#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QImage>
#include <QRect>

class GameObject : public QObject
{
    Q_OBJECT
public:
    explicit GameObject(QObject *parent = nullptr);

    QImage *image;
    QRect *bounds;

    int health = 1;
    char letter;
    void setHealth(int health);
    void setLetter(char letter);

private:
    void rotate(float angle);

signals:

public slots:
};

#endif // GAMEOBJECT_H
