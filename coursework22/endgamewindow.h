#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QMainWindow>

#include <QMessageBox>

namespace Ui {
class EndGameWindow;
}

class EndGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndGameWindow(QWidget *parent = 0);
    ~EndGameWindow();
    void setScore(int value);

signals:
    void menuWindow();
    void helpWindow();
    void signal_addResult(QString str, int value);

private:
    Ui::EndGameWindow *ui;
    QAction *helpAction;
    int score;
    int checkbox_state;
    QString username;

private slots:
    void on_continueButton_clicked();
    void slot_helpAction();
    void changeCheckBox(bool value);
    void changeNickname(QString value);
};

#endif // ENDGAMEWINDOW_H
