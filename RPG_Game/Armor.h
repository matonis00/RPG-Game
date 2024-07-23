
#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
class Armor : public Item
{
    int Armor_value;
    std::string Type;
public:
    Armor(std::string v_Type, std::string& v_Profession);
    Armor(std::string& v_Profession, int& v_Level, std::string v_Type, std::string& v_Name, int v_max = 2);
    Armor(Statistics& v_Stats, std::string& v_Name, int& v_Price, int& v_Armor_value, std::string& v_Type);
    void Show();
    int Get_Armor_value();
    std::string Get_Type();
    Statistics Get_Stats();
    Armor& Get();
    friend std::ostream& operator<<(std::ostream& s, Armor& x);
};


#endif