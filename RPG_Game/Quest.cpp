#include "Quest.h"
#include "Function.h"
    Quest::Quest()
    {
        Short_Description = "Opis";
        Description = "Dlugi OPIS";
        Expirience = 0;
        Gold = 0;
        std::string prof, race;
        prof = "Hunter";
        race = "Ork";
        Opponent = std::shared_ptr<Monster>(new Monster(race, prof));
    }
    Quest::Quest(std::string& v_Short_Description, std::string v_Description, int& v_Expirience, int& v_Gold, std::shared_ptr<Monster> v_Opponent) : Short_Description(v_Short_Description), Description(v_Description), Expirience(v_Expirience), Gold(v_Gold), Opponent(v_Opponent)
    {

    }
    void Quest::Show_Short_Description()
    {
        std::cout << "Quest: " << Short_Description << std::endl;
        return;
    }
    void Quest::Show_Description()
    {
        std::cout << "Quest: " << Description << std::endl;
        std::cout << "Exp:" << Expirience << std::endl;
        std::cout << "Gold: " << Gold << std::endl;
        return;
    }
    int Quest::Get_Expirience()
    {
        return Expirience;
    };
    int Quest::Get_Gold()
    {
        return Gold;
    };
    std::string Quest::Get_Short_Description()
    {
        return Short_Description;
    }
    std::string Quest::Get_Description()
    {
        return Description;
    }
    std::shared_ptr<Monster> Quest::Get_Opponent()
    {
        return Opponent;
    };
    void Quest::Make_New_Quest(std::string& v_Short_Description, std::string& v_Description, int& v_Level, std::string& v_Proffesion, std::string& v_Monster_Name, std::string& v_Weapon_Name)
    {
        //srand(time(NULL));
        Short_Description = v_Short_Description;
        Description = v_Description;
        // Zadanko Formula na EXP I GOLD
        Expirience = v_Level * (200 + rand() % 200);
        Gold = 2*(rand() % (v_Level)+v_Level + 1);
        int v_M_Level = v_Level - rand() % 3;
        if (v_M_Level < 1)v_M_Level = 1;

        std::string v_Race = Random_Race();

        Opponent = std::shared_ptr<Monster>(new Monster(v_Proffesion, v_Race, v_Monster_Name, v_M_Level, v_Weapon_Name));
    }
