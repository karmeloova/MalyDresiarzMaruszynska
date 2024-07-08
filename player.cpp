#include "player.h"
Player::Player()
{
    playerNick = "Default";
    isAI = true;
    szacun = 0;
    kasa = 0;
    bmw = 0;
    haracz = 0;
}
Player::Player(std::string newName, bool isPlayerRobot)
{
    playerNick = newName;
    isAI = isPlayerRobot;
    szacun = 0;
    kasa = 0;
    bmw = 0;
    haracz = 0;
}

void Player::Lans()
{
    szacun ++;
}

void Player::DoRoboty()
{
    kasa += 2;
}

void Player::Haracz()
{
    if(kasa < 4) return;

    kasa -= 4;
    haracz ++;
}

void Player::BMW()
{
    bmw ++;
}

void Player::Iwan()
{
    if(kasa >= 1) kasa --;
}

void Player::OnRoundStart()
{
    kasa += haracz;

    for(int i = 0; i<bmw; i++)
    {
        if(kasa >= 2)
        {
            kasa -= 2;
            szacun += 3;
        }
        else
        {
            szacun -= 3;
        }
    }

}

void Player::AIMakeRandomMove()
{
    int choice = std::rand() % ((kasa>=4)?5:4);
    switch(choice)
    {
    case 0:
        Lans();
        break;
    case 1:
        DoRoboty();
        break;
    case 2:
        BMW();
        break;
    case 3:
        Iwan();
        break;
    case 4:
        Haracz();
        break;
    }
}
