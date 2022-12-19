#ifndef DATABASERESULT_H
#define DATABASERESULT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>


#define DEFAULT_DATABASE_PATH "D:/QT.PROJECTS/coursework22/results.db"

class DatabaseResult
{
public:
    DatabaseResult(const QString &path);
    void addRecord(const QString username, const int score);
    QList<QList<QString>>  getRecords();
private:
    QSqlDatabase database;
};

#endif // DATABASERESULT_H
