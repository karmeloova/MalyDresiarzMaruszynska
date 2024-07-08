/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *GameplayWidget;
    QLabel *PlayerLabel;
    QPushButton *LansButton;
    QPushButton *RobotaButton;
    QPushButton *HaraczButton;
    QPushButton *BMWButton;
    QPushButton *IvanButton;
    QLabel *SzacunLabel;
    QLabel *KasaLabel;
    QLabel *BMLabel;
    QLabel *HaraczLabel;
    QWidget *GameResultWidget;
    QLabel *ResultLabel;
    QWidget *PlayerCreationWidget;
    QLineEdit *PlayerNameEdit;
    QCheckBox *isRobotCheckbox;
    QPushButton *addPlayerButton;
    QPushButton *endCreationButton;
    QLineEdit *ServerIP;
    QCheckBox *isHostCheckbox;
    QWidget *PlayerWaitingForGame;
    QLabel *WaitingLabel;
    QPushButton *StartGameButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        GameplayWidget = new QWidget(centralwidget);
        GameplayWidget->setObjectName("GameplayWidget");
        GameplayWidget->setGeometry(QRect(0, 10, 1024, 768));
        PlayerLabel = new QLabel(GameplayWidget);
        PlayerLabel->setObjectName("PlayerLabel");
        PlayerLabel->setGeometry(QRect(0, 0, 1024, 41));
        QFont font;
        font.setPointSize(25);
        PlayerLabel->setFont(font);
        PlayerLabel->setAlignment(Qt::AlignCenter);
        LansButton = new QPushButton(GameplayWidget);
        LansButton->setObjectName("LansButton");
        LansButton->setGeometry(QRect(270, 190, 231, 101));
        RobotaButton = new QPushButton(GameplayWidget);
        RobotaButton->setObjectName("RobotaButton");
        RobotaButton->setGeometry(QRect(510, 190, 231, 101));
        HaraczButton = new QPushButton(GameplayWidget);
        HaraczButton->setObjectName("HaraczButton");
        HaraczButton->setGeometry(QRect(270, 310, 231, 101));
        BMWButton = new QPushButton(GameplayWidget);
        BMWButton->setObjectName("BMWButton");
        BMWButton->setGeometry(QRect(510, 310, 231, 101));
        IvanButton = new QPushButton(GameplayWidget);
        IvanButton->setObjectName("IvanButton");
        IvanButton->setGeometry(QRect(410, 450, 231, 101));
        SzacunLabel = new QLabel(GameplayWidget);
        SzacunLabel->setObjectName("SzacunLabel");
        SzacunLabel->setGeometry(QRect(370, 90, 49, 16));
        SzacunLabel->setAlignment(Qt::AlignCenter);
        KasaLabel = new QLabel(GameplayWidget);
        KasaLabel->setObjectName("KasaLabel");
        KasaLabel->setGeometry(QRect(440, 90, 49, 16));
        KasaLabel->setAlignment(Qt::AlignCenter);
        BMLabel = new QLabel(GameplayWidget);
        BMLabel->setObjectName("BMLabel");
        BMLabel->setGeometry(QRect(520, 90, 49, 16));
        BMLabel->setAlignment(Qt::AlignCenter);
        HaraczLabel = new QLabel(GameplayWidget);
        HaraczLabel->setObjectName("HaraczLabel");
        HaraczLabel->setGeometry(QRect(600, 90, 49, 16));
        HaraczLabel->setAlignment(Qt::AlignCenter);
        GameResultWidget = new QWidget(centralwidget);
        GameResultWidget->setObjectName("GameResultWidget");
        GameResultWidget->setGeometry(QRect(0, 10, 1024, 768));
        ResultLabel = new QLabel(GameResultWidget);
        ResultLabel->setObjectName("ResultLabel");
        ResultLabel->setGeometry(QRect(0, 240, 1021, 361));
        QFont font1;
        font1.setPointSize(50);
        ResultLabel->setFont(font1);
        ResultLabel->setFrameShape(QFrame::NoFrame);
        ResultLabel->setAlignment(Qt::AlignCenter);
        PlayerCreationWidget = new QWidget(centralwidget);
        PlayerCreationWidget->setObjectName("PlayerCreationWidget");
        PlayerCreationWidget->setGeometry(QRect(13, 27, 1021, 761));
        PlayerNameEdit = new QLineEdit(PlayerCreationWidget);
        PlayerNameEdit->setObjectName("PlayerNameEdit");
        PlayerNameEdit->setGeometry(QRect(260, 180, 471, 61));
        QFont font2;
        font2.setPointSize(24);
        PlayerNameEdit->setFont(font2);
        PlayerNameEdit->setMaxLength(32);
        PlayerNameEdit->setFrame(true);
        PlayerNameEdit->setAlignment(Qt::AlignCenter);
        isRobotCheckbox = new QCheckBox(PlayerCreationWidget);
        isRobotCheckbox->setObjectName("isRobotCheckbox");
        isRobotCheckbox->setGeometry(QRect(280, 260, 121, 31));
        QFont font3;
        font3.setPointSize(18);
        isRobotCheckbox->setFont(font3);
        addPlayerButton = new QPushButton(PlayerCreationWidget);
        addPlayerButton->setObjectName("addPlayerButton");
        addPlayerButton->setGeometry(QRect(260, 340, 471, 61));
        endCreationButton = new QPushButton(PlayerCreationWidget);
        endCreationButton->setObjectName("endCreationButton");
        endCreationButton->setGeometry(QRect(500, 440, 231, 61));
        ServerIP = new QLineEdit(PlayerCreationWidget);
        ServerIP->setObjectName("ServerIP");
        ServerIP->setGeometry(QRect(260, 440, 231, 61));
        ServerIP->setFont(font2);
        ServerIP->setMaxLength(32);
        ServerIP->setFrame(true);
        ServerIP->setAlignment(Qt::AlignCenter);
        isHostCheckbox = new QCheckBox(PlayerCreationWidget);
        isHostCheckbox->setObjectName("isHostCheckbox");
        isHostCheckbox->setGeometry(QRect(260, 501, 231, 41));
        isHostCheckbox->setFont(font3);
        PlayerWaitingForGame = new QWidget(centralwidget);
        PlayerWaitingForGame->setObjectName("PlayerWaitingForGame");
        PlayerWaitingForGame->setGeometry(QRect(10, 20, 1024, 768));
        WaitingLabel = new QLabel(PlayerWaitingForGame);
        WaitingLabel->setObjectName("WaitingLabel");
        WaitingLabel->setGeometry(QRect(10, 0, 991, 661));
        WaitingLabel->setFont(font1);
        WaitingLabel->setFrameShape(QFrame::NoFrame);
        WaitingLabel->setAlignment(Qt::AlignCenter);
        StartGameButton = new QPushButton(PlayerWaitingForGame);
        StartGameButton->setObjectName("StartGameButton");
        StartGameButton->setGeometry(QRect(390, 680, 231, 61));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PlayerLabel->setText(QCoreApplication::translate("MainWindow", "[PLAYER NAME]", nullptr));
        LansButton->setText(QCoreApplication::translate("MainWindow", "Lans", nullptr));
        RobotaButton->setText(QCoreApplication::translate("MainWindow", "Do roboty", nullptr));
        HaraczButton->setText(QCoreApplication::translate("MainWindow", "Haracz", nullptr));
        BMWButton->setText(QCoreApplication::translate("MainWindow", "BMW", nullptr));
        IvanButton->setText(QCoreApplication::translate("MainWindow", "Ivan", nullptr));
        SzacunLabel->setText(QCoreApplication::translate("MainWindow", "Szacun:", nullptr));
        KasaLabel->setText(QCoreApplication::translate("MainWindow", "Kasa:", nullptr));
        BMLabel->setText(QCoreApplication::translate("MainWindow", "BMW:", nullptr));
        HaraczLabel->setText(QCoreApplication::translate("MainWindow", "Haracz:", nullptr));
        ResultLabel->setText(QCoreApplication::translate("MainWindow", "[Result]", nullptr));
#if QT_CONFIG(tooltip)
        PlayerNameEdit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nazwa gracza</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PlayerNameEdit->setText(QCoreApplication::translate("MainWindow", "Nazwa gracza", nullptr));
        isRobotCheckbox->setText(QCoreApplication::translate("MainWindow", " Gracz SI", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("MainWindow", "Dodaj gracza", nullptr));
        endCreationButton->setText(QCoreApplication::translate("MainWindow", "Graj!", nullptr));
        ServerIP->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        isHostCheckbox->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        WaitingLabel->setText(QCoreApplication::translate("MainWindow", "[Result]", nullptr));
        StartGameButton->setText(QCoreApplication::translate("MainWindow", "Graj!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
