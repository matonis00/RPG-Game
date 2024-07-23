#include "Hero.h"
#include "Function.h"
    Hero::Hero(std::string& v_Race, std::string& v_Profesion)
    {
        Stats.Strength = 10;
        Stats.Dexterity = 10;
        Stats.Intelligence = 10;
        Stats.Stamina = 10;
        Stats.Luck = 10;
        Armor_value = 0;
        Profesion = v_Profesion;
        Race = v_Race;
        if (v_Race == "Human")
        {
            Stats.Strength += 0;
            Stats.Dexterity += 0;
            Stats.Intelligence += 0;
            Stats.Stamina += 0;
            Stats.Luck += 0;
            Armor_value += 0;
        }
        else if (v_Race == "Dwarf")
        {
            Stats.Strength += 0;
            Stats.Dexterity += -2;
            Stats.Intelligence += -1;
            Stats.Stamina += 2;
            Stats.Luck += 1;
            Armor_value += 0;
        }
        else if (v_Race == "Elf")
        {
            Stats.Strength += -1;
            Stats.Dexterity += 2;
            Stats.Intelligence += 0;
            Stats.Stamina += -1;
            Stats.Luck += 0;
            Armor_value += 0;
        }
        else if (v_Race == "Ork")
        {
            Stats.Strength += 1;
            Stats.Dexterity += 0;
            Stats.Intelligence += -1;
            Stats.Stamina += 0;
            Stats.Luck += 0;
            Armor_value += 0;
        }
        else if (v_Race == "Undead")
        {
            Stats.Strength += -2;
            Stats.Dexterity += 2;
            Stats.Intelligence += 1;
            Stats.Stamina += -1;
            Stats.Luck += 0;
            Armor_value += 0;
        }
        else
        {
            Stats.Strength += -2;
            Stats.Dexterity += 2;
            Stats.Intelligence += 0;
            Stats.Stamina += -1;
            Stats.Luck += 1;
            Armor_value += 0;
        }

        if (v_Profesion == "Mage")
        {
            Stats.Strength += 0;
            Stats.Dexterity += 0;
            Stats.Intelligence += 8;
            Stats.Stamina += 2;
            Stats.Luck += 5;
            Armor_value += 0;
        }
        else if (v_Profesion == "Hunter")
        {
            Stats.Strength += 1;
            Stats.Dexterity += 7;
            Stats.Intelligence += 1;
            Stats.Stamina += 4;
            Stats.Luck += 2;
            Armor_value += 0;
        }
        else
        {
            Stats.Strength += 7;
            Stats.Dexterity += 3;
            Stats.Intelligence += 0;
            Stats.Stamina += 5;
            Stats.Luck += 0;
            Armor_value += 0;
        }




        Level = 1;



        Hero_Equipment = std::shared_ptr<Equipment>(new Equipment(v_Profesion));
        Gold = 0;
        Experience = 0;
    };
    Hero::Hero(Statistics& v_Stats, int& v_Armor_Value, int& v_Level, std::string& v_Race, std::string& v_Proffesion, std::shared_ptr<Equipment> v_Hero_Equipment, int& v_Gold, int& v_Expirience) : Hero_Equipment(v_Hero_Equipment), Gold(v_Gold), Experience(v_Expirience)
    {
        Stats = v_Stats;
        Armor_value = v_Armor_Value;
        Level = v_Level;
        Race = v_Race;
        Profesion = v_Proffesion;
    }
    int Hero::Get_HP()
    {
        Statistics Full_Stats = Stats + Hero_Equipment->Get_Equiped_Stats();
        if (Profesion == "Mage")
        {
            return Full_Stats.Stamina * 2 * (Level + 1);
        }
        else if (Profesion == "Warrior")
        {
            return Full_Stats.Stamina * 5 * (Level + 1);
        }
        else if (Profesion == "Hunter")
        {
            return Full_Stats.Stamina * 4 * (Level + 1);
        }
    }
    int Hero::Get_Hit()
    {
        int v_min_dmg, v_max_dmg, v_dmg_stat, v_hit, v_luck, v_crit_chance;
        v_max_dmg = Hero_Equipment->Get_Weapon()->Get_max_Damage();
        v_min_dmg = Hero_Equipment->Get_Weapon()->Get_min_Damage();
        v_dmg_stat = 0;
        Statistics Full_Stats = Stats + Hero_Equipment->Get_Equiped_Stats();
        if (Profesion == "Mage")
        {
            v_dmg_stat = Full_Stats.Intelligence;
        }
        else if (Profesion == "Warrior")
        {
            v_dmg_stat = Full_Stats.Strength;
        }
        else if (Profesion == "Hunter")
        {
            v_dmg_stat = Full_Stats.Dexterity;
        }

        v_hit = rand() % (v_max_dmg - v_min_dmg) + v_min_dmg;
        v_hit = v_hit * (1 + (v_dmg_stat) / 10);
        v_luck = rand() % 100 + 1;
        v_crit_chance = (float)((Full_Stats.Luck * 5) / (Level * 2));
        if (v_crit_chance >= 50) v_crit_chance = 50;
        if (v_luck <= v_crit_chance)return v_hit * 2;
        return v_hit;
    }
    int Hero::Get_Reduction()
    {
        int tmp = (Armor_value + Hero_Equipment->Get_Armor_Value()) / Level;
        if (Profesion == "Mage" && tmp > 10)return 10;
        else if (Profesion == "Hunter" && tmp > 25)return 25;
        else if (Profesion == "Warrior" && tmp > 50)return 50;
        else return tmp;
    }
    void Hero::Show_All()
    {
        int Needed_Exp = 500 * Level;
        int t_Level = Level;
        int t_tmp = 1;
        while (t_Level > 10)
        {
            t_tmp++;
            t_Level -= 10;
        }
        Needed_Exp *= t_tmp;
        Statistics Full_Stats = Stats + Hero_Equipment->Get_Equiped_Stats();
        int v_crit_chance = (float)((Full_Stats.Luck * 5) / (Level * 2));
        if (v_crit_chance >= 50) v_crit_chance = 50;

        int v_avg_dmg = (Hero_Equipment->Get_Weapon()->Get_max_Damage() + Hero_Equipment->Get_Weapon()->Get_min_Damage()) / 2;

        
        std::cout << "Rasa: " << Race << ", Klasa: " << Profesion << std::endl;
        std::cout << "Poziom: " << Level << ", Doswiadczenie: " << Experience << " / " << Needed_Exp << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "Sila: " << Full_Stats.Strength; 
        if (Profesion == "Warrior")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Strength / 10);
            std::cout << ", Œrednie Obra¿enia: ~" << v_dmg << " dmg";
        }
        std::cout << std::endl;

        std::cout << "Zrecznosc: " << Full_Stats.Dexterity; 
        if (Profesion == "Hunter")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Dexterity / 10);
            std::cout << ", Œrednie Obra¿enia: ~" << v_dmg << " dmg";
        }
        std::cout << std::endl;
        std::cout << "Inteligencja: " << Full_Stats.Intelligence;
        if (Profesion == "Mage")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Intelligence / 10);
            std::cout << ", Œrednie Obra¿enia: ~" << v_dmg << " dmg";
        }
        std::cout << std::endl;
        std::cout << "Wytrzyma³osc: " << Full_Stats.Stamina << ", HP: " << this->Get_HP() << std::endl;
        std::cout << "Szczescie: " << Full_Stats.Luck << ", Szanasa na trafienie krytyczne: " << v_crit_chance << "%" << std::endl;
        std::cout << "Pancerz: " << Armor_value + Hero_Equipment->Get_Armor_Value() << ", Redukcja: " << this->Get_Reduction() << "%" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Zloto: " << Gold << std::endl;
    };
    std::string Hero::Get_Show_All()
    {
        std::string tmp_all ="";
        int Needed_Exp = 500 * Level;
        int t_Level = Level;
        int t_tmp = 1;
        while (t_Level > 10)
        {
            t_tmp++;
            t_Level -= 10;
        }
        Needed_Exp *= t_tmp;
        Statistics Full_Stats = Stats + Hero_Equipment->Get_Equiped_Stats();
        int v_crit_chance = (float)((Full_Stats.Luck * 5) / (Level * 2));
        if (v_crit_chance >= 50) v_crit_chance = 50;

        int v_avg_dmg = (Hero_Equipment->Get_Weapon()->Get_max_Damage() + Hero_Equipment->Get_Weapon()->Get_min_Damage()) / 2;

        
        tmp_all+= "Rasa: " + Race + ", Klasa: "+ Profesion +"\n";
        tmp_all+= "Poziom: " + std::to_string(Level)+ ", Doswiadczenie: " + std::to_string(Experience) + " / " + std::to_string(Needed_Exp)+ "\n";
       // tmp_all+= "=======================================\n";
        tmp_all+= "Sila: " + std::to_string(Full_Stats.Strength);
        if (Profesion == "Warrior")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Strength / 10);
            tmp_all+= ", Srednie Obrazenia: ~" + std::to_string(v_dmg)+ " dmg";
        }
        tmp_all+= "\n";

        tmp_all+= "Zrecznosc: " + std::to_string(Full_Stats.Dexterity);
        if (Profesion == "Hunter")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Dexterity / 10);
            tmp_all+= ", Srednie Obrazenia: ~" + std::to_string(v_dmg )+ " dmg";
        }
        tmp_all+= "\n";
        tmp_all+= "Inteligencja: " + std::to_string(Full_Stats.Intelligence);
        if (Profesion == "Mage")
        {
            int v_dmg = v_avg_dmg * (1 + (float)Full_Stats.Intelligence / 10);
            tmp_all+= ", Srednie Obrazenia: ~" + std::to_string(v_dmg )+ " dmg";
        }
        tmp_all+= "\n";
        tmp_all+= "Wytrzymalosc: " + std::to_string(Full_Stats.Stamina) + ", HP: " + std::to_string(this->Get_HP())+"\n";
        tmp_all+= "Szczescie: " + std::to_string(Full_Stats.Luck) + ", Szanasa na trafienie krytyczne: " + std::to_string(v_crit_chance) +"%" + "\n";
        tmp_all+= "Pancerz: " + std::to_string(Armor_value + Hero_Equipment->Get_Armor_Value()) + ", Redukcja: " + std::to_string(this->Get_Reduction()) + "%" + "\n";
        //tmp_all+= "========================================\n";
        tmp_all+= "Zloto: "  +std::to_string(Gold) + "\n";


        return tmp_all;
    }

    std::shared_ptr<Equipment> Hero::Get_Equipment()
    {
        return Hero_Equipment;
    };
    int Hero::Get_Gold()
    {
        return Gold;
    };
    int Hero::Get_Level()
    {
        return Level;
    }
    void Hero::Levelup()
    {
        int Needed_Exp = 500 * Level;
        int t_Level = Level;
        int t_tmp = 1;
        while (t_Level > 10)
        {
            t_tmp++;
            t_Level -= 10;
        }
        Needed_Exp *= t_tmp;


        while (Experience >= Needed_Exp)
        {
            Level++;
            t_Level++;
            Experience -= Needed_Exp;

            Stats += (1 + (Level / 5));


            if (Profesion == "Mage")
            {
                Stats.Intelligence += Level / 3;
                Stats.Luck += Level / 3;
            }
            else if (Profesion == "Hunter")
            {
                Stats.Dexterity += Level / 3;
                Stats.Luck += Level / 6;
                Stats.Stamina += Level / 6;
            }
            else
            {
                Stats.Strength += Level / 3;
                Stats.Stamina += Level / 3;
            }

            while (t_Level > 10)
            {
                t_tmp++;
                t_Level -= 10;
            }
            Needed_Exp += (500 * t_tmp);

        }


    };
    int Hero::Get_Experience()
    {
        return Experience;
    };
    Hero& Hero::Get()
    {
        return *this;
    }
    void Hero::Increase_Expirience(int v_Expirience)
    {
        Experience += v_Expirience;
        //SPR LVL UP
        Levelup();
    }
    void Hero::Decrese_Gold(int v_gold)
    {
        Gold -= v_gold;
        return;
    }
    void Hero::Increse_Gold(int v_gold)
    {
        Gold += v_gold;
        return;
    }
    std::ostream& operator<<(std::ostream& s, Hero& x)
    {
        std::string t_Stats = Connect_Stats(x.Get_Stats());
        s << t_Stats << " " << x.Armor_value << " " << x.Level << " " << x.Race << " " << x.Profesion << " " << x.Gold << " " << x.Experience;
        return s;
    }

