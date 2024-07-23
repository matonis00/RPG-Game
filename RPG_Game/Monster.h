
#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
class Monster : public Character
{
    std::shared_ptr<Weapon> Monster_Weapon;
    std::string Name;

public:
    Monster(std::string& v_Race, std::string& v_Profesion);
    Monster(Statistics& v_Stats, int& v_Armor_Value, std::string& v_Name, int& v_Level, std::string& v_Race, std::string& v_Proffesion, std::shared_ptr<Weapon> v_Monster_Weapon);
    Monster(std::string& v_Proffesion, std::string& v_Race, std::string& v_Monster_Name, int& v_Level, std::string& v_Weapon_Name);
    void Show_All();
    std::string Get_Show_All();//NOWE
    std::shared_ptr<Weapon> Get_Weapon();
    int Get_HP();
    int Get_Hit();
    Monster& Get();
    Statistics Get_Stats();
    std::string Get_Name();

    friend std::ostream& operator<<(std::ostream& s, Monster& x);
};
#endif
