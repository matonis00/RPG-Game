
#ifndef HERO_H
#define HERO_H
#include "Character.h"
class Hero : public Character
{
    std::shared_ptr<Equipment> Hero_Equipment;
    int Gold;
    int Experience;

public:
    Hero(std::string& v_Race, std::string& v_Profesion);
    Hero(Statistics& v_Stats, int& v_Armor_Value, int& v_Level, std::string& v_Race, std::string& v_Proffesion, std::shared_ptr<Equipment> v_Hero_Equipment, int& v_Gold, int& v_Expirience);
    int Get_HP();
    int Get_Hit();
    int Get_Reduction();
    void Show_All();
    std::string Get_Show_All();//NOWE
    std::shared_ptr<Equipment> Get_Equipment();
    int Get_Gold();
    int Get_Level();
    void Levelup();
    int Get_Experience();
    Hero& Get();
    void Increase_Expirience(int v_Expirience);
    void Decrese_Gold(int v_gold);
    void Increse_Gold(int v_gold);
    friend std::ostream& operator<<(std::ostream& s, Hero& x);
};
#endif
