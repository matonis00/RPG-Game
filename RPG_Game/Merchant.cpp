#include "Merchant.h"
    Merchant::Merchant()
    {
        std::string v_prof = "Mage";
        First_Item = std::shared_ptr<Item>(new Weapon(v_prof));
        Second_Item = std::shared_ptr<Item>(new Armor("Helm", v_prof));
        Third_Item = std::shared_ptr<Item>(new Armor("Armor", v_prof));
    }
    Merchant::Merchant(std::string v_Proffesion)
    {
        First_Item = std::shared_ptr<Item>(new Weapon(v_Proffesion));
        Second_Item = std::shared_ptr<Item>(new Armor("Helm", v_Proffesion));
        Third_Item = std::shared_ptr<Item>(new Armor("Armor", v_Proffesion));
    }
    Merchant::Merchant(std::shared_ptr<Item> v_First_Item, std::shared_ptr<Item> v_Second_Item, std::shared_ptr<Item> v_Third_Item) : First_Item(v_First_Item), Second_Item(v_Second_Item), Third_Item(v_Third_Item)
    {
    }
    std::shared_ptr<Item> Merchant::Get_Item(int ch)
    {
        if (ch == 0)return First_Item;
        else if (ch == 1)return Second_Item;
        else if (ch == 2)return Third_Item;
        else return nullptr;
    };
    bool Merchant::Buy_Item(int ch, std::shared_ptr<Hero> v_Hero)
    {
        std::shared_ptr<Item> tmp;
        switch (ch)
        {
        case 1:
            tmp = First_Item;
            break;
        case 2:
            tmp = Second_Item;
            break;
        case 3:
            tmp = Third_Item;
            break;
        default:
           // std::cout << "Zly wybor!" << std::endl;
            return false;
            break;
        }

        if (v_Hero->Get_Equipment()->Bag_full())
        {
            //std::cout << "Masz pelny plecak sprzedaj cos!" << std::endl;
            return false;
        }
        int tmp_p = tmp->Get_Price() * (2);
        if (v_Hero->Get_Gold() < tmp_p)
        {
            //std::cout << "Nie masz wystarczajaco zlota!" << std::endl;
            return false;
        }
        if (v_Hero->Get_Equipment()->Add_Item(tmp))
        {
            v_Hero->Decrese_Gold(tmp_p);
            return true;
        }
        return false;
    };
    bool Merchant::Sell_Item(int ch, std::shared_ptr<Hero> v_Hero)
    {
        if (ch > 6 || ch > v_Hero->Get_Equipment()->Get_Bag_Size() || ch <= 0)
        {
            std::cout << "Zly wybor!" << std::endl;
            return false;
        }
        if (v_Hero->Get_Equipment()->Get_Item(ch - 1) == nullptr)return false;
        int v_price = v_Hero->Get_Equipment()->Get_Item(ch - 1)->Get_Price();
        v_Hero->Get_Equipment()->Remove_Item(ch - 1);
        v_Hero->Increse_Gold(v_price);
        return true;


    };
    void Merchant::Add_New_Item(int ch, int v_Level, std::string& v_Proffesion, std::string& v_Name, std::string& v_Type)
    {
        std::shared_ptr<Item> t_ptr;
        if (v_Type == "Weapon")
        {
            t_ptr = std::shared_ptr<Weapon>(new Weapon(v_Proffesion, v_Level, v_Name));
        }
        else
        {
            t_ptr = std::shared_ptr<Armor>(new Armor(v_Proffesion, v_Level, v_Type, v_Name));
        }

        switch (ch)
        {
        case 1:
            First_Item = t_ptr;
            break;
        case 2:
            Second_Item = t_ptr;
            break;
        case 3:
            Third_Item = t_ptr;
            break;
        default:
            std::cout << "Nie udalo sie dodac" << std::endl;
            return;
            break;
        }
    }
    void Merchant::Show_All()
    {
        std::cout << "1. " << First_Item->Get_Type() << " Gold: " << (First_Item->Get_Price() * (2)) << " : ";
        First_Item->Show();
        std::cout << std::endl;
        std::cout << "2. " << Second_Item->Get_Type() << " Gold: " << (Second_Item->Get_Price() * (2)) << " : ";
        Second_Item->Show();
        std::cout << std::endl;
        std::cout << "3. " << Third_Item->Get_Type() << " Gold: " << (Third_Item->Get_Price() * (2)) << " : ";
        Third_Item->Show();
        std::cout << std::endl;

    }
