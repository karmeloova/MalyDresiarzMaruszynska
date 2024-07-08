#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "player.h"

class Client: public QObject
{
    Q_OBJECT

public:
    Client(QObject *parent = nullptr);
    // Funkcja do dołączania do serwera hosta
    void connectToServer(const QString &host, quint16 port);
    // Funkcja
    void sendMessage(const QString &message);
    void setPlayerListReference(std::vector<Player*> *p);

    bool hasToken = false;

signals:
    void iwanActionSignal();
    void refreshInterfaceSignal();
    void newRoundSignal();
    void endGameSignal(string result);

private slots:
    void onReadyToRead();

private:
    QTcpSocket *socket;
    std::vector<Player*> *players;

};

#endif
