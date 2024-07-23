
#ifndef Data_base_H
#define Data_base_H
#include "Account_Data.h"
class Data_base
{
    std::vector<Account_Data> Data;
    std::vector<std::vector<std::shared_ptr<Monster>>> DungeonsBase;
    std::map<std::string, std::map<std::string, std::vector<std::string>>> ItemBase;
    std::map<std::string, std::vector<std::string>> MonsterBase;
    std::vector<std::pair<std::string, std::string>> QuestBase;

public:
    Data_base(std::string v_file);
    bool Check(std::string& t_login);
    std::string Get_Pass(std::string& t_login);
    std::shared_ptr<Account_Data> Get_AD(std::string& t_login, std::string& t_password);
    void Add_account(Account_Data& t_AD);
    std::string Get_New_Item_Name(std::string& v_Proffesion, std::string& v_Type);
    std::string Get_New_Monster_Name(std::string& v_Proffesion);
    std::pair<std::string, std::string> Get_New_Quest();
    std::shared_ptr<Monster> Get_Dungeon_Monster(int v_Floor, int v_Progress);
    void Save(std::string v_file);
};
#endif