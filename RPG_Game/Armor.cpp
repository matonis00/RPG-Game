#include "Armor.h"
#include "Function.h"
Armor::Armor(std::string v_Type, std::string& v_Profession) :Type(v_Type)
{
    
    Name = "Poczatk";
    Price = 1;
    if (v_Type == "Helm")
    {
        Name += "owy Helm";
        if (v_Profession == "Mage")Stats.Intelligence += 1;
        else if (v_Profession == "Warrior")Stats.Strength += 1;
        else if (v_Profession == "Hunter")Stats.Dexterity += 1;
        Armor_value = 2;
    }
    else if (v_Type == "Armor")
    {
        Name += "owa Zbroja";
        if (v_Profession == "Mage")Stats.Stamina += 1;
        else if (v_Profession == "Warrior")Stats.Stamina += 1;
        else if (v_Profession == "Hunter")Stats.Stamina += 1;
        Armor_value = 5;
    }
    else if (v_Type == "Gloves")
    {
        Name += "owe Rekawice";
        if (v_Profession == "Mage")Stats.Intelligence += 1;
        else if (v_Profession == "Warrior")Stats.Strength += 1;
        else if (v_Profession == "Hunter")Stats.Dexterity += 1;
        Armor_value = 3;
    }
}
Armor::Armor(std::string& v_Profession, int& v_Level, std::string v_Type, std::string& v_Name, int v_max) :Type(v_Type)
{
    
    Stats = 0;
    if (v_Profession == "Mage")
    {
        Armor_value = v_Level + (rand() % v_Level + 1);
    }

    else if (v_Profession == "Warrior")
    {
        Armor_value = v_Level * 7 + (rand() % (v_Level * 7) + 1);
    }

    else if (v_Profession == "Hunter")
    {
        Armor_value = v_Level * 4 + (rand() % (v_Level * 4) + 1);
    }
    int max = v_max;
    for (int i = 0; i < max; i++)
    {
        int r_Stat = rand() % 5;
        if (r_Stat == 0)Stats.Strength += rand() % (10 * (1 + v_Level / 10)) + v_Level;
        else if (r_Stat == 1)Stats.Dexterity += rand() % (10 * (1 + v_Level / 10)) + v_Level;
        else if (r_Stat == 2)Stats.Intelligence += rand() % (10 * (1 + v_Level / 10)) + v_Level;
        else if (r_Stat == 3)Stats.Stamina += rand() % (10 * (1 + v_Level / 10)) + v_Level;
        else if (r_Stat == 4)Stats.Luck += rand() % (10 * (1 + v_Level / 10)) + v_Level;
    }
    Name = v_Name;
    Price = v_Level * 2 + rand() % (v_Level * 2);
}
Armor::Armor(Statistics& v_Stats, std::string& v_Name, int& v_Price, int& v_Armor_value, std::string& v_Type) : Armor_value(v_Armor_value), Type(v_Type)
{
    
    Stats = v_Stats;
    Name = v_Name;
    Price = v_Price;
}
void Armor::Show()
{
    std::cout << Name << ": " << Stats << ", Pancerz: " << Armor_value;
}
int Armor::Get_Armor_value()
{
    return Armor_value;
}
std::string Armor::Get_Type()
{
    return Type;
}
Statistics Armor::Get_Stats()
{
    return Stats;
}
Armor& Armor::Get()
{
    return *this;
}
std::ostream& operator<<(std::ostream& s, Armor& x)
{
    std::string t_Stats = Connect_Stats(x.Get_Stats());
    s << t_Stats << " \"" << x.Name << "\" " << x.Price << " " << x.Armor_value << " " << x.Type;
    return s;
}


