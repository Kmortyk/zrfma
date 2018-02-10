#include "gamewidget.h"
#include <QDebug>
#include <QtMath>
#include <QChar>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    hero = new Hero(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(10);

    setMouseTracking(true);

    qsrand(0);
}

void GameWidget::updateGame()
{
    time += 10;

    for(QList<bullet *>::iterator it = bulletsList.begin(); it != bulletsList.end();) {
        (*it)->update();
        if(!(*it)->isActive){ it = bulletsList.erase(it); }
        else { ++it; }
    }

    for(QList<enemy *>::iterator it = enemiesList.begin(); it != enemiesList.end();) {
        (*it)->update();
        if(!(*it)->isActive){ it = enemiesList.erase(it); }
        else { ++it; }
    }

    if(time > 3000){
        addEnemy(GameObject::getRandomChar(), QPointF(qrand()%400 - 200,qrand()%400 - 200));
        time = 0;
    }

    updateCollision();
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pos = (event->pos() - rect().center()) - hero->position;
    float angle = qAtan2((double) pos.y(), (double) pos.x()) * (180.0 / 3.14);
    hero->angle = angle;
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{
    bullet *b = new bullet(hero->letter, this);
    b->setPosition(QPointF(0,0));
    b->angle = hero->angle;
    b->speed = 1;

    bulletsList.push_back(b);
}

void GameWidget::updateCollision()
{
    for(auto i = enemiesList.begin(); i != enemiesList.end(); ++i)
    {
        for(auto j = bulletsList.begin(); j != bulletsList.end(); ++j)
        {
            QRectF bullet_bounds = *((*j)->bounds);
            if((*i)->bounds->contains(bullet_bounds))
            {
                (*i)->hit((*j)->letter);
                (*j)->isActive = false;
            }
        }

        if(hero->bounds->contains(*((*i)->bounds)))
        {
            timer->stop();
        }
    }

}

void GameWidget::paintEvent(QPaintEvent *event)
{
    drawBullets();
    drawEnemies();
    drawHero();
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    QString text = event->text();
    if(text.length() > 0) hero->letter = (char) text.at(0).toUpper().toLatin1();
}

void GameWidget::drawHero()
{
    QPainter painter(this);
    painter.translate(width()/2, height()/2);
    painter.save();
    painter.rotate(hero->angle);
    painter.drawImage(hero->getDrawablePosition(), *(hero->image));
    painter.restore();
    drawLetter(painter, hero, QPointF(0, 0));
}

void GameWidget::drawBullets()
{
    QPainter painter(this);
    painter.translate(width()/2, height()/2);
    for(QList<bullet *>::iterator it = bulletsList.begin(); it != bulletsList.end(); ++it)
    {
        painter.drawImage((*it)->getDrawablePosition(), *((*it)->image));
    }
}

void GameWidget::drawEnemies()
{
    QPainter painter(this);
    painter.translate(width()/2, height()/2);

    for(QList<enemy *>::iterator it = enemiesList.begin(); it != enemiesList.end(); ++it)
    {
        painter.save();
        painter.translate((*it)->position);
        painter.rotate((*it)->angle);
        painter.drawImage((*it)->getDrawableDelta(), *((*it)->image));
        painter.restore();
        drawLetter(painter, *it, (*it)->bounds->bottomLeft());
    }
}

void GameWidget::drawLetter(QPainter &painter, GameObject *o, QPointF point)
{
    QPainterPath path;
    path.addText(point, QFont("Times", 11, QFont::Bold), QString(o->letter));
    painter.setPen(Qt::black);
    painter.setBrush(Qt::cyan);
    painter.drawPath(path);
}

void GameWidget::addEnemy(const char &letter, const QPointF &position)
{
    enemy *e = new enemy(letter, this);
    e->setPosition(position);
    e->setTarget(hero);
    e->speed = 0.001;

    enemiesList.push_back(e);
}
