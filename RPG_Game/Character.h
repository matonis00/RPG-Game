
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Equipment.h"

class Character
{
protected:
    Statistics Stats;
    int Armor_value;
    int Level;
    std::string Race;
    std::string Profesion;

public:
    virtual void Show_All() = 0;
    virtual std::string Get_Show_All() = 0;
    virtual int Get_HP() = 0;
    virtual int Get_Hit() = 0;
    std::string Get_Profesion();
    std::string Get_Race();
    int Get_Armor_value();
    virtual int  Get_Level();
    Statistics Get_Stats();
};

#endif

