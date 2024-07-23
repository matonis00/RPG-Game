
#include "Equipment.h"
Equipment::Equipment()
{
    e_Weapon = nullptr;
    e_Helm = nullptr;
    e_Armor = nullptr;
    e_Gloves = nullptr;
}
Equipment::Equipment(std::string& v_Profession)
{
    e_Weapon = std::shared_ptr<Weapon>(new Weapon(v_Profession));
    e_Helm = std::shared_ptr<Armor>(new Armor("Helm", v_Profession));
    e_Armor = std::shared_ptr<Armor>(new Armor("Armor", v_Profession));
    e_Gloves = std::shared_ptr<Armor>(new Armor("Gloves", v_Profession));
    for (int i = 0; i < 6; i++)
    {
        Bag.push_back(nullptr);
    }

}
Equipment::Equipment(std::vector<std::shared_ptr<Item>> v_Bag, std::shared_ptr<Weapon> v_e_Weapon, std::shared_ptr<Armor> v_e_Helm, std::shared_ptr<Armor> v_e_Armor, std::shared_ptr<Armor> v_e_Gloves) :Bag(v_Bag), e_Weapon(v_e_Weapon), e_Helm(v_e_Helm), e_Armor(v_e_Armor), e_Gloves(v_e_Gloves)
{}
void Equipment::Show_Bag()
{
    int v_num = 0;

    for (int i = 0; i < Bag.size(); i++)
    {
        if (Bag[i] == nullptr)
        {
            std::cout << (i + 1) << ". Puste" << std::endl;
            continue;
        }

        v_num++;
        std::cout << (i + 1) << ". ";
        Bag[i]->Show();
        std::cout <<", Cena : " << Bag[i]->Get_Price() << std::endl;
    }
    if (v_num == 0)std::cout << "Plecak jest pusty" << std::endl;
    else std::cout << "Wolne miejsca: " << (6 - v_num) << std::endl;


};
void Equipment::Show_Equiped()
{
    std::cout << "He³m: ";
    e_Helm->Show();
    std::cout << std::endl;
    std::cout << "Zbroja: ";
    e_Armor->Show();
    std::cout << std::endl;
    std::cout << "Rêkawice: ";
    e_Gloves->Show();
    std::cout << std::endl;
    std::cout << "Broñ: ";
    e_Weapon->Show();
    std::cout << std::endl;
};
void Equipment::Equip(int ch)
{
    std::shared_ptr<Item> tmp = Bag[ch];
    if (tmp == nullptr)
    {
        std::cout << "Nic tam nie ma" << std::endl;
        return;

    }

    if (tmp->Get_Type() == "Weapon")
    {
        Bag[ch] = e_Weapon;
        e_Weapon = std::dynamic_pointer_cast<Weapon>(tmp);

    }
    else if (tmp->Get_Type() == "Helm")
    {
        Bag[ch] = e_Helm;
        e_Helm = std::dynamic_pointer_cast<Armor>(tmp);

    }
    else if (tmp->Get_Type() == "Armor")
    {
        Bag[ch] = e_Armor;
        e_Armor = std::dynamic_pointer_cast<Armor>(tmp);
    }
    else if (tmp->Get_Type() == "Gloves")
    {
        Bag[ch] = e_Gloves;
        e_Gloves = std::dynamic_pointer_cast<Armor>(tmp);
    }
};
int Equipment::Get_Bag_Size()
{
    return Bag.size();
}
bool Equipment::Bag_full() {
    if (Bag.size() < 6)return false;
    else if (Bag[0] == nullptr || Bag[1] == nullptr || Bag[2] == nullptr || Bag[3] == nullptr || Bag[4] == nullptr || Bag[5] == nullptr)return false;
    else return true;
}
bool Equipment::Add_Item(std::shared_ptr<Item> v_Item)
{
    if (Bag.size() == 0)
    {
        Bag.push_back(std::shared_ptr<Item>(v_Item));
        return true;

    }
    else if (Bag.size() < 6)
    {
        for (int i = 0; i < Bag.size(); i++)
        {
            if (Bag[i] == nullptr)
            {
                Bag[i] = std::shared_ptr<Item>(v_Item);
                return true;
            }
        }
        Bag.push_back(std::shared_ptr<Item>(v_Item));
        return true;
    }
    else if (Bag.size() == 6)
    {
        for (int i = 0; i < Bag.size(); i++)
        {
            if (Bag[i] == nullptr)
            {
                Bag[i] = std::shared_ptr<Item>(v_Item);
                return true;
            }
        }
        std::cout << "Cos nie wyszlo!" << std::endl;
        return false;
    }

}
void Equipment::Remove_Item(int ch)
{
    Bag[ch] = nullptr;
}
std::shared_ptr<Item> Equipment::Get_Item(int ch)
{
    return Bag[ch];
};
std::shared_ptr<Armor> Equipment::Get_Armor(int ch)
{
    if (ch == 0)return e_Helm;
    else if (ch == 1)return e_Armor;
    else if (ch == 2) return e_Gloves;
    else return nullptr;
}
std::shared_ptr<Weapon> Equipment::Get_Weapon()
{
    return e_Weapon;
}
Statistics Equipment::Get_Equiped_Stats()
{
    Statistics tmp;
    tmp += e_Weapon->Get_Stats();
    tmp += e_Helm->Get_Stats();
    tmp += e_Armor->Get_Stats();
    tmp += e_Gloves->Get_Stats();
    return tmp;
}
int Equipment::Get_Armor_Value()
{
    int tmp = e_Armor->Get_Armor_value() + e_Helm->Get_Armor_value() + e_Gloves->Get_Armor_value();
    return tmp;
}
void Equipment::Items_Order_Change(int ch1, int ch2)
{
    std::shared_ptr<Item> tmp = Bag[ch1];
    Bag[ch1] = Bag[ch2];
    Bag[ch2] = tmp;
}
