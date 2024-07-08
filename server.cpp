#include "server.h"

// Konstruktor klasy Server, dziedziczący po QTcpServer
Server::Server(QObject *parent) : QTcpServer(parent)
{
}

// Metoda uruchamiająca serwer
void Server::startServer()
{
    // Próbujemy uruchomić serwer nasłuchujący na dowolnym adresie IP i porcie 1234
    if (listen(QHostAddress::Any, 1234)) {
        qDebug() << "Serwer wystartowal"; // Sukces uruchomienia serwera
    } else {
        qDebug() << "Serwer nie mogl wystartowac"; // Niepowodzenie uruchomienia serwera
    }
}

// Metoda obsługująca nowe połączenia przychodzące
void Server::incomingConnection(qintptr socketDescriptor)
{
    // Tworzenie nowego gniazda dla klienta
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);
    clients << client; // Dodanie klienta do listy klientów

    // Połączenie sygnałów gotowości do odczytu i rozłączenia z odpowiednimi metodami
    connect(client, &QTcpSocket::readyRead, this, &Server::onReadyToRead);
    connect(client, &QTcpSocket::disconnected, this, &Server::onClientDisconnected);
}

// Metoda obsługująca odczyt danych od klientów
void Server::onReadyToRead()
{
    // Pobranie klienta, który wysłał dane
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    QString data = QString::fromUtf8(client->readAll()); // Odczytanie danych

    // Podział otrzymanych danych na poszczególne wiadomości
    QStringList messages =  data.split(";");

    for(int i = 0; i < messages.count(); i++)
    {
        QStringList args =  messages[i].split("|"); // Podział wiadomości na argumenty
        if(args.length() <= 0) return;

        std::string command = args[0].toStdString(); // Pobranie komendy

        // Obsługa różnych komend
        if(command == "pass")
        {
            PassToken(); // Przekazanie tokena
        }
        else if(command == "startGame")
        {
            roundCounter = 0;
            currentClientTour = -1;
            PassToken(); // Rozpoczęcie gry i przekazanie tokena
        }
        else if(command == "current")
        {
            NextPlayer(); // Przejście do następnego gracza
        }
        else if(command == "ivan")
        {
            // Wysłanie akcji Ivana do wszystkich klientów
            for(int i = 0; i < clients.length(); i++)
            {
                clients[i]->write(QString("ivanAction").toUtf8());
            }
        }
        else if(command == "winner")
        {
            // Obsługa wyników gry
            bool parseScore = false;
            int score = args[2].toInt(&parseScore);

            if(parseScore)
            {
                winners++;
                if(score > winnerScore)
                {
                    winnerScore = score;
                    winner = args[1];
                }
                else if(score == winnerScore)
                {
                    winner += "&" + args[1];
                }
            }

            // Jeśli wszyscy klienci przesłali swoje wyniki, wyświetl zwycięzcę
            if(winners >= clients.count())
            {
                for(int i = 0; i < clients.length(); i++)
                {
                    std::string message = "showWinner|" + winner.toStdString();
                    clients[i]->write(QString::fromStdString(message).toUtf8());
                }
            }
        }
    }
}

// Metoda obsługująca rozłączenie klienta
void Server::onClientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients.removeAll(client); // Usunięcie klienta z listy klientów
    client->deleteLater(); // Zwolnienie pamięci
}

// Metoda przekazująca token do następnego gracza
void Server::PassToken()
{
    currentClientTour++;
    std::string newRound = "|0";

    // Jeśli wszyscy gracze wykonali ruch, zaczynamy nową rundę
    if(currentClientTour >= clients.length())
    {
        currentClientTour = 0;
        roundCounter++;
        newRound = "|1";
    }

    // Jeśli gra osiągnęła maksymalną liczbę rund, kończymy grę
    if(roundCounter >= roundsToPlay)
    {
        EndGame();
    }
    else
    {
        // Przekazanie tokena odpowiedniemu graczowi
        for(int i = 0; i < clients.length(); i++)
        {
            if(i == currentClientTour)
            {
                clients[i]->write(QString(("setToken|1" + newRound).c_str()).toUtf8());
            }
            else
            {
                clients[i]->write(QString(("setToken|0"+newRound).c_str()).toUtf8());
            }
        }
    }
}

// Metoda przechodząca do następnego gracza
void Server::NextPlayer()
{
    for(int i = 0; i < clients.length(); i++)
    {
        clients[i]->write(QString("startMove").toUtf8());
    }
}

// Metoda kończąca grę i zbierająca wyniki od wszystkich klientów
void Server::EndGame()
{
    winnerScore = 0;
    winner = "";
    winners = 0;

    for(int i = 0; i < clients.length(); i++)
    {
        clients[i]->write(QString("getWinner").toUtf8());
    }
}
