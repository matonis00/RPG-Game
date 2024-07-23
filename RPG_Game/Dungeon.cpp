#include "Dungeon.h"
    Dungeon::Dungeon()
    {
        Floor = 1;
        Progress = 1;
        Opponent = nullptr;
    }
    Dungeon::Dungeon(int v_Floor, int v_Progress, std::shared_ptr<Monster> v_Opponent) : Floor(v_Floor), Progress(v_Progress), Opponent(v_Opponent)
    {

    }
    int Dungeon::Get_Floor()
    {
        return Floor;
    };
    int Dungeon::Get_Progress()
    {
        return Progress;
    };
    std::shared_ptr<Monster> Dungeon::Get_Opponent()
    {
        return Opponent;
    };
    void Dungeon::Go_Next()
    {
        Progress++;
        if (Progress == 11)
        {
            Progress = 1;
            Floor++;
        }

    };
    void Dungeon::Reset_Oponent(std::shared_ptr<Monster> v_Oponent)
    {
        Opponent = v_Oponent;
    }
