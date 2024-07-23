
#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
class Weapon : public Item
{
    int min_Damage;
    int max_Damage;
public:
    Weapon(std::string& v_Profession);
    Weapon(std::string& v_Profession, int& v_Level, std::string& v_Name, int v_max = 1);
    Weapon(Statistics& v_Stats, std::string& v_Name, int& v_Price, int& v_min_Damage, int& v_max_Damage);
    void Show();
    int Get_min_Damage();
    int Get_max_Damage();
    Statistics Get_Stats();
    std::string  Get_Type();
    Weapon& Get();
    friend std::ostream& operator<<(std::ostream& s, Weapon& x);
};
#endif