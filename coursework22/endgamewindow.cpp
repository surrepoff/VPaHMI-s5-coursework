#include "endgamewindow.h"
#include "ui_endgamewindow.h"

EndGameWindow::EndGameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndGameWindow)
{
    ui->setupUi(this);

    helpAction = ui->menuBar->addAction("Справка");
    connect(helpAction,SIGNAL(triggered()),this,SLOT(slot_helpAction()));

    checkbox_state = false;
    ui->nameLabel->hide();
    ui->nameLineEdit->hide();

    connect(ui->checkBox,SIGNAL(clicked(bool)), this, SLOT(changeCheckBox(bool)));
    connect(ui->nameLineEdit,SIGNAL(textChanged(QString)),this, SLOT(changeNickname(QString)));
}

EndGameWindow::~EndGameWindow()
{
    delete ui;
}

void EndGameWindow::on_continueButton_clicked()
{
    if (checkbox_state && username == "")
    {
        QMessageBox::information(this,"Ошибка",QString("Чтобы добавить результат в таблицу необходимо ввести имя."));
    }
    else
    {
        if (checkbox_state) emit signal_addResult(username,score);
        emit menuWindow();
        this->close();
    }
}

void EndGameWindow::slot_helpAction()
{
    emit helpWindow();
}

void EndGameWindow::setScore(int value)
{
    score = value;
    ui->scoreLineEdit->setText(QString("%1").arg(score));
}

void EndGameWindow::changeCheckBox(bool value)
{
    checkbox_state = value;
    if (checkbox_state)
    {
        ui->nameLabel->show();
        ui->nameLineEdit->show();
    }
    else
    {
        ui->nameLabel->hide();
        ui->nameLineEdit->hide();
    }
}

void EndGameWindow::changeNickname(QString value)
{
    username = value;
    //QMessageBox::information(this,"Nick",QString("Никнейм = %1").arg(username));
}
