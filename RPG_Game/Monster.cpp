#include "Monster.h"
#include "Function.h"
    Monster::Monster(std::string& v_Race, std::string& v_Profesion)
    {
        Profesion = v_Profesion;
        Race = v_Race;
        int tmp = rand() % 3;
        Stats.Strength += tmp + 1;
        tmp = rand() % 3;
        Stats.Dexterity += tmp + 1;
        tmp = rand() % 3;
        Stats.Intelligence += tmp + 1;
        tmp = rand() % 3;
        Stats.Stamina += tmp + 1;
        tmp = rand() % 3;
        Stats.Luck += tmp + 1;
        Armor_value += 0;
        if (v_Profesion == "Mage")
        {
            Stats.Intelligence += 2;
        }
        else if (v_Profesion == "Hunter")
        {
            Stats.Dexterity += 2;
        }
        else
        {
            Stats.Strength += 2;
        }
        Level = 1;
        Monster_Weapon = std::shared_ptr<Weapon>(new Weapon(v_Profesion));
    }
    Monster::Monster(Statistics& v_Stats, int& v_Armor_Value, std::string& v_Name, int& v_Level, std::string& v_Race, std::string& v_Proffesion, std::shared_ptr<Weapon> v_Monster_Weapon) : Monster_Weapon(v_Monster_Weapon)
    {
        Name = v_Name;
        Stats = v_Stats;
        Armor_value = v_Armor_Value;
        Level = v_Level;
        Race = v_Race;
        Profesion = v_Proffesion;
    }
    Monster::Monster(std::string& v_Proffesion, std::string& v_Race, std::string& v_Monster_Name, int& v_Level, std::string& v_Weapon_Name)
    {
        Stats = 0;
        Profesion = v_Proffesion;
        Name = v_Monster_Name;
        Race = v_Race;
        Monster_Weapon = std::shared_ptr<Weapon>(new Weapon(v_Proffesion, v_Level, v_Weapon_Name));
        Level = v_Level;

        Stats.Strength += (v_Level + rand() % v_Level + 1);
        Stats.Dexterity += (v_Level + rand() % v_Level + 1);
        Stats.Intelligence += (v_Level + rand() % v_Level + 1);
        Stats.Stamina += (v_Level + rand() % v_Level + 1);
        Stats.Luck += (v_Level + rand() % v_Level + 1);
        if (v_Proffesion == "Mage")
        {
            Stats.Intelligence += v_Level / 2;
            Stats.Luck += v_Level / 2;
            Armor_value += 1;
        }
        else if (v_Proffesion == "Hunter")
        {
            Stats.Dexterity += v_Level / 2;
            Stats.Stamina += v_Level / 3;
            Stats.Luck += v_Level / 3;
            Armor_value += 1;
        }
        else
        {
            Stats.Strength += v_Level / 2;
            Stats.Stamina += v_Level / 2;
            Armor_value += 1;
        }
        int t_tmp = v_Level / 10;
        while (t_tmp>0)
        {
            Stats += v_Level*2;
            t_tmp--;
        }

    }
    void Monster::Show_All()
    {
        Statistics FullStats = Stats + Monster_Weapon->Get_Stats();
        int v_avg_dmg = (float)(Monster_Weapon->Get_max_Damage() + Monster_Weapon->Get_min_Damage()) / 2;
        int v_crit_chance = (float)((FullStats.Luck * 5) / (Level * 2));
        std::cout << "Nazwa: " << Name << std::endl;
        std::cout << "Klasa: " << Profesion << std::endl;
        std::cout << "Poziom: " << Level << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "Sila: " << FullStats.Strength;
        if (Profesion == "Warrior")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Strength / 10);
            std::cout << ", Srednie Obrazenia: ~" << v_dmg << " dmg";
        }
        std::cout << std::endl;
        std::cout << "Zrecznosc: " << FullStats.Dexterity;
        if (Profesion == "Hunter")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Dexterity / 10);
            std::cout << ", Srednie Obrazenia: ~"  << v_dmg << " dmg";
        }
        std::cout << std::endl;
        std::cout << "Inteligencja: " << FullStats.Intelligence;
        if (Profesion == "Mage")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Intelligence / 10);
            std::cout << ", Srednie Obrazenia: ~"  << v_dmg << " dmg";
        }
        std::cout << std::endl;
        std::cout << "Wytrzymalosc: " << FullStats.Stamina << ", HP: " << this->Get_HP()<< std::endl;
        std::cout << "Szczescie: " << FullStats.Luck <<", Szansa na Kryta: "<<v_crit_chance<<"%"<< std::endl;
        std::cout << "========================================" << std::endl;
    }
    std::string Monster::Get_Show_All()
    {
        std::string tmp_str="";
        Statistics FullStats = Stats + Monster_Weapon->Get_Stats();
        int v_avg_dmg = (float)(Monster_Weapon->Get_max_Damage() + Monster_Weapon->Get_min_Damage()) / 2;
        int v_crit_chance = (float)((FullStats.Luck * 5) / (Level * 2));
        tmp_str+= "Nazwa: " + Name + "\n";
        tmp_str+= "Klasa: " + Profesion + "\n";
        tmp_str += "Poziom: "+ std::to_string(Level)+ "\n";
        //tmp_str+= "=======================================\n";
        tmp_str+= "Sila: ";
        tmp_str += std::to_string(FullStats.Strength);
        if (Profesion == "Warrior")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Strength / 10);
            tmp_str+= ", Srednie Obrazenia: ~";
            tmp_str += std::to_string(v_dmg);
            tmp_str += " dmg";
        }
       tmp_str+='\n';
       tmp_str+= "Zrecznosc: ";
       tmp_str += std::to_string(FullStats.Dexterity);
        if (Profesion == "Hunter")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Dexterity / 10);
            tmp_str += ", Srednie Obrazenia: ~";
            tmp_str += std::to_string(v_dmg);
            tmp_str += " dmg";
        }
        tmp_str+= '\n';
        tmp_str+= "Inteligencja: ";
        tmp_str += std::to_string(FullStats.Intelligence);
        if (Profesion == "Mage")
        {
            int v_dmg = v_avg_dmg * (1 + (float)FullStats.Intelligence / 10);
            tmp_str += ", Srednie Obrazenia: ~";
            tmp_str += std::to_string(v_dmg);
            tmp_str += " dmg";
        }
        tmp_str+= '\n';
        tmp_str+= "Wytrzymalosc: ";
        tmp_str += std::to_string(FullStats.Stamina);
        tmp_str += ", HP: ";
        tmp_str += std::to_string(this->Get_HP());
        tmp_str += '\n';
        tmp_str+= "Szczescie: ";
        tmp_str += std::to_string(FullStats.Luck);
        tmp_str += ", Szansa na Kryta: ";
        tmp_str += std::to_string(v_crit_chance);
        tmp_str += "%\n";
        //tmp_str+= "========================================\n";
        return tmp_str;
    }

    std::shared_ptr<Weapon> Monster::Get_Weapon()
    {
        return Monster_Weapon;
    }
    int Monster::Get_HP()
    {
        Statistics FullStats = Stats + Monster_Weapon->Get_Stats();
        if (Profesion == "Mage")
        {
            return FullStats.Stamina * 2 * (Level + 1);
        }
        else if (Profesion == "Warrior")
        {
            return FullStats.Stamina * 5 * (Level + 1);
        }
        else if (Profesion == "Hunter")
        {
            return FullStats.Stamina * 4 * (Level + 1);
        }
    }
    int Monster::Get_Hit()
    {
        int v_min_dmg, v_max_dmg, v_dmg_stat, v_hit, v_luck, v_crit_chance;
        v_max_dmg = Monster_Weapon->Get_max_Damage();
        v_min_dmg = Monster_Weapon->Get_min_Damage();
        v_dmg_stat = 9;
        Statistics FullStats = Stats + Monster_Weapon->Get_Stats();
        if (Profesion == "Mage")
        {
            v_dmg_stat = FullStats.Intelligence;
        }
        else if (Profesion == "Warrior")
        {
            v_dmg_stat = FullStats.Strength;
        }
        else if (Profesion == "Hunter")
        {
            v_dmg_stat = FullStats.Dexterity;
        }

        v_hit = rand() % (v_max_dmg - v_min_dmg) + v_min_dmg;
        v_hit = v_hit * (1 + (v_dmg_stat) / 10);
        v_luck = rand() % 100 + 1;
        v_crit_chance = (float)((FullStats.Luck * 5) / (Level * 2));
        if (v_luck <= v_crit_chance)return v_hit * 2;
        return v_hit;
    }
    Monster& Monster::Get()
    {
        return *this;
    }
    Statistics Monster::Get_Stats()
    {
        return Stats;
    }
    std::string Monster::Get_Name()
    {
        return Name;
    }

    std::ostream& operator<<(std::ostream& s, Monster& x)
    {
        std::string t_Stats = Connect_Stats(x.Get_Stats());
        s << t_Stats << " \"" << x.Name << "\" " << x.Armor_value << " " << x.Level << " " << x.Race << " " << x.Profesion;
        return s;
    }

