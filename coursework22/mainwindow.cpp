#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameWindow = new GameWindow();
    connect(gameWindow, &GameWindow::menuWindow, this, &MainWindow::show);

    endGameWindow = new EndGameWindow();
    connect(gameWindow, &GameWindow::endGameWindow, endGameWindow, &EndGameWindow::show);
    connect(gameWindow, &GameWindow::endGameWindow, endGameWindow, &EndGameWindow::setScore);

    connect(endGameWindow, &EndGameWindow::menuWindow, this, &MainWindow::show);

    resultWindow = new ResultWindow();
    connect(resultWindow, &ResultWindow::menuWindow, this, &MainWindow::show);
    connect(endGameWindow, &EndGameWindow::signal_addResult, resultWindow, &ResultWindow::slot_addRecord);

    connect(ui->exitButton,SIGNAL(clicked(bool)),SLOT(close()));

    helpAction = ui->menuBar->addAction("Справка");

    helpWindow = new HelpWindow();
    connect(helpAction, SIGNAL(triggered()), helpWindow, SLOT(show()));
    connect(gameWindow, &GameWindow::helpWindow, helpWindow, &HelpWindow::show);
    connect(endGameWindow, &EndGameWindow::helpWindow, helpWindow, &HelpWindow::show);
    connect(resultWindow, &ResultWindow::helpWindow, helpWindow, &HelpWindow::show);
    /*
    ui->startButton->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(255, 255, 255);"
                "border-radius: 15%;"
                "border: 1px solid rgb(0, 0, 0);}"
                "QPushButton:hover{"
                "background-color: rgba(229, 241, 251, 226);"
                "border: 1px solid rgba(0, 120, 215, 255);}"
                "QPushButton:pressed  {"
                "background-color: rgba(204, 228, 247, 255);"
                "border: 1px solid rgba(0, 84, 153, 255);}"
                );
    ui->resultButton->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(255, 255, 255);"
                "border-radius: 15%;"
                "border: 1px solid rgb(0, 0, 0);}"
                "QPushButton:hover{"
                "background-color: rgba(229, 241, 251, 226);"
                "border: 1px solid rgba(0, 120, 215, 255);}"
                "QPushButton:pressed  {"
                "background-color: rgba(204, 228, 247, 255);"
                "border: 1px solid rgba(0, 84, 153, 255);}"
                );
    ui->exitButton->setStyleSheet(
                "QPushButton{"
                "background-color: rgb(255, 255, 255);"
                "border-radius: 15%;"
                "border: 1px solid rgb(0, 0, 0);}"
                "QPushButton:hover{"
                "background-color: rgba(229, 241, 251, 226);"
                "border: 1px solid rgba(0, 120, 215, 255);}"
                "QPushButton:pressed  {"
                "background-color: rgba(204, 228, 247, 255);"
                "border: 1px solid rgba(0, 84, 153, 255);}"
                );
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    gameWindow->show();
    gameWindow->startGame();
    this->close();
}

void MainWindow::on_resultButton_clicked()
{
    resultWindow->show();
    this->close();
}
