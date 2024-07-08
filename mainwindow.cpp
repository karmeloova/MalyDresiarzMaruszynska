#include "mainwindow.h"
#include "ui_mainwindow.h"

// Konstruktor MainWindow, inicjalizuje interfejs użytkownika i ustawia początkowe stany widgetów
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ustawienie widoczności poszczególnych widgetów
    ui->PlayerCreationWidget->setVisible(true);
    ui->GameResultWidget->setVisible(false);
    ui->GameplayWidget->setVisible(false);
    ui->PlayerWaitingForGame->setVisible(false);
    ui->endCreationButton->setDisabled(true); // Dezaktywacja przycisku zakończenia tworzenia graczy
}

// Destruktor MainWindow, usuwa interfejs użytkownika
MainWindow::~MainWindow()
{
    delete ui;
}

// Metoda obsługująca kliknięcie przycisku Lans
void MainWindow::on_LansButton_clicked()
{
    if(canMove == false) return; // Sprawdzenie, czy ruch jest dozwolony
    players.at(currentPlayer)->Lans(); // Wykonanie ruchu Lans
    EndPlayerMove(); // Zakończenie ruchu gracza
}

// Metoda obsługująca kliknięcie przycisku Robota
void MainWindow::on_RobotaButton_clicked()
{
    if(canMove == false) return; // Sprawdzenie, czy ruch jest dozwolony
    players.at(currentPlayer)->DoRoboty(); // Wykonanie ruchu Robota
    EndPlayerMove(); // Zakończenie ruchu gracza
}

// Metoda obsługująca kliknięcie przycisku Haracz
void MainWindow::on_HaraczButton_clicked()
{
    if(canMove == false) return; // Sprawdzenie, czy ruch jest dozwolony
    players.at(currentPlayer)->Haracz(); // Wykonanie ruchu Haracz
    EndPlayerMove(); // Zakończenie ruchu gracza
}

// Metoda obsługująca kliknięcie przycisku BMW
void MainWindow::on_BMWButton_clicked()
{
    if(canMove == false) return; // Sprawdzenie, czy ruch jest dozwolony
    players.at(currentPlayer)->BMW(); // Wykonanie ruchu BMW
    EndPlayerMove(); // Zakończenie ruchu gracza
}

// Metoda obsługująca kliknięcie przycisku Ivan
void MainWindow::on_IvanButton_clicked()
{
    if(canMove == false) return; // Sprawdzenie, czy ruch jest dozwolony
    client.sendMessage(QString("ivan")); // Wysłanie wiadomości "ivan" do serwera
}

// Metoda odświeżająca interfejs użytkownika
void MainWindow::onRefreshInterface()
{
    ui->PlayerWaitingForGame->setVisible(false);
    ui->GameplayWidget->setVisible(true);

    if(client.hasToken)
    {
        Player* curPlayer = players.at(currentPlayer);

        if(curPlayer == nullptr) return;

        // Ustawienie stanu przycisków na podstawie stanu gracza
        ui->HaraczButton->setEnabled(curPlayer->kasa >= 4);
        ui->BMWButton->setEnabled(true);
        ui->IvanButton->setEnabled(true);
        ui->LansButton->setEnabled(true);
        ui->RobotaButton->setEnabled(true);

        // Aktualizacja etykiet z informacjami o graczu
        ui->PlayerLabel->setText(QString::fromStdString(curPlayer->playerNick));
        ui->SzacunLabel->setText(QString::number(curPlayer->szacun));
        ui->KasaLabel->setText(QString::number(curPlayer->kasa));
        ui->BMWLabel->setText(QString::number(curPlayer->bmw));
        ui->HaraczLabel->setText(QString::number(curPlayer->haracz));

        if(curPlayer->isAI)
        {
            curPlayer->AIMakeRandomMove(); // Wykonanie losowego ruchu przez AI
            EndPlayerMove(); // Zakończenie ruchu gracza
        }
        canMove = true;
    }
    else
    {
        // Dezaktywacja przycisków, gdy ruch nie jest dozwolony
        ui->HaraczButton->setEnabled(false);
        ui->BMWButton->setEnabled(false);
        ui->IvanButton->setEnabled(false);
        ui->LansButton->setEnabled(false);
        ui->RobotaButton->setEnabled(false);

        // Ustawienie etykiet dla zdalnego gracza
        ui->PlayerLabel->setText(QString::fromStdString("Remote player"));
        ui->SzacunLabel->setText(QString::number(0));
        ui->KasaLabel->setText(QString::number(0));
        ui->BMWLabel->setText(QString::number(0));
        ui->HaraczLabel->setText(QString::number(0));
    }
}

// Metoda kończąca ruch gracza
void MainWindow::EndPlayerMove()
{
    currentPlayer++;
    canMove = false;

    if(currentPlayer >= players.size())
    {
        currentPlayer = 0;
        client.sendMessage("pass"); // Wysłanie wiadomości "pass" do serwera
    }
    else
    {
        std::string s = "current|" + players.at(currentPlayer)->playerNick;
        client.sendMessage(QString::fromStdString(s)); // Wysłanie wiadomości z informacją o bieżącym graczu
    }
}

// Metoda obsługująca akcję Ivana
void MainWindow::onIwan()
{
    if(client.hasToken == false)
    {
        for(int i = 0; i < players.size(); i++)
        {
            players.at(i)->Iwan(); // Wykonanie akcji Ivana dla każdego gracza
        }
    }
    else
    {
        for(int i = 0; i < players.size(); i++)
        {
            if(i != currentPlayer) players.at(i)->Iwan(); // Wykonanie akcji Ivana dla innych graczy niż bieżący
        }
        EndPlayerMove(); // Zakończenie ruchu gracza
    }
}

// Metoda obsługująca zakończenie gry i wyświetlenie wyniku
void MainWindow::onEndGame(std::string result)
{
    qDebug() << result;
    ui->GameResultWidget->setVisible(true);
    ui->GameplayWidget->setVisible(false);

    result = "Wygrana: \n" + result;
    ui->ResultLabel->setText(QString::fromStdString(result)); // Wyświetlenie wyniku gry
}

// Metoda obsługująca kliknięcie przycisku dodania gracza
void MainWindow::on_addPlayerButton_clicked()
{
    std::string newName = ui->PlayerNameEdit->text().toStdString();
    bool isRobot = ui->isRobotCheckbox->isChecked();

    players.push_back(new Player(newName, isRobot)); // Dodanie nowego gracza do listy

    ui->PlayerNameEdit->setText("Nazwa gracza");
    ui->endCreationButton->setDisabled(false); // Aktywacja przycisku zakończenia tworzenia graczy
}

// Metoda obsługująca kliknięcie przycisku zakończenia tworzenia graczy
void MainWindow::on_endCreationButton_clicked()
{
    // Ustawienie widoczności widgetów
    ui->PlayerCreationWidget->setVisible(false);
    ui->GameResultWidget->setVisible(false);
    ui->GameplayWidget->setVisible(false);
    ui->PlayerWaitingForGame->setVisible(true);

    bool isHost = ui->isHostCheckbox->isChecked();
    QString ip = ui->ServerIP->text();

    if(isHost)
    {
        server.startServer(); // Uruchomienie serwera, jeśli użytkownik jest hostem
        ui->WaitingLabel->setText(QString("Rozpocznij grę!"));
    }
    else
    {
        ui->StartGameButton->setVisible(false); // Ukrycie przycisku rozpoczęcia gry, jeśli użytkownik nie jest hostem
        ui->WaitingLabel->setText(QString("Oczekiwanie na hosta!"));
    }

    client.setPlayerListReference(&players);
    client.connectToServer(ip, 1234); // Połączenie klienta z serwerem

    // Połączenie sygnałów klienta z odpowiednimi metodami
    connect(&client, &Client::refreshInterfaceSignal, this, &MainWindow::onRefreshInterface);
    connect(&client, &Client::endGameSignal, this, &MainWindow::onEndGame);
    connect(&client, &Client::iwanActionSignal, this, &MainWindow::onIwan);
    connect(&client, &Client::newRoundSignal, this, &MainWindow::onNewRound);
}

// Metoda obsługująca kliknięcie przycisku rozpoczęcia gry
void MainWindow::on_StartGameButton_clicked()
{
    // Ustawienie widoczności widgetów
    ui->PlayerCreationWidget->setVisible(false);
    ui->GameResultWidget->setVisible(false);
    ui->GameplayWidget->setVisible(true);
    ui->PlayerWaitingForGame->setVisible(false);

    client.sendMessage(QString("startGame")); // Wysłanie wiadomości "startGame" do serwera
}

// Metoda obsługująca rozpoczęcie nowej rundy
void MainWindow::onNewRound()
{
    for(int i = 0; i < players.size(); i++)
    {
        players.at(i)->OnRoundStart(); // Rozpoczęcie nowej rundy dla każdego gracza
    }
}

// Metoda obsługująca zmianę stanu checkboxa isHost
void MainWindow::on_isHostCheckbox_stateChanged(int arg1)
{
    ui->ServerIP->setDisabled(arg1 != 0); // Dezaktywacja pola ServerIP, jeśli użytkownik jest hostem
}
