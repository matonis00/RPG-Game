#include "Fight.h"
#include <windows.h> 

bool Fight(std::shared_ptr<Hero> v_Hero, std::shared_ptr<Monster> v_Monster, Options v_Settings,  std::queue<int>& v_hits, bool& v_heroStarts)
{
   // srand(time(NULL));
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    int v_Hero_HP, v_Monster_HP, v_Hit, v_reduction;
    bool v_turn, b_Fight = true;
    v_Hero_HP = v_Hero->Get_HP();
    v_Monster_HP = v_Monster->Get_HP();
    v_turn = rand() % 2;
    v_reduction = v_Hero->Get_Reduction();
    v_heroStarts = v_turn;
    while (b_Fight)
    {
        if (v_Settings.FastGame == false)
        {
            //std::cout << "Hero: " << v_Hero_HP << "    Monster: " << v_Monster_HP << std::endl;
            //Sleep(500);
        }

        if (v_turn)
        {
            v_Hit = v_Hero->Get_Hit();
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
            //if (v_Settings.FastGame == false)std::cout << ">>>>  " << v_Hit << " DMG  >>>>" << std::endl;

            v_Monster_HP -= v_Hit;
            v_hits.push(v_Hit);

        }
        else
        {
            v_Hit = v_Monster->Get_Hit();
            v_Hit -= v_Hit * (v_reduction / 100);
            SetConsoleTextAttribute(hOut,FOREGROUND_RED);
            //if (v_Settings.FastGame == false)std::cout << "<<<<  " << v_Hit << " DMG  <<<<" << std::endl;

            v_Hero_HP -= v_Hit;
            v_hits.push(v_Hit);

        }
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        //if (v_Settings.FastGame == false)Sleep(500);
        if (v_Hero_HP <= 0 || v_Monster_HP <= 0)b_Fight = false;

        v_turn = !v_turn;
    }
    //std::cout << "Hero: " << v_Hero_HP << "    Monster: " << v_Monster_HP << std::endl;
    if (v_turn)return false;
    else return true;
}