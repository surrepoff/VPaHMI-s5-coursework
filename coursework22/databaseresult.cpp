#include "databaseresult.h"

DatabaseResult::DatabaseResult(const QString &path)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path);
    if (!database.open()) {
        qDebug() << "ERROR";
    } else {
        qDebug() << "WORKING!";
    }
}


void DatabaseResult::addRecord(const QString username, const int score) {
    QSqlQuery query;
    query.prepare("INSERT INTO results (username, score) VALUES (:username, :score)");
    query.bindValue(":username", username);
    query.bindValue(":score", score);
    if (query.exec()) {
        qDebug() << "WORKING!";
    } else {
        qDebug() << "NOT WORKING(";
    }
}


QList<QList<QString> > DatabaseResult::getRecords() {
    QSqlQuery query(database);
    QList<QList<QString> > records;
    if (query.exec("SELECT id, username, score FROM results ORDER BY score DESC")) {
        while(query.next()) {
            QList<QString> tmp;
            QString id = query.value(0).toString();
            QString username = query.value(1).toString();
            QString score = query.value(2).toString();
            tmp.append(id);
            tmp.append(username);
            tmp.append(score);
            records.append(tmp);
        }
    } else {
        qDebug() << "FAIL";
        qDebug() << query.lastError();
    }

    return records;

}
