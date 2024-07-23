
#ifndef Quest_H
#define Quest_H
#include "Hero.h"
#include "Monster.h"
class Quest
{
    std::string Short_Description;
    std::string Description;
    int Expirience;
    int Gold;
    std::shared_ptr<Monster> Opponent;

public:
    Quest();
    Quest(std::string& v_Short_Description, std::string v_Description, int& v_Expirience, int& v_Gold, std::shared_ptr<Monster> v_Opponent);
    void Show_Short_Description();
    void Show_Description();
    int Get_Expirience();
    int Get_Gold();
    std::string Get_Short_Description();
    std::string Get_Description();
    std::shared_ptr<Monster> Get_Opponent();
    void Make_New_Quest(std::string& v_Short_Description, std::string& v_Description, int& v_Level, std::string& v_Proffesion, std::string& v_Monster_Name, std::string& v_Weapon_Name);
};
#endif