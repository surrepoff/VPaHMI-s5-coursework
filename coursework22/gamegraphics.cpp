#include "gamegraphics.h"

void GameGraphics::Init()
{
    /*
    QPixmap newImage;

    if (!newImage.load(QStringLiteral(":/images/background.jpg")))
    {
            return;
    }

    background = addPixmap(newImage);
    background->setPos(0,0);
    background->setData(0, "background");
    background->setFlags(QGraphicsItem::ItemIsMovable);
    */

    item[0] = new GameItem();

    /*
    if (!newImage.load(QStringLiteral(":/images/items/item_car_show.png")))
    {
            return;
    }

    item[0] = addPixmap(newImage);
    item[0]->setPos(0,0);
    item[0]->setData(0, "car");
    item[0]->setFlags(QGraphicsItem::ItemIsMovable);
    */
}

GameGraphics::GameGraphics()
{
    Init();
}
