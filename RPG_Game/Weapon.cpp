#include "Weapon.h"
#include "Function.h"
    Weapon::Weapon(std::string& v_Profession)
    {
        
        Stats = 0;
        if (v_Profession == "Mage")
        {
            min_Damage = 8;
            max_Damage = 10;
        }

        else if (v_Profession == "Warrior")
        {
            min_Damage = 1;
            max_Damage = 7;
        }

        else if (v_Profession == "Hunter")
        {
            min_Damage = 2;
            max_Damage = 8;
        }
        Name = "Bron poczatkowa";
        Price = 1;
    }
    Weapon::Weapon(std::string& v_Profession, int& v_Level, std::string& v_Name, int v_max)
    {
        
        Stats = 0;
        Name = v_Name;
        int avg_Damage = 0;
        if (v_Profession == "Mage")
        {
            avg_Damage = v_Level * 4;
            Stats.Intelligence = 10 * (1 + v_Level / 10);
        }

        else if (v_Profession == "Warrior")
        {
            avg_Damage = v_Level * 2;
            Stats.Strength = 10 * (1 + v_Level / 10);;
        }

        else if (v_Profession == "Hunter")
        {
            avg_Damage = (v_Level * (25 / 10));
            Stats.Dexterity = 10 * (1 + v_Level / 10);
        }

        min_Damage = avg_Damage - (rand() % v_Level + 1);
        max_Damage = avg_Damage + (rand() % v_Level + 1);

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
    Weapon::Weapon(Statistics& v_Stats, std::string& v_Name, int& v_Price, int& v_min_Damage, int& v_max_Damage) : min_Damage(v_min_Damage), max_Damage(v_max_Damage)
    {
        
        Stats = v_Stats;
        Name = v_Name;
        Price = v_Price;
    }
    void Weapon::Show()
    {
        std::cout << Name << ": " << Stats << ", Obrazenia: " << min_Damage << "-" << max_Damage;
    }
    int Weapon::Get_min_Damage()
    {
        return min_Damage;
    }
    int Weapon::Get_max_Damage()
    {
        return max_Damage;
    }
    Statistics Weapon::Get_Stats()
    {
        return Stats;
    }
    std::string  Weapon::Get_Type()
    {
        return "Weapon";
    }
    Weapon& Weapon::Get()
    {
        return *this;
    }

    std::ostream& operator<<(std::ostream& s, Weapon& x)
    {
        std::string t_Stats = Connect_Stats(x.Stats);
        s << t_Stats << " \"" << x.Name << "\" " << x.Price << " " << x.min_Damage << " " << x.max_Damage;
        return s;
    }