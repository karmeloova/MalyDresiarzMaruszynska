#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
public:
    Player();
    Player(string newName, bool isPlayerAI);
    string playerNick;

    bool isAI = false;

    int szacun = 0;
    int kasa = 0;
    int bmw = 0;
    int haracz = 0;

    void Lans();
    void DoRoboty();
    void Haracz();
    void BMW();
    void Iwan();

    void OnRoundStart();
    void AIMakeRandomMove();
};

#endif
