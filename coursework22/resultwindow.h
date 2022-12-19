#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <databaseresult.h>

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = 0);
    ~ResultWindow();

public slots:
    void slot_addRecord(QString username, int score);

signals:
    void menuWindow();
    void helpWindow();

private:
    Ui::ResultWindow *ui;
    QAction *helpAction;
    void UpdateTable();
    DatabaseResult databaseResult = DatabaseResult(DEFAULT_DATABASE_PATH);

private slots:
    void on_menuButton_clicked();
    void slot_helpAction();
};

#endif // RESULTWINDOW_H
