#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager net;
    QSqlDatabase db;

    return a.exec();
}
