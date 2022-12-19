#include "gameitem.h"


GameItem::GameItem(int num, QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    itemnum = num;
    switch (num)
    {
        case -1:
            itemimage = new QPixmap(":/images/background.jpg");
            x = 0; y = 0; w = 386; h = 502;
        break;

        case 0:
            itemimage = new QPixmap(":/images/items/item0.jpg");
            x = 244; y = 23; w = 42; h = 30;
        break;

        case 1:
            itemimage = new QPixmap(":/images/items/item1.jpg");
            x = 62; y = 118; w = 23; h = 16;
        break;

        case 2:
            itemimage = new QPixmap(":/images/items/item2.jpg");
            x = 155; y = 94; w = 16; h = 20;
        break;

        case 3:
            itemimage = new QPixmap(":/images/items/item3.jpg");
            x = 200; y = 119; w = 36; h = 42;
        break;

        case 4:
            itemimage = new QPixmap(":/images/items/item4.jpg");
            x = 338; y = 112; w = 27; h = 36;
        break;

        case 5:
            itemimage = new QPixmap(":/images/items/item5.jpg");
            x = 14; y = 206; w = 17; h = 17;
        break;

        case 6:
            itemimage = new QPixmap(":/images/items/item6.jpg");
            x = 99; y = 207; w = 21; h = 13;
        break;

        case 7:
            itemimage = new QPixmap(":/images/items/item7.jpg");
            x = 329; y = 231; w = 23; h = 23;
        break;

        case 8:
            itemimage = new QPixmap(":/images/items/item8.jpg");
            x = 76; y = 263; w = 41; h = 54;
        break;

        case 9:
            itemimage = new QPixmap(":/images/items/item9.jpg");
            x = 189; y = 296; w = 31; h = 32;
        break;

        case 10:
            itemimage = new QPixmap(":/images/items/item10.jpg");
            x = 54; y = 354; w = 36; h = 30;
        break;

        case 11:
            itemimage = new QPixmap(":/images/items/item11.jpg");
            x = 170; y = 376; w = 24; h = 45;
        break;

        case 12:
            itemimage = new QPixmap(":/images/items/item12.jpg");
            x = 297; y = 401; w = 40; h = 39;
        break;

        case 13:
            itemimage = new QPixmap(":/images/items/item13.jpg");
            x = 88; y = 417; w = 34; h = 29;
        break;

        case 14:
            itemimage = new QPixmap(":/images/items/item14.jpg");
            x = 167; y = 457; w = 39; h = 45;
        break;
    }
}

GameItem::~GameItem()
{

}

void GameItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalClicked(itemnum);
    QGraphicsItem::mousePressEvent(event);
}

QRectF GameItem::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void GameItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(x,y,*itemimage);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
