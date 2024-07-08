#include "client.h"
#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>

// Konstruktor klasy Client, inicjalizujący socket i łączący sygnał readyRead do metody onReadyToRead
Client::Client(QObject *parent) : QObject(parent),socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyToRead);
}

// Metoda ustawiająca wskaźnik na listę graczy
void Client::setPlayerListReference(std::vector<Player*> *p = nullptr)
{
    players = p;
}

// Metoda łącząca klienta z serwerem przy użyciu hosta i portu
void Client::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

// Metoda wysyłająca wiadomość do serwera
void Client::sendMessage(const QString &message)
{
    std::string s = message.toStdString() + ";"; // Dodanie separatora ';' do wiadomości
    QString formatedMsg = QString::fromStdString(s);

    // Sprawdzenie, czy socket jest połączony przed wysłaniem wiadomości
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(formatedMsg.toUtf8());
    }
}

// Metoda obsługująca odbieranie danych z serwera
void Client::onReadyToRead()
{
    QString data = QString::fromUtf8(socket->readAll()); // Odczytanie wszystkich danych z socketu
    QStringList command = data.split("|"); // Podzielenie danych na komendy

    // Przetwarzanie różnych typów komend
    if(command[0] == "setToken")
    {
        if(command[1] == "1") {
            hasToken = true;
        } else {
            hasToken = false;
        }
        if(command[2]=="1")
        {
            emit newRoundSignal();
        }


        emit refreshInterfaceSignal(); // Emitowanie sygnału do odświeżenia interfejsu
    }
    else if(command[0] == "startMove") {
        emit refreshInterfaceSignal(); // Emitowanie sygnału do rozpoczęcia ruchu
    }
    else if(command[0] == "ivanAction") {
        emit iwanActionSignal(); // Emitowanie sygnału do wykonania akcji Ivana
    }
    else if(command[0] == "getWinner") {
        if(players == nullptr) return; // Sprawdzenie, czy lista graczy jest zainicjalizowana

        Player* winPlayer = players->at(0); // Zakładanie, że pierwszy gracz jest zwycięzcą
        for(int i = 0; i < players->size(); i++) {
            if(players->at(i)->szacun > winPlayer->szacun) {
                winPlayer = players->at(i); // Aktualizacja zwycięzcy, jeśli obecny gracz ma większy szacun
            }
        }

        // Tworzenie wiadomości ze zwycięzcą i wysyłanie jej do serwera
        std::string message = "winner|" + winPlayer->playerNick + "|" + std::to_string(winPlayer->szacun);
        sendMessage(QString::fromStdString(message));
    }
    else if(command[0] == "showWinner") {
        emit endGameSignal(command[1].toStdString()); // Emitowanie sygnału do zakończenia gry i pokazania zwycięzcy
    }
}
