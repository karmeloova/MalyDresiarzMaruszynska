#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);

    QList<QTcpSocket *> clients;

    int winners = 0;
    int winnerScore = 0;
    QString winner = "None";

    int currentClientTour = 0;
    int roundCounter = 0;
    int roundsToPlay = 10;

    void PassToken();
    void NextPlayer();
    void EndGame();

    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyToRead();
    void onClientDisconnected();

};

#endif
