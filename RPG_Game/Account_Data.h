
#ifndef ACCOUNT_DATA_H
#define ACCOUNT_DATA_H
#include "Inn.h"
#include "Dungeon.h"
#include "Merchant.h"


class Account_Data
{
    std::string Login;
    std::string Password;
    std::shared_ptr<Options> Settings;
    std::shared_ptr<Hero> Hero_status;
    std::shared_ptr<Inn> Inn_status;
    std::shared_ptr<Merchant>  Merchant_status;
    std::shared_ptr<Dungeon> Dungeon_status;
    bool lost;

public:
    Account_Data();
    Account_Data(std::string& v_Login, std::string& v_Password);
    Account_Data(std::string& v_Login, std::string& v_Password, std::shared_ptr<Hero>& v_Hero_status, std::shared_ptr<Options>& v_Settings);
    Account_Data(std::string v_Login, std::string v_Password, std::shared_ptr<Options> v_Settings, std::shared_ptr<Hero> v_Hero_status, std::shared_ptr<Inn> v_Inn_status, std::shared_ptr<Merchant>  v_Merchant_status, std::shared_ptr<Dungeon> v_Dungeon_status, bool v_lost);
    std::string Get_login();
    std::string Get_Password();
    std::shared_ptr<Hero> Get_Hero_status();
    std::shared_ptr<Inn> Get_Inn_status();
    std::shared_ptr<Merchant> Get_Merchant_status();
    std::shared_ptr<Dungeon> Get_Dungeon_status();
    std::shared_ptr<Options> Get_Settings();
    bool Get_Lost();
    void Set_Settings(Options v_Settings);
    void Set_Inn_status(std::shared_ptr<Inn> v_Inn_status);
    void Set_Hero_status(std::shared_ptr<Hero> v_Hero_status);
    void Set_Merchant_status(std::shared_ptr<Merchant> v_Merchant_status);
    void Set_Dungeon_status(std::shared_ptr<Dungeon> v_Dungeon_status);
    void Lost();

};
#endif