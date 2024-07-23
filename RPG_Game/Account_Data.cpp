#include "Account_Data.h"
Account_Data::Account_Data()
{
    Settings->FastGame = false;
    Hero_status = nullptr;
    Inn_status = nullptr;
    Merchant_status = nullptr;
    Dungeon_status = nullptr;
    lost = false;
};
Account_Data::Account_Data(std::string& v_Login, std::string& v_Password) : Login(v_Login), Password(v_Password)
{
    Settings->FastGame = false;
    Hero_status = nullptr;
    Inn_status = nullptr;
    Merchant_status = nullptr;
    Dungeon_status = nullptr;
    lost = false;
};
Account_Data::Account_Data(std::string& v_Login, std::string& v_Password, std::shared_ptr<Hero>& v_Hero_status, std::shared_ptr<Options>& v_Settings) : Login(v_Login), Password(v_Password), Settings(v_Settings)
{
    Hero_status = v_Hero_status;
    Inn_status = std::shared_ptr<Inn>(new Inn());
    Merchant_status = std::shared_ptr<Merchant>(new Merchant(v_Hero_status->Get_Profesion()));
    Dungeon_status = std::shared_ptr<Dungeon>(new Dungeon());
    lost = false;
};
Account_Data::Account_Data(std::string v_Login, std::string v_Password, std::shared_ptr<Options> v_Settings, std::shared_ptr<Hero> v_Hero_status, std::shared_ptr<Inn> v_Inn_status, std::shared_ptr<Merchant>  v_Merchant_status, std::shared_ptr<Dungeon> v_Dungeon_status, bool v_lost) :Login(v_Login), Password(v_Password), Settings(v_Settings), Hero_status(v_Hero_status), Inn_status(v_Inn_status), Merchant_status(v_Merchant_status), Dungeon_status(v_Dungeon_status), lost(v_lost)
{
}
std::string Account_Data::Get_login()
{
    return Login;
}
std::string Account_Data::Get_Password()
{
    return Password;
}
std::shared_ptr<Hero> Account_Data::Get_Hero_status()
{
    return Hero_status;
}
std::shared_ptr<Inn> Account_Data::Get_Inn_status()
{
    return Inn_status;
}
std::shared_ptr<Merchant> Account_Data::Get_Merchant_status()
{
    return Merchant_status;
}
std::shared_ptr<Dungeon> Account_Data::Get_Dungeon_status()
{
    return Dungeon_status;
}
std::shared_ptr<Options> Account_Data::Get_Settings()
{
    return Settings;
}
bool Account_Data::Get_Lost()
{
    return lost;
}
void Account_Data::Set_Settings(Options v_Settings)
{
    Settings->FastGame = v_Settings.FastGame;
    Settings->Hardcore = v_Settings.Hardcore;
}
void Account_Data::Set_Inn_status(std::shared_ptr<Inn> v_Inn_status)
{
    Inn_status = v_Inn_status;
    return;
}
void Account_Data::Set_Hero_status(std::shared_ptr<Hero> v_Hero_status)
{
    Hero_status = v_Hero_status;
};
void Account_Data::Set_Merchant_status(std::shared_ptr<Merchant> v_Merchant_status)
{
    Merchant_status = v_Merchant_status;
    return;
};
void Account_Data::Set_Dungeon_status(std::shared_ptr<Dungeon> v_Dungeon_status)
{
    Dungeon_status = v_Dungeon_status;
};
void Account_Data::Lost()
{
    lost = true;
}
