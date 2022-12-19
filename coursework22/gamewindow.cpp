#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    helpAction = ui->menuBar->addAction("Справка");
    connect(helpAction,SIGNAL(triggered()),this,SLOT(slot_helpAction()));

    scene = new QGraphicsScene();
    ui->gameGraphicsView->setScene(scene);

    scene->setSceneRect(0,0,385,501);

    background = new GameItem(-1);
    scene->addItem(background);
    connect(background,SIGNAL(signalClicked(int)),this,SLOT(slotCheck(int)));

    for (int i = 0; i < 15; i++)
    {
        item[i] = new GameItem(i);
        scene->addItem(item[i]);
        connect(item[i],SIGNAL(signalClicked(int)),this,SLOT(slotItemClicked(int)));
    }

    selected = -1;
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_menuButton_clicked()
{
    timer->stop();
    emit menuWindow();
    this->close();
}

void GameWindow::on_endButton_clicked()
{
    score = saved_time * (1 + life);
    timer->stop();
    emit endGameWindow(score);
    this->close();
}

void GameWindow::slot_helpAction()
{
    emit helpWindow();
}

void GameWindow::slotItemClicked(int num)
{
    selected = num;
}

void GameWindow::slotCheck(int)
{
        if (selected == item_order[current_item])
        {
            saved_time += current_time;
            changeScore();
            increaseCurrentItem();
        }
        else
        {
            decreaseLife();
            changeScore();
        }
        selected = -1;
}

void GameWindow::fillItemOrder(int item_order[])
{
    bool used[15];
    for (int i = 0; i < 15; i++) used[i] = false;

    int remaining = 15;
    for (int i = 0; i < 15; i++)
    {
        int number = rand() % remaining;
        int item_num = 0;
        while(number > 0 || used[item_num])
        {
            if (!used[item_num]) number--;
            item_num++;
        }
        item_order[i] = item_num;
        used[item_num] = true;
        remaining--;
    }
}

void GameWindow::startGame()
{
    fillItemOrder(item_order);
    current_item = 0;

    selected = -1;

    life = 3;
    saved_time = 0;
    current_time = 9000;

    score = 0;

    updateLife();
    updateCurrentItem();
    changeScore();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &GameWindow::gameProcess);
    timer->start(10);
}

void GameWindow::gameProcess()
{
    current_time--;
    changeTime();
    if (current_time == 0)
    {
        decreaseLife();
        changeScore();
    }
}

void GameWindow::gameOver()
{
    score = saved_time * (1 + life);
    timer->stop();
    emit endGameWindow(score);
    this->close();
}

void GameWindow::increaseCurrentItem()
{
    if (current_item + 1 < 15)
    {
        current_item++;
        updateCurrentItem();
        current_time = 9000;
    }
    else gameOver();
}

void GameWindow::updateCurrentItem()
{
    QPixmap *itemimage = new QPixmap(QString(":/images/items_show/item%1.png").arg(item_order[current_item]));
    ui->itemLabel->setPixmap(*itemimage);
    ui->itemLineEdit->setText(QString("%1/15").arg(current_item + 1));
}

void GameWindow::decreaseLife()
{
    life--;
    updateLife();
    if (life <= 0) gameOver();
    increaseCurrentItem();
    current_time = 9000;
}

void GameWindow::updateLife()
{
    switch(life)
    {
        case 3:
            ui->lifeLabel_1->show();
            ui->lifeLabel_2->show();
            ui->lifeLabel_3->show();
        break;
        case 2:
            ui->lifeLabel_3->hide();
        break;
        case 1:
            ui->lifeLabel_2->hide();
        break;
        case 0:
            ui->lifeLabel_1->hide();
        break;
    }
}

void GameWindow::changeScore()
{
    score = saved_time * (1 + life);
    ui->scoreLineEdit->setText(QString("%1").arg(score));
}

void GameWindow::changeTime()
{
    ui->timeLineEdit->setText(QString("%1").arg(ceil((double)current_time / 100)));
}
