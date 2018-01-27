#include "gamewidget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWidget *gameWidget = new GameWidget();

    gameWidget->move(QApplication::desktop()->screen()->rect().center() - gameWidget->rect().center());
    gameWidget->show();

    return a.exec();
}
