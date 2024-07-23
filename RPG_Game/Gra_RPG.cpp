//#include "Data_base.h"
//#include "Fight.h"
//int x()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//    setlocale(LC_CTYPE, "Polish");
//    srand(time(NULL));
//    bool Play = true;
//    Data_base DB("configfiles2.txt");
//    DB.Save("configfiles2.txt");
//    std::shared_ptr<Account_Data> Current_Player;
//    while (Play)
//    {
//
//        bool Game = false;
//        system("CLS");
//        std::cout << "RPG" << std::endl;
//        std::cout << "1. Nowa gra/postac" << std::endl;
//        std::cout << "2. Logowanie" << std::endl;
//        std::cout << "3. Opusc gre" << std::endl;
//
//        //cin >> chooise;
//        char ch_chooise = _getch();
//
//        int chooise = ch_chooise - 48;
//        switch (chooise)
//        {
//        case 1:
//        {
//            system("CLS");
//            bool session = true;
//            while (session)
//            {
//                std::cout << "Podaj nazwe/login: " << std::endl;
//                std::string tmp;
//                std::cin >> tmp;
//                if (DB.Check(tmp))
//                {
//                    system("CLS");
//                    std::cout << "Nazwa/Login juz zajety." << std::endl;
//                }
//                else
//                {
//                    system("CLS");
//                    std::string t_l = tmp;
//                    std::string t_p;
//                    while (true)
//                    {
//                        std::cout << "Podaj haslo: " << std::endl;
//                        std::cin >> tmp;
//                        t_p = tmp;
//                        std::cout << "Podaj haslo ponownie: " << std::endl;
//                        std::cin >> tmp;
//                        if (t_p == tmp)
//                        {
//                            system("CLS");
//                            std::cout << "Haslo takie samo hurra!" << std::endl;
//                            break;
//                        }
//                        else
//                        {
//                            system("CLS");
//                            std::cout << "Hasla nie sa takie same!" << std::endl;
//                        }
//                    }
//                    std::string t_race;
//                    do
//                    {
//                        std::cout << "Wybierz Rase: " << std::endl;
//                        std::cout << "1. Czlowiek" << std::endl;
//                        std::cout << "2. Krasnolud" << std::endl;
//                        std::cout << "3. Elf" << std::endl;
//                        std::cout << "4. Ork" << std::endl;
//                        std::cout << "5. Nieumarly" << std::endl;
//                        std::cout << "6. Goblin" << std::endl;
//                        char ch_ch_race = _getch();
//                        int ch_race = ch_ch_race - 48;
//                        //cin >> ch_race;
//                        switch (ch_race)
//                        {
//                        case 1:
//                        {
//                            t_race = "Human";
//                            break;
//                        }
//                        case 2:
//                        {
//                            t_race = "Dwarf";
//                            break;
//                        }
//                        case 3:
//                        {
//                            t_race = "Elf";
//                            break;
//                        }
//                        case 4:
//                        {
//                            t_race = "Ork";
//                            break;
//                        }
//                        case 5:
//                        {
//                            t_race = "Undead";
//                            break;
//                        }
//                        case 6:
//                        {
//                            t_race = "Goblin";
//                            break;
//                        }
//                        default:
//                            t_race = "";
//                            system("CLS");
//                            std::cout << "Wybrano zla wartosc! " << std::endl;;
//                            break;
//                        }
//                    } while (t_race == "");
//                    std::string t_profesion;
//                    system("CLS");
//                    do
//                    {
//                        std::cout << "Wybierz Klase: " << std::endl;
//                        std::cout << "1. Wojownik" << std::endl;
//                        std::cout << "2. Mag" << std::endl;
//                        std::cout << "3. Lowca" << std::endl;
//                        char ch_ch_profesion = _getch();
//                        int ch_profesion = ch_ch_profesion - 48;
//                        //cin >> ch_profesion;
//                        switch (ch_profesion)
//                        {
//                        case 1:
//                        {
//                            t_profesion = "Warrior";
//                            break;
//                        }
//                        case 2:
//                        {
//                            t_profesion = "Mage";
//                            break;
//                        }
//                        case 3:
//                        {
//                            t_profesion = "Hunter";
//                            break;
//                        }
//                        default:
//                            t_profesion = "";
//                            system("CLS");
//                            std::cout << "Wybrano zla wartosc! " << std::endl;;
//                            break;
//                        }
//                    } while (t_profesion == "");
//                    std::shared_ptr<Options> t_Settings = std::shared_ptr<Options>(new Options);
//
//                    system("CLS");
//                    while (true)
//                    {
//                        std::cout << "Tryb Hardcore: " << std::endl;
//                        std::cout << "1. Tak" << std::endl;
//                        std::cout << "2. Nie" << std::endl;
//                        char ch_ch_settings = _getch();
//                        int ch_settings = ch_ch_settings - 48;
//                        //cin >> ch_settings;
//                        if (ch_settings == 1)
//                        {
//                            t_Settings->Hardcore = true;
//                            break;
//                        }
//                        else if (ch_settings == 2)
//                        {
//                            t_Settings->Hardcore = false;
//                            break;
//                        }
//                        else {
//                            system("CLS");
//                            std::cout << "Wybrano zla wartosc! " << std::endl;;
//                        }
//                    }
//
//                    system("CLS");
//                    while (true)
//                    {
//                        std::cout << "Tryb SzybkiejGry: " << std::endl;
//                        std::cout << "1. Tak" << std::endl;
//                        std::cout << "2. Nie" << std::endl;
//                        char ch_ch_settings = _getch();
//                        int ch_settings = ch_ch_settings - 48;
//                        //cin >> ch_settings;
//                        if (ch_settings == 1)
//                        {
//                            t_Settings->FastGame = true;
//                            break;
//                        }
//                        else if (ch_settings == 2)
//                        {
//                            t_Settings->FastGame = false;
//                            break;
//                        }
//                        else {
//                            system("CLS");
//                            std::cout << "Wybrano zla wartosc! " << std::endl;;
//                        }
//                    }
//
//
//
//                    std::shared_ptr<Hero>t_H = std::shared_ptr<Hero>(new Hero(t_race, t_profesion));
//                    Current_Player = std::shared_ptr<Account_Data>(new Account_Data(t_l, t_p, t_H, t_Settings));
//                    int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                    for (int i = 0; i < 3; i++)
//                    {
//                        std::pair<std::string, std::string> t_pair = DB.Get_New_Quest();
//                        std::string t_Short_Description = t_pair.first;
//                        std::string t_Description = t_pair.second;
//                        std::string t_Proffesion = Random_Proffesion();
//                        std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
//                        std::shared_ptr<Quest> t_Q = Current_Player->Get_Inn_status()->Get_Quest(i);
//                        std::string t_Type = "Weapon";
//                        std::string t_Weapon_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                        t_Q->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name, t_Weapon_Name);
//                    }
//
//
//
//                    //Account_Data t_AD(t_l, t_p,t_H);
//                    DB.Add_account(*Current_Player);
//                    session = false;
//                    Game = true;
//
//                }
//
//            }
//            break;
//        }
//        case 2:
//        {
//            system("CLS");
//            bool session = true;
//            while (session)
//            {
//                std::string tmp;
//                std::cout << "Podaj login: " << std::endl;
//                std::cin >> tmp;
//                std::string t_l = tmp;
//                std::string t_p;
//                if (DB.Check(tmp))
//                {
//                    t_p = DB.Get_Pass(tmp);
//                    system("CLS");
//                    while (true)
//                    {
//                        std::cout << "Podaj haslo: " << std::endl;
//                        std::cin >> tmp;
//                        if (t_p == tmp)
//                        {
//                            system("CLS");
//                            std::cout << "Haslo poprawne hurra!" << std::endl;
//                            break;
//                        }
//                        else
//                        {
//                            system("CLS");
//                            std::cout << "Hasla nie poprawne!" << std::endl;
//                            std::cout << "Spróbuj ponownie" << std::endl;
//                        }
//                    }
//                    Current_Player = std::shared_ptr<Account_Data>(new Account_Data(DB.Get_AD(t_l, t_p)));
//                    session = false;
//                    Game = true;
//                    //Account_Data t_AD = DB.Get_AD(t_l, t_p);//trzeba kopiujący zrobić
//                }
//                else
//                {
//                    system("CLS");
//                    std::cout << "Zly login! " << std::endl;
//                }
//            }
//
//            break;
//        }
//        case 3:
//        {
//            Play = false;
//            break;
//        }
//        default:
//            /*system("CLS");
//            std::cout << "Wybrales nwm co" << std::endl;
//            ch_chooise = _getch();*/
//            break;
//        }
//        if (Current_Player != nullptr)
//        {
//            if (Current_Player->Get_Lost() && Play)
//            {
//                std::cout << "Oj chyba jesteś juz martwy :)" << std::endl;
//                std::cout << "Kliknij coś!" << std::endl;
//                char tt_ch = _getch();
//                Game = false;
//            }
//        }
//        while (Game)
//        {
//            system("CLS");
//
//            bool b_Hard = Current_Player->Get_Settings()->Get().Hardcore;
//            std::cout << "1. Karczma" << std::endl;
//            std::cout << "2. Kupiec" << std::endl;
//            std::cout << "3. Lochy" << std::endl;
//            std::cout << "4. Postac" << std::endl;
//            std::cout << "5. Ustawienia" << std::endl;
//            std::cout << "6. Wyjdz" << std::endl;
//            char ch_ch = _getch();
//            int ch = ch_ch - 48;
//            //cin >> ch;
//            switch (ch)
//            {
//            case 1:
//            {
//                bool b_Inn = true;
//                bool b_quest_done = false;
//                while (b_Inn)
//                {
//
//
//                    std::shared_ptr<Inn> t_Inn = Current_Player->Get_Inn_status();
//                    /*if (t_Inn == nullptr)
//                    {
//                        t_Inn = std::shared_ptr<Inn>(new Inn());
//                        Current_Player->Set_Inn_status(t_Inn);
//                    }*/
//                    std::shared_ptr<Quest> t_Q1 = t_Inn->Get_First_Quest();
//                    std::shared_ptr<Quest> t_Q2 = t_Inn->Get_Second_Quest();
//                    std::shared_ptr<Quest> t_Q3 = t_Inn->Get_Third_Quest();
//
//
//                    system("CLS");
//                    std::cout << "1. ";
//                    t_Q1->Show_Short_Description();
//                    std::cout << "2. ";
//                    t_Q2->Show_Short_Description();
//                    std::cout << "3. ";
//                    t_Q3->Show_Short_Description();
//                    std::cout << "4. Opusc karczme. " << std::endl;
//                    char ch_ch_inn = _getch();
//                    int ch_inn = ch_ch_inn - 48;
//                    // cin >> ch_inn;
//                    switch (ch_inn)
//                    {
//                    case 1:
//                    {
//                        system("CLS");
//                        bool b_q = true;
//                        while (b_q)
//                        {
//                            std::cout << "Wybrano Q1!" << std::endl;
//                            t_Q1->Show_Description();
//                            std::cout << std::endl;
//                            t_Q1->Get_Opponent()->Show_All();
//                            std::cout << std::endl;
//                            std::cout << "1. Podejmij sie" << std::endl;
//                            std::cout << "2. Odpusc" << std::endl;
//                            char ch_ch_q = _getch();
//                            int ch_q = ch_ch_q - 48;
//                            //cin >> ch_q;
//                            if (ch_q == 1)
//                            {
//                                system("CLS");
//                                //WAlka
//
//                                if (Fight(Current_Player->Get_Hero_status(), t_Q1->Get_Opponent(), Current_Player->Get_Settings()->Get()))
//                                {
//                                    std::cout << std::endl << "Zwycięstwo" << std::endl;
//                                    std::cout << "Zdobyto: " << t_Q1->Get_Expirience() << " doswiadczenia, " << t_Q1->Get_Gold() << " zlota" << std::endl;
//                                    Current_Player->Get_Hero_status()->Increse_Gold(t_Q1->Get_Gold());
//                                    Current_Player->Get_Hero_status()->Increase_Expirience(t_Q1->Get_Expirience());
//                                }
//                                else
//                                {
//
//                                    std::cout << std::endl << "Porazka" << std::endl;
//                                    if (b_Hard)
//                                    {
//                                        std::cout << "Twoja przygoda się zakończyła !" << std::endl;
//                                        Current_Player->Lost();
//                                    }
//                                }
//                                /*pair<std::string, std::string> t_pair = DB.Get_New_Quest();
//                                std::string t_Short_Description = t_pair.first;
//                                std::string t_Description = t_pair.second;
//                                std::string t_Proffesion = Random_Proffesion();
//                                std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
//                                int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                                t_Q1->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name);*/
//                                std::cout << "Powrót -  kliknij przycisk." << std::endl;
//
//                                char t_ch = _getch();
//                                //cin>>ch_q;
//                                b_Inn = false;
//                                b_q = false;
//                                b_quest_done = true;
//                            }
//                            else if (ch_q == 2)
//                            {
//                                system("CLS");
//
//                                b_q = false;
//                            }
//                            else
//                            {
//                                system("CLS");
//                                std::cout << "Cos nie tak z toba :| " << std::endl;
//                                std::cout << std::endl;
//                            }
//                        }
//                        break;
//                    }
//                    case 2:
//                    {
//                        system("CLS");
//                        bool b_q = true;
//                        while (b_q)
//                        {
//                            std::cout << "Wybrano Q2!" << std::endl;
//                            t_Q2->Show_Description();
//                            std::cout << std::endl;
//                            t_Q2->Get_Opponent()->Show_All();
//                            std::cout << std::endl;
//                            std::cout << "1. Podejmij sie" << std::endl;
//                            std::cout << "2. Odpusc" << std::endl;
//                            char ch_ch_q = _getch();
//                            int ch_q = ch_ch_q - 48;
//                            //cin >> ch_q;
//                            if (ch_q == 1)
//                            {
//                                system("CLS");
//                                //WALKA
//                                if (Fight(Current_Player->Get_Hero_status(), t_Q2->Get_Opponent(), Current_Player->Get_Settings()->Get()))
//                                {
//                                    std::cout << std::endl << "Zwycięstwo" << std::endl;
//                                    std::cout << "Zdobyto: " << t_Q2->Get_Expirience() << " doswiadczenia, " << t_Q2->Get_Gold() << " zlota" << std::endl;
//                                    Current_Player->Get_Hero_status()->Increse_Gold(t_Q2->Get_Gold());
//                                    Current_Player->Get_Hero_status()->Increase_Expirience(t_Q2->Get_Expirience());
//                                }
//                                else
//                                {
//
//                                    std::cout << std::endl << "Porazka" << std::endl;
//                                    if (b_Hard)
//                                    {
//                                        std::cout << "Twoja przygoda się zakończyła !" << std::endl;
//                                        Current_Player->Lost();
//                                    }
//                                }
//                                /*pair<std::string, std::string> t_pair = DB.Get_New_Quest();
//                                std::string t_Short_Description = t_pair.first;
//                                std::string t_Description = t_pair.second;
//                                std::string t_Proffesion = Random_Proffesion();
//                                std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
//                                int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                                t_Q2->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name);*/
//                                std::cout << "Powrót -  kliknij przycisk." << std::endl;
//
//                                char t_ch = _getch();
//                                //cin >> ch_q;
//                                b_Inn = false;
//                                b_q = false;
//                                b_quest_done = true;
//                            }
//                            else if (ch_q == 2)
//                            {
//                                system("CLS");
//                                b_q = false;
//                            }
//                            else
//                            {
//                                system("CLS");
//                                std::cout << "Cos nie tak z toba :| " << std::endl;
//                                std::cout << std::endl;
//                            }
//                        }
//                        break;
//                    }
//                    case 3:
//                    {
//                        system("CLS");
//                        bool b_q = true;
//                        while (b_q)
//                        {
//                            std::cout << "Wybrano Q3!" << std::endl;
//                            t_Q3->Show_Description();
//                            std::cout << std::endl;
//                            t_Q3->Get_Opponent()->Show_All();
//                            std::cout << std::endl;
//                            std::cout << "1. Podejmij sie" << std::endl;
//                            std::cout << "2. Odpusc" << std::endl;
//                            char ch_ch_q = _getch();
//                            int ch_q = ch_ch_q - 48;
//                            //cin >> ch_q;
//                            if (ch_q == 1)
//                            {
//                                system("CLS");
//                                //WALKA
//
//                                if (Fight(Current_Player->Get_Hero_status(), t_Q3->Get_Opponent(), Current_Player->Get_Settings()->Get()))
//                                {
//                                    std::cout << std::endl << "Zwycięstwo" << std::endl;
//                                    std::cout << "Zdobyto: " << t_Q3->Get_Expirience() << " doswiadczenia, " << t_Q3->Get_Gold() << " zlota" << std::endl;
//                                    Current_Player->Get_Hero_status()->Increse_Gold(t_Q3->Get_Gold());
//                                    Current_Player->Get_Hero_status()->Increase_Expirience(t_Q3->Get_Expirience());
//                                }
//                                else
//                                {
//                                    std::cout << std::endl << "Porazka" << std::endl;
//                                    if (b_Hard)
//                                    {
//                                        std::cout << "Twoja przygoda się zakończyła !" << std::endl;
//                                        Current_Player->Lost();
//                                    }
//                                }
//                                /* pair<std::string, std::string> t_pair = DB.Get_New_Quest();
//                                 std::string t_Short_Description = t_pair.first;
//                                 std::string t_Description= t_pair.second;
//                                 std::string t_Proffesion = Random_Proffesion();
//                                 std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
//                                 int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                                 t_Q3->Make_New_Quest(t_Short_Description, t_Description, t_Level,t_Proffesion, t_Monster_Name);*/
//                                std::cout << "Powrót -  kliknij przycisk." << std::endl;
//
//                                char t_ch = _getch();
//                                //cin >> ch_q;
//                                b_Inn = false;
//                                b_q = false;
//                                b_quest_done = true;
//                            }
//                            else if (ch_q == 2)
//                            {
//                                system("CLS");
//                                b_q = false;
//                            }
//                            else
//                            {
//                                system("CLS");
//                                std::cout << "Cos nie tak z toba :| " << std::endl;
//                                std::cout << std::endl;
//                            }
//                        }
//                        break;
//                    }
//                    case 4:
//                    {
//                        system("CLS");
//                        std::cout << "Powrot z Karczmy!" << std::endl;
//                        b_Inn = false;
//                        break;
//                    }
//
//                    default:
//                        system("CLS");
//                        std::cout << "Cos poszlo nie tak!" << std::endl;
//                        break;
//                    }
//                }
//                if (b_quest_done == true)
//                {
//                    std::shared_ptr<Merchant> t_Merchant = Current_Player->Get_Merchant_status();
//                    std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
//                    int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//
//                    for (int i = 1; i < 4; i++)
//                    {
//                        std::string t_Type = Random_Type();
//                        std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                        t_Merchant->Add_New_Item(i, t_Level, t_Proffesion, t_Name, t_Type);
//                    }
//                    b_quest_done = false;
//
//                    for (int i = 0; i < 3; i++)
//                    {
//                        std::pair<std::string, std::string> t_pair = DB.Get_New_Quest();
//                        std::string t_Short_Description = t_pair.first;
//                        std::string t_Description = t_pair.second;
//                        t_Proffesion = Random_Proffesion();
//                        std::string t_Monster_Name = DB.Get_New_Monster_Name(t_Proffesion);
//                        std::shared_ptr<Quest> t_Q = Current_Player->Get_Inn_status()->Get_Quest(i);
//                        std::string t_Type = "Weapon";
//                        std::string t_Weapon_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                        t_Q->Make_New_Quest(t_Short_Description, t_Description, t_Level, t_Proffesion, t_Monster_Name, t_Weapon_Name);
//                    }
//                    DB.Save("configfiles2.txt");
//
//                }
//                break;
//            }
//            case 2:
//            {
//                std::shared_ptr<Merchant> t_Merchant = Current_Player->Get_Merchant_status();
//                if (t_Merchant == nullptr)
//                {
//                    t_Merchant = std::shared_ptr<Merchant>(new Merchant());
//                    Current_Player->Set_Merchant_status(t_Merchant);
//                }
//                bool b_m = true;
//                system("CLS");
//                while (b_m)
//                {
//                    t_Merchant->Show_All();
//                    std::cout << std::endl << "Gold: " << Current_Player->Get_Hero_status()->Get_Gold() << std::endl;
//
//                    std::cout << "1. Kup przedmiot" << std::endl;
//                    std::cout << "2. Sprzedaj Przedmiot" << std::endl;
//                    std::cout << "3. Opusc Kupca" << std::endl;
//                    char ch_ch_m = _getch();
//                    int ch_m = ch_ch_m - 48;
//                    //cin >> ch_m;
//                    char ch_ch_p;
//                    int ch_p;
//                    switch (ch_m)
//                    {
//                    case 1:
//
//                        std::cout << "Ktory?" << std::endl;
//                        ch_ch_p = _getch();
//                        ch_p = ch_ch_p - 48;
//                        //cin >> ch_p;
//                        system("CLS");
//                        if (t_Merchant->Buy_Item(ch_p, Current_Player->Get_Hero_status()))
//                        {
//                            std::cout << "Po zakupach" << std::endl;
//                            std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
//                            std::string t_Type = Random_Type();
//                            std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                            int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                            t_Merchant->Add_New_Item(ch_p, t_Level, t_Proffesion, t_Name, t_Type);
//
//                        }
//                        else
//                        {
//                            std::cout << "Nic nie kupiono" << std::endl;
//                        }
//
//
//                        break;
//                    case 2:
//                        Current_Player->Get_Hero_status()->Get_Equipment()->Show_Bag();
//                        std::cout << "Ktory?" << std::endl;
//                        ch_ch_p = _getch();
//                        ch_p = ch_ch_p - 48;
//                        //cin >> ch_p;
//                        system("CLS");
//                        if (t_Merchant->Sell_Item(ch_p, Current_Player->Get_Hero_status()))
//                        {
//
//                            std::cout << "Sprzedano !" << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "Chyba nic tam nie masz !" << std::endl;
//                        }
//
//                        break;
//                    case 3:
//                        system("CLS");
//                        b_m = false;
//                        break;
//                    default:
//                        system("CLS");
//                        std::cout << "Cos poszlo nie tak!" << std::endl;
//                        break;
//                    }
//
//                }
//                break;
//            }
//            case 3:
//            {
//                std::shared_ptr<Dungeon> t_Dungeon = Current_Player->Get_Dungeon_status();
//                bool b_dung = true;
//                system("CLS");
//                while (b_dung)
//                {
//
//                    std::cout << "Pietro: " << t_Dungeon->Get_Floor() << ", Przeciwnik: " << t_Dungeon->Get_Progress() << std::endl;
//                    if (t_Dungeon->Get_Opponent() == nullptr)t_Dungeon->Reset_Oponent(DB.Get_Dungeon_Monster(t_Dungeon->Get_Floor(), t_Dungeon->Get_Progress()));
//                    t_Dungeon->Get_Opponent()->Show_All();
//                    std::cout << std::endl << "1. Podejmij sie" << std::endl;
//                    std::cout << "2. Odpusc" << std::endl;
//                    char t_ch;
//                    char ch_ch_dung = _getch();
//                    int ch_dung = ch_ch_dung - 48;
//                    //cin >> ch_dung;
//                    switch (ch_dung)
//                    {
//                    case 1:
//                        system("CLS");
//                        if (Fight(Current_Player->Get_Hero_status(), t_Dungeon->Get_Opponent(), Current_Player->Get_Settings()->Get()))
//                        {
//                            std::cout << std::endl << "Zwycięstwo" << std::endl;
//
//                            int t_Level = Current_Player->Get_Hero_status()->Get_Level();
//                            int t_expirience = 2 * (t_Level * (200 + rand() % 200));
//                            int t_gold = (rand() % (t_Level)+t_Level + 2) * 2;
//
//                            std::cout << "Zdobyto: " << t_gold << " Golda, " << t_expirience << " Doświadczenia." << std::endl;
//                            Current_Player->Get_Hero_status()->Increse_Gold(t_gold);
//                            Current_Player->Get_Hero_status()->Increase_Expirience(t_expirience);
//                            bool b_suprice = rand() % 2;
//                            if (b_suprice)
//                            {
//                                if (!(Current_Player->Get_Hero_status()->Get_Equipment()->Bag_full()))
//                                {
//                                    std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
//                                    std::string t_Type = Random_Type();
//                                    std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                                    std::shared_ptr<Item> t_ptr;
//                                    if (t_Type == "Weapon")
//                                    {
//                                        t_ptr = std::shared_ptr<Weapon>(new Weapon(t_Proffesion, t_Level, t_Name, 2));
//                                    }
//                                    else
//                                    {
//                                        t_ptr = std::shared_ptr<Armor>(new Armor(t_Proffesion, t_Level, t_Type, t_Name, 3));
//                                    }
//                                    Current_Player->Get_Hero_status()->Get_Equipment()->Add_Item(t_ptr);
//                                    std::cout << "Udało się zdobyć nowy przedmiot: ";
//                                    t_ptr->Show();
//                                    std::cout << std::endl;
//                                }
//                                else
//                                {
//                                    std::cout << "TY IDIOTO NIE MASZ MIEJSCA W PLECAKU HEHE, PRZEPAŁ CI SUPER PRZEDMIOT" << std::endl;
//                                }
//                            }
//
//                            if (t_Dungeon->Get_Floor() == 2 && t_Dungeon->Get_Progress() == 10)
//                            {
//                                t_ch = _getch();
//                                system("CLS");
//                                std::cout << "Wygrałeś HURRRA" << std::endl;
//                                std::cout << "Kliknij, aby kontynuować!" << std::endl;
//                                t_ch = _getch();
//                                b_dung = false;
//                                break;
//                            }
//
//
//                            t_Dungeon->Go_Next();
//                            t_Dungeon->Reset_Oponent(DB.Get_Dungeon_Monster(t_Dungeon->Get_Floor(), t_Dungeon->Get_Progress()));
//
//                            std::shared_ptr<Merchant> t_Merchant = Current_Player->Get_Merchant_status();
//                            std::string t_Proffesion = Current_Player->Get_Hero_status()->Get_Profesion();
//                            t_Level = Current_Player->Get_Hero_status()->Get_Level();
//
//                            for (int i = 1; i < 4; i++)
//                            {
//                                std::string t_Type = Random_Type();
//                                std::string t_Name = DB.Get_New_Item_Name(t_Proffesion, t_Type);
//                                t_Merchant->Add_New_Item(i, t_Level, t_Proffesion, t_Name, t_Type);
//                            }
//                            DB.Save("configfiles2.txt");
//                        }
//                        else
//                        {
//                            std::cout << std::endl << "Porazka" << std::endl;
//                            if (b_Hard)
//                            {
//                                std::cout << "Twoja przygoda się zakończyła !" << std::endl;
//                                Current_Player->Lost();
//                            }
//                        }
//                        std::cout << "Kliknij, aby kontynuować!" << std::endl;
//                        t_ch = _getch();
//                        b_dung = false;
//                        break;
//                    case 2:
//                        b_dung = false;
//                        break;
//                    default:
//                        system("CLS");
//                        break;
//                    }
//
//                }
//
//                break;
//            }
//            case 4:
//            {
//                bool b_h = true;
//                system("CLS");
//                while (b_h)
//                {
//                    std::shared_ptr<Hero> t_Hero = Current_Player->Get_Hero_status();
//                    t_Hero->Show_All();
//
//                    std::cout << "1. Zobacz Ekwipunek" << std::endl;
//                    std::cout << "2. Opusc podglad" << std::endl;
//                    char ch_ch_h = _getch();
//                    int ch_h = ch_ch_h - 48;
//
//                    //cin >> ch_h;
//                    if (ch_h == 1)
//                    {
//                        bool b_e = true;
//                        system("CLS");
//                        while (b_e)
//                        {
//
//                            std::shared_ptr<Equipment> t_Equipment = t_Hero->Get_Equipment();
//                            t_Equipment->Show_Equiped();
//                            t_Equipment->Show_Bag();
//                            std::cout << "1. Ubierz przedmiot" << std::endl;
//                            std::cout << "2. Opusc Ekwipunek" << std::endl;
//                            char ch_ch_e = _getch();
//                            int ch_e = ch_ch_e - 48;
//                            char ch_ch_i;
//                            int ch_i;
//                            //std::string pp = "Mage";
//                            //cin >> ch_e;
//                            switch (ch_e)
//                            {
//                            case 1:
//                                std::cout << "Co ubrac? " << std::endl;
//                                ch_ch_i = _getch();
//                                ch_i = ch_ch_i - 48;
//                                //cin >> ch_i;
//                                if (ch_i <= 6 && ch_i >= 1)
//                                {
//                                    t_Equipment->Equip(ch_i - 1);
//                                }
//                                system("CLS");
//                                break;
//                            case 2:
//                                system("CLS");
//                                b_e = false;
//                                break;
//                            default:
//                                system("CLS");
//                                std::cout << "Cos poszlo nie tak!" << std::endl;
//                                break;
//                            }
//                        }
//
//
//
//                    }
//                    else if (ch_h == 2)
//                    {
//                        system("CLS");
//                        b_h = false;
//                    }
//                    else
//                    {
//                        system("CLS");
//                        std::cout << "Cos poszlo nie tak!" << std::endl;
//                    }
//                }
//
//                break;
//            }
//            case 5:
//            {
//                system("CLS");
//                bool b_s = true;
//                while (b_s)
//                {
//                    bool tmp = Current_Player->Get_Settings()->Get().FastGame;
//
//                    std::cout << "FastGame: ";
//                    if (tmp)std::cout << " wł.";
//                    else std::cout << " wył.";
//                    std::cout << std::endl;
//
//
//                    std::cout << "1. Zmień Fastgame." << std::endl;
//                    std::cout << "2. Opuść" << std::endl;
//                    char ch_tmp_i = _getch();
//                    int tmp_i = ch_tmp_i - 48;
//                    //cin >> tmp_i;
//                    if (tmp_i == 1)
//                    {
//                        system("CLS");
//                        Options t;
//                        t.FastGame = !tmp;
//                        t.Hardcore = Current_Player->Get_Settings()->Get().Hardcore;
//                        Current_Player->Set_Settings(t);
//                    }
//                    else if (tmp_i == 2)
//                    {
//                        system("CLS");
//                        b_s = false;
//                    }
//                    else
//                    {
//                        system("CLS");
//                        std::cout << "Nie ma tego co chesz:)" << std::endl;
//                    }
//
//
//                }
//                break;
//            }
//            case 6:
//            {
//                system("CLS");
//                Game = false;
//                break;
//            }
//            default:
//                system("CLS");
//                std::cout << "Cos nie tak z twoim wyborem!" << std::endl;
//                break;
//            }
//            if (Current_Player->Get_Lost())
//            {
//                system("CLS");
//                std::cout << "!!To juz koniec!!" << std::endl;
//                std::cout << "Kliknij co kolwiek!" << std::endl;
//                char t_ch = _getch();
//                Game = false;
//                DB.Save("configfiles2.txt");
//            }
//        }
//
//    }
//    DB.Save("configfiles2.txt");
//    return 1;
//}
//
