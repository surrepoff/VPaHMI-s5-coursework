#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <gameitem.h>

class GameGraphics : public QGraphicsScene
{
public:
    GameGraphics();
    void Init();

private:
    QGraphicsPixmapItem* background;
    GameItem* item[15];
};
#endif // GAMEGRAPHICS_H
