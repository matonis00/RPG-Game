
#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Weapon.h"
#include "Armor.h"
class Equipment
{
    std::vector<std::shared_ptr<Item>> Bag;
    std::shared_ptr<Weapon> e_Weapon;
    std::shared_ptr<Armor> e_Helm;
    std::shared_ptr<Armor> e_Armor;
    std::shared_ptr<Armor> e_Gloves;

public:
    Equipment();
    Equipment(std::string& v_Profession);
    Equipment(std::vector<std::shared_ptr<Item>> v_Bag, std::shared_ptr<Weapon> v_e_Weapon, std::shared_ptr<Armor> v_e_Helm, std::shared_ptr<Armor> v_e_Armor, std::shared_ptr<Armor> v_e_Gloves);
    void Show_Bag();
    void Show_Equiped();
    void Equip(int ch);
    int Get_Bag_Size();
    bool Bag_full();
    bool Add_Item(std::shared_ptr<Item> v_Item);
    void Remove_Item(int ch);
    std::shared_ptr<Item> Get_Item(int ch);
    std::shared_ptr<Armor> Get_Armor(int ch);
    std::shared_ptr<Weapon> Get_Weapon();
    Statistics Get_Equiped_Stats();
    int Get_Armor_Value();
    void Items_Order_Change(int ch1, int ch2);
};

#endif
