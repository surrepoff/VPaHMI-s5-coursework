#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class GameItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GameItem(int num, QObject *parent = 0);
    ~GameItem();

signals:
    void signalClicked(int itemnum);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *itemimage;
    int x, y;
    int w, h;
    int itemnum;
};

#endif // GAMEITEM_H
