#include "Function.h"
std::string Random_Type()
{
    //srand(time(NULL));
    int t_tmp = rand() % 4;
    if (t_tmp == 0)return "Weapon";
    else if (t_tmp == 1)return "Helm";
    else if (t_tmp == 2)return "Armor";
    else return "Gloves";
}
std::string Random_Proffesion()
{
    //srand(time(NULL));
    int t_tmp = rand() % 3;
    if (t_tmp == 0)return "Mage";
    else if (t_tmp == 1)return "Hunter";
    else return "Warrior";
}
std::string Random_Race()
{
    //srand(time(NULL));
    int t_tmp = rand() % 6;
    if (t_tmp == 0)return "Human";
    else if (t_tmp == 1)return "Dwarf";
    else if (t_tmp == 1)return "Elf";
    else if (t_tmp == 1)return "Ork";
    else if (t_tmp == 1)return "Undead";
    else return "Goblin";
}
std::string Connect_Stats(Statistics v_Stats)
{

    std::string t_Stats = "";
    std::string x;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)x = std::to_string(v_Stats.Strength);
        else if (i == 1)x = std::to_string(v_Stats.Dexterity);
        else if (i == 2)x = std::to_string(v_Stats.Intelligence);
        else x = std::to_string(v_Stats.Stamina);
        t_Stats += x;
        t_Stats += ";";
    }
    x = std::to_string(v_Stats.Luck);
    t_Stats += x;
    return t_Stats;
}
std:: vector<int> splitData(const std::string& s, char t_char) {
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, t_char)) {
        int tmp = stoi(item);
        result.push_back(tmp);
    }

    return result;
}
void clearQueue(std::queue<int>& q)
{
    std::queue<int> empty;
    std::swap(q, empty);
}


