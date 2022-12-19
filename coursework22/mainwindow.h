#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewindow.h>
#include <endgamewindow.h>
#include <resultwindow.h>
#include <helpwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameWindow *gameWindow;
    EndGameWindow *endGameWindow;
    ResultWindow *resultWindow;
    HelpWindow *helpWindow;
    QAction *helpAction;

private slots:
    void on_startButton_clicked();
    void on_resultButton_clicked();
};

#endif // MAINWINDOW_H
