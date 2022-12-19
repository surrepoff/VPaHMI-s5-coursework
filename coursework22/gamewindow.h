#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <endgamewindow.h>
#include <gameitem.h>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void startGame();

signals:
    void menuWindow();
    void endGameWindow(int score);
    void helpWindow();

private:
    Ui::GameWindow *ui;
    QAction *helpAction;
    QGraphicsScene *scene;
    GameItem* background;
    GameItem* item[15];
    QTimer *timer;
    int selected;
    int life;
    int saved_time;
    int current_time;
    int item_order[15];
    int current_item;
    int score;
    void fillItemOrder(int item_order[]);
    void gameOver();
    void increaseCurrentItem();
    void updateCurrentItem();
    void decreaseLife();
    void updateLife();
    void changeScore();
    void changeTime();

private slots:
    void on_menuButton_clicked();
    void on_endButton_clicked();
    void slot_helpAction();
    void slotItemClicked(int num);
    void slotCheck(int);
    void gameProcess();

};

#endif // GAMEWINDOW_H
