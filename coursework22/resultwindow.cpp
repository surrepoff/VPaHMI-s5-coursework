#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);

    helpAction = ui->menuBar->addAction("Справка");
    connect(helpAction,SIGNAL(triggered()),this,SLOT(slot_helpAction()));

    UpdateTable();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_menuButton_clicked()
{
    emit menuWindow();
    this->close();
}

void ResultWindow::slot_helpAction()
{
    emit helpWindow();
}

void ResultWindow::slot_addRecord(QString username, int score)
{
    databaseResult.addRecord(username, score);
    UpdateTable();
}

void ResultWindow::UpdateTable()
{
    ui->tableWidget->setRowCount(0);
    auto records = databaseResult.getRecords();
    for(int i = 0; i < records.size(); i++) {
        ui->tableWidget->insertRow(i);
        for(int j = 0; j < records[i].size(); j++) {
            qDebug() << records[i][j];
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(records[i][j]));
        }
    }
}
