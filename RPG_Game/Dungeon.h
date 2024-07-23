
#ifndef DUNGEON_H
#define DUNGEON_H
#include "Monster.h"
class Dungeon
{
    int Floor;
    int Progress;
    std::shared_ptr<Monster> Opponent;

public:
    Dungeon();
    Dungeon(int v_Floor, int v_Progress, std::shared_ptr<Monster> v_Opponent);
    int Get_Floor();
    int Get_Progress();
    std::shared_ptr<Monster> Get_Opponent();
    void Go_Next();
    void Reset_Oponent(std::shared_ptr<Monster> v_Oponent);
};
#endif