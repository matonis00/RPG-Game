
#ifndef MERCHANT_H
#define MERCHANT_H
#include "Hero.h"

class Merchant
{
    std::shared_ptr<Item> First_Item;
    std::shared_ptr<Item> Second_Item;
    std::shared_ptr<Item> Third_Item;
public:
    Merchant();
    Merchant(std::string v_Proffesion);
    Merchant(std::shared_ptr<Item> v_First_Item, std::shared_ptr<Item> v_Second_Item, std::shared_ptr<Item> v_Third_Item);
    std::shared_ptr<Item> Get_Item(int ch);
    bool Buy_Item(int ch, std::shared_ptr<Hero> v_Hero);
    bool Sell_Item(int ch, std::shared_ptr<Hero> v_Hero);
    void Add_New_Item(int ch, int v_Level, std::string& v_Proffesion, std::string& v_Name, std::string& v_Type);
    void Show_All();
};


#endif