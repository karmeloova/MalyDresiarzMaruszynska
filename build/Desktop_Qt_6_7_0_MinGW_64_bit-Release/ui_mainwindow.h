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
    QWidget *GameplayWidget;
    QLabel *PlayerLabel;
    QPushButton *LansButton;
    QPushButton *RobotaButton;
    QPushButton *HaraczButton;
    QPushButton *BMWButton;
    QPushButton *IvanButton;
    QLabel *SzacunLabel;
    QLabel *KasaLabel;
    QLabel *BMWLabel;
    QLabel *HaraczLabel;
    QLabel *Zasoby;
    QLabel *Instrukcja;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        GameResultWidget = new QWidget(centralwidget);
        GameResultWidget->setObjectName("GameResultWidget");
        GameResultWidget->setGeometry(QRect(0, 10, 1024, 768));
        ResultLabel = new QLabel(GameResultWidget);
        ResultLabel->setObjectName("ResultLabel");
        ResultLabel->setGeometry(QRect(0, 240, 1021, 361));
        QFont font;
        font.setPointSize(50);
        ResultLabel->setFont(font);
        ResultLabel->setFrameShape(QFrame::NoFrame);
        ResultLabel->setAlignment(Qt::AlignCenter);
        PlayerCreationWidget = new QWidget(centralwidget);
        PlayerCreationWidget->setObjectName("PlayerCreationWidget");
        PlayerCreationWidget->setGeometry(QRect(13, 27, 1021, 761));
        PlayerNameEdit = new QLineEdit(PlayerCreationWidget);
        PlayerNameEdit->setObjectName("PlayerNameEdit");
        PlayerNameEdit->setGeometry(QRect(260, 180, 471, 61));
        QFont font1;
        font1.setPointSize(24);
        PlayerNameEdit->setFont(font1);
        PlayerNameEdit->setMaxLength(32);
        PlayerNameEdit->setFrame(true);
        PlayerNameEdit->setAlignment(Qt::AlignCenter);
        isRobotCheckbox = new QCheckBox(PlayerCreationWidget);
        isRobotCheckbox->setObjectName("isRobotCheckbox");
        isRobotCheckbox->setGeometry(QRect(750, 200, 151, 31));
        QFont font2;
        font2.setPointSize(18);
        isRobotCheckbox->setFont(font2);
        addPlayerButton = new QPushButton(PlayerCreationWidget);
        addPlayerButton->setObjectName("addPlayerButton");
        addPlayerButton->setGeometry(QRect(260, 250, 241, 61));
        QFont font3;
        font3.setPointSize(15);
        addPlayerButton->setFont(font3);
        endCreationButton = new QPushButton(PlayerCreationWidget);
        endCreationButton->setObjectName("endCreationButton");
        endCreationButton->setGeometry(QRect(510, 250, 221, 61));
        endCreationButton->setFont(font3);
        ServerIP = new QLineEdit(PlayerCreationWidget);
        ServerIP->setObjectName("ServerIP");
        ServerIP->setGeometry(QRect(260, 320, 241, 61));
        ServerIP->setFont(font1);
        ServerIP->setMaxLength(32);
        ServerIP->setFrame(true);
        ServerIP->setAlignment(Qt::AlignCenter);
        isHostCheckbox = new QCheckBox(PlayerCreationWidget);
        isHostCheckbox->setObjectName("isHostCheckbox");
        isHostCheckbox->setGeometry(QRect(530, 330, 231, 41));
        isHostCheckbox->setFont(font2);
        PlayerWaitingForGame = new QWidget(centralwidget);
        PlayerWaitingForGame->setObjectName("PlayerWaitingForGame");
        PlayerWaitingForGame->setGeometry(QRect(10, 20, 1024, 768));
        WaitingLabel = new QLabel(PlayerWaitingForGame);
        WaitingLabel->setObjectName("WaitingLabel");
        WaitingLabel->setGeometry(QRect(10, 0, 991, 661));
        WaitingLabel->setFont(font);
        WaitingLabel->setFrameShape(QFrame::NoFrame);
        WaitingLabel->setAlignment(Qt::AlignCenter);
        StartGameButton = new QPushButton(PlayerWaitingForGame);
        StartGameButton->setObjectName("StartGameButton");
        StartGameButton->setGeometry(QRect(390, 680, 231, 61));
        GameplayWidget = new QWidget(centralwidget);
        GameplayWidget->setObjectName("GameplayWidget");
        GameplayWidget->setGeometry(QRect(10, 77, 1024, 701));
        QFont font4;
        font4.setPointSize(14);
        GameplayWidget->setFont(font4);
        PlayerLabel = new QLabel(GameplayWidget);
        PlayerLabel->setObjectName("PlayerLabel");
        PlayerLabel->setGeometry(QRect(0, 0, 1024, 41));
        QFont font5;
        font5.setPointSize(25);
        PlayerLabel->setFont(font5);
        PlayerLabel->setAlignment(Qt::AlignCenter);
        LansButton = new QPushButton(GameplayWidget);
        LansButton->setObjectName("LansButton");
        LansButton->setGeometry(QRect(330, 70, 151, 61));
        LansButton->setFont(font3);
        RobotaButton = new QPushButton(GameplayWidget);
        RobotaButton->setObjectName("RobotaButton");
        RobotaButton->setGeometry(QRect(500, 70, 151, 61));
        RobotaButton->setFont(font3);
        HaraczButton = new QPushButton(GameplayWidget);
        HaraczButton->setObjectName("HaraczButton");
        HaraczButton->setGeometry(QRect(330, 150, 151, 61));
        HaraczButton->setFont(font3);
        BMWButton = new QPushButton(GameplayWidget);
        BMWButton->setObjectName("BMWButton");
        BMWButton->setGeometry(QRect(500, 150, 151, 61));
        BMWButton->setFont(font3);
        IvanButton = new QPushButton(GameplayWidget);
        IvanButton->setObjectName("IvanButton");
        IvanButton->setGeometry(QRect(680, 110, 151, 61));
        IvanButton->setFont(font3);
        SzacunLabel = new QLabel(GameplayWidget);
        SzacunLabel->setObjectName("SzacunLabel");
        SzacunLabel->setGeometry(QRect(170, 60, 61, 31));
        SzacunLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        KasaLabel = new QLabel(GameplayWidget);
        KasaLabel->setObjectName("KasaLabel");
        KasaLabel->setGeometry(QRect(180, 95, 51, 31));
        KasaLabel->setFont(font4);
        KasaLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        BMWLabel = new QLabel(GameplayWidget);
        BMWLabel->setObjectName("BMWLabel");
        BMWLabel->setGeometry(QRect(180, 140, 51, 21));
        BMWLabel->setFont(font4);
        BMWLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        HaraczLabel = new QLabel(GameplayWidget);
        HaraczLabel->setObjectName("HaraczLabel");
        HaraczLabel->setGeometry(QRect(180, 175, 49, 31));
        HaraczLabel->setFont(font4);
        HaraczLabel->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        Zasoby = new QLabel(GameplayWidget);
        Zasoby->setObjectName("Zasoby");
        Zasoby->setGeometry(QRect(90, 60, 61, 151));
        Zasoby->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Instrukcja = new QLabel(GameplayWidget);
        Instrukcja->setObjectName("Instrukcja");
        Instrukcja->setGeometry(QRect(90, 220, 911, 241));
        Instrukcja->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        GameResultWidget->raise();
        PlayerWaitingForGame->raise();
        GameplayWidget->raise();
        PlayerCreationWidget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ResultLabel->setText(QCoreApplication::translate("MainWindow", "[Result]", nullptr));
#if QT_CONFIG(tooltip)
        PlayerNameEdit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nazwa gracza</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        PlayerNameEdit->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nazwa gracza</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        PlayerNameEdit->setText(QCoreApplication::translate("MainWindow", "Nazwa gracza", nullptr));
        isRobotCheckbox->setText(QCoreApplication::translate("MainWindow", "Komputer", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("MainWindow", "Dodaj gracza", nullptr));
        endCreationButton->setText(QCoreApplication::translate("MainWindow", "Graj", nullptr));
        ServerIP->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        isHostCheckbox->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        WaitingLabel->setText(QCoreApplication::translate("MainWindow", "[Result]", nullptr));
        StartGameButton->setText(QCoreApplication::translate("MainWindow", "Graj!", nullptr));
        PlayerLabel->setText(QCoreApplication::translate("MainWindow", "[GRACZ]", nullptr));
        LansButton->setText(QCoreApplication::translate("MainWindow", "Lans", nullptr));
        RobotaButton->setText(QCoreApplication::translate("MainWindow", "Do roboty", nullptr));
        HaraczButton->setText(QCoreApplication::translate("MainWindow", "Haracz", nullptr));
        BMWButton->setText(QCoreApplication::translate("MainWindow", "BMW", nullptr));
        IvanButton->setText(QCoreApplication::translate("MainWindow", "Ivan", nullptr));
        SzacunLabel->setText(QCoreApplication::translate("MainWindow", "Szacun:", nullptr));
        KasaLabel->setText(QCoreApplication::translate("MainWindow", "Kasa:", nullptr));
        BMWLabel->setText(QCoreApplication::translate("MainWindow", "BMW:", nullptr));
        HaraczLabel->setText(QCoreApplication::translate("MainWindow", "Haracz:", nullptr));
        Zasoby->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Szacun:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Kasa:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">BMW:</spa"
                        "n></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Haracz:</span></p></body></html>", nullptr));
        Instrukcja->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Lans - </span>+1 szacun</p><p><span style=\" font-weight:700;\">Do roboty -</span> +2 kasa</p><p><span style=\" font-weight:700;\">Haracz -</span> jednorazowo -4 kasa, do ko\305\204ca gry co rund\304\231 +1 kasa</p><p><span style=\" font-weight:700;\">BMW - </span>je\305\274eli &gt;=2 kasa na pocz\304\205tku tury, to -2 kasa, +3 szacun, w przeciwnym razie -2 szacun</p><p><span style=\" font-weight:700;\">Iwan -</span> wszyscy gracze poza Tob\304\205 -1 kasa</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
