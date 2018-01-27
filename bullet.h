#ifndef BULLET_H
#define BULLET_H

#include <QObject>

class bullet : public QObject
{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BULLET_H