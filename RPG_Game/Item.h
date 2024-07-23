
#ifndef ITEM_H
#define ITEM_H
#include "Struct.h"
#include "Function.h"
class Item
{
protected:
    
    Statistics Stats;
    std::string Name;
    int Price;

public:
    void virtual Show() = 0;
    Statistics virtual Get_Stats() = 0;
    std::string virtual Get_Type() = 0;
    int Get_Price();
    std::string Get_Name();
   
};


#endif
