#include "Data_base.h"
    Data_base::Data_base(std::string v_file)
    {
        std::vector<std::shared_ptr<Item>> UsedItems;
        std::vector<std::shared_ptr<Monster>> UsedMonster;
        std::vector<std::shared_ptr<Quest>> UsedQuest;
        std::vector<std::shared_ptr<Inn>> Inn_Data;
        std::vector<std::shared_ptr<Merchant>> Merchant_Data;
        std::vector<std::shared_ptr<Dungeon>> Dungeon_Data;
        std::vector<std::shared_ptr<Equipment>> Equipment_Data;
        std::vector<std::shared_ptr<Hero>> Hero_Data;
        std::string f_Date, f_Dungeon, f_DungeonBase, f_Equipment, f_ItemBase, f_Hero, f_Inn, f_Merchant, f_UsedItems, f_UsedMonster, f_UsedQuest, f_MonsterBase, f_QuestBase;
        std::ifstream file(v_file);
        if (file.good()) file >> f_Date >> f_Dungeon >> f_DungeonBase >> f_Equipment >> f_ItemBase >> f_Hero >> f_Inn >> f_Merchant >> f_UsedItems >> f_UsedMonster >> f_UsedQuest >> f_MonsterBase >> f_QuestBase;
        else return;
        file.close();
        file.open(f_UsedItems);
        while (file.good())
        {
            std::string t_line = "";
            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                std::string t_Name, t_What, t_Type, v_t_Stats;
                Statistics t_Stats;
                int t_Armor_value, t_Price, t_min_Damage, t_max_Damage, t_tmp;
                std::shared_ptr<Item> t_ptr;


                is >> t_tmp >> t_What >> v_t_Stats;
                is >> t_Name;
                while (t_Name[t_Name.length() - 1] != '"')
                {
                    std::string tmp = "";
                    is >> tmp;
                    t_Name += " " + tmp;
                }
                t_Name.erase(0, 1);
                t_Name.erase(t_Name.length() - 1, t_Name.length());

                is >> t_Price;

                std::vector<int> v_Stats = splitData(v_t_Stats, ';');
                if (v_Stats.size() == 5)
                {
                    t_Stats.Strength = v_Stats[0];
                    t_Stats.Dexterity = v_Stats[1];
                    t_Stats.Intelligence = v_Stats[2];
                    t_Stats.Stamina = v_Stats[3];
                    t_Stats.Luck = v_Stats[4];
                }
                else
                {
                    //Blad ze Statami
                    std::cout << "Zle staty";
                    break;
                }

                if (t_What == "W")
                {
                    is >> t_min_Damage >> t_max_Damage;
                    t_ptr = std::shared_ptr<Weapon>(new Weapon(t_Stats, t_Name, t_Price, t_min_Damage, t_max_Damage));

                }
                else if (t_What == "A")
                {
                    is >> t_Armor_value >> t_Type;
                    t_ptr = std::shared_ptr<Armor>(new Armor(t_Stats, t_Name, t_Price, t_Armor_value, t_Type));
                }
                UsedItems.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_UsedMonster);
        while (file.good())
        {
            std::string t_line = "";
            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                std::string v_t_Stats, t_Race, t_Proffesion, t_Name;
                Statistics t_Stats;
                int t_Armor_Value, t_Level, v_t_ptr, t_tmp;
                is >> t_tmp >> v_t_Stats;

                is >> t_Name;
                while (t_Name[t_Name.length() - 1] != '"')
                {
                    std::string tmp = "";
                    is >> tmp;
                    t_Name += " " + tmp;
                }
                t_Name.erase(0, 1);
                t_Name.erase(t_Name.length() - 1, t_Name.length());


                is >> t_Armor_Value >> t_Level >> t_Race >> t_Proffesion >> v_t_ptr;
                std::vector<int> v_Stats = splitData(v_t_Stats, ';');
                if (v_Stats.size() == 5)
                {
                    t_Stats.Strength = v_Stats[0];
                    t_Stats.Dexterity = v_Stats[1];
                    t_Stats.Intelligence = v_Stats[2];
                    t_Stats.Stamina = v_Stats[3];
                    t_Stats.Luck = v_Stats[4];
                }
                else
                {
                    //Blad ze Statami
                    std::cout << "Zle staty";
                    break;
                }


                std::shared_ptr<Monster> t_ptr;
                std::shared_ptr<Weapon> t_Monster_Weapon = std::dynamic_pointer_cast<Weapon>(UsedItems[v_t_ptr - 1]);
                t_ptr = std::shared_ptr<Monster>(new Monster(t_Stats, t_Armor_Value, t_Name, t_Level, t_Race, t_Proffesion, t_Monster_Weapon));
                UsedMonster.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_UsedQuest);
        while (file.good())
        {
            std::string t_line = "";
            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_tmp, t_Gold, t_Expirience, v_t_ptr;
                std::string t_Description, t_Short_Description;
                std::shared_ptr<Monster> t_Oponent;
                std::shared_ptr<Quest> t_ptr;
                is >> t_tmp;

                is >> t_Short_Description;
                while (t_Short_Description[t_Short_Description.length() - 1] != '"')
                {
                    std::string tmp = "";
                    is >> tmp;
                    t_Short_Description += " " + tmp;
                }
                t_Short_Description.erase(0, 1);
                t_Short_Description.erase(t_Short_Description.length() - 1, t_Short_Description.length());
                is >> t_Description;
                while (t_Description[t_Description.length() - 1] != '"')
                {
                    std::string tmp = "";
                    is >> tmp;
                    //if(t_Description[t_Description.length() - 1]  == 'n' && t_Description[t_Description.length() - 2] == '\\')t_Description += "\n " + tmp;
                     t_Description += " " + tmp;
                }
                t_Description.erase(0, 1);
                t_Description.erase(t_Description.length() - 1, t_Description.length());
                is >> t_Expirience >> t_Gold >> v_t_ptr;
                t_Oponent = UsedMonster[v_t_ptr - 1];
                t_ptr = std::shared_ptr<Quest>(new Quest(t_Short_Description, t_Description, t_Expirience, t_Gold, t_Oponent));
                UsedQuest.push_back(t_ptr);

            }
        }
        file.close();
        file.open(f_Inn);
        while (file.good())
        {
            std::string t_line = "";
            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_Q1, t_Q2, t_Q3, t_tmp;
                is >> t_tmp >> t_Q1 >> t_Q2 >> t_Q3;
                std::shared_ptr<Quest> t_ptr1, t_ptr2, t_ptr3;
                t_ptr1 = UsedQuest[t_Q1 - 1];
                t_ptr2 = UsedQuest[t_Q2 - 1];
                t_ptr3 = UsedQuest[t_Q3 - 1];
                std::shared_ptr<Inn> t_ptr = std::shared_ptr<Inn>(new Inn(t_ptr1, t_ptr2, t_ptr3));
                Inn_Data.push_back(t_ptr);

            }
        }
        file.close();
        file.open(f_Merchant);
        while (file.good())
        {
            std::string t_line = "";
            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_tmp, t_I1, t_I2, t_I3;
                std::shared_ptr<Item>  t_ptr1, t_ptr2, t_ptr3;
                std::shared_ptr<Merchant> t_ptr;
                is >> t_tmp >> t_I1 >> t_I2 >> t_I3;
                t_ptr1 = UsedItems[t_I1 - 1];
                t_ptr2 = UsedItems[t_I2 - 1];
                t_ptr3 = UsedItems[t_I3 - 1];
                t_ptr = std::shared_ptr<Merchant>(new Merchant(t_ptr1, t_ptr2, t_ptr3));
                Merchant_Data.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_DungeonBase);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                std::vector <std::shared_ptr<Monster>> t_vec;
                std::string  t_Race, t_Proffesion, v_t_Stats, t_Name;
                int v_t_ptrM, t_tmp1, t_tmp2, t_Armor_Value, t_Level, v_t_ptr;
                Statistics t_Stats;
                is >> t_tmp1 >> t_tmp2 >> v_t_Stats;
                is >> t_Name;
                while (t_Name[t_Name.length() - 1] != '"')
                {
                    std::string tmp = "";
                    is >> tmp;
                    t_Name += " " + tmp;
                }
                t_Name.erase(0, 1);
                t_Name.erase(t_Name.length() - 1, t_Name.length());
                is >> t_Armor_Value >> t_Level >> t_Race >> t_Proffesion >> v_t_ptr;
                std::vector<int> v_Stats = splitData(v_t_Stats, ';');
                if (v_Stats.size() == 5)
                {
                    t_Stats.Strength = v_Stats[0];
                    t_Stats.Dexterity = v_Stats[1];
                    t_Stats.Intelligence = v_Stats[2];
                    t_Stats.Stamina = v_Stats[3];
                    t_Stats.Luck = v_Stats[4];
                }
                else
                {
                    //Blad ze Statami
                    std::cout << "Zle staty";
                    break;
                }
                std::shared_ptr<Weapon> t_Monster_Weapon = std::dynamic_pointer_cast<Weapon>(UsedItems[v_t_ptr - 1]);
                std::shared_ptr<Monster> t_ptr;
                t_ptr = std::shared_ptr<Monster>(new Monster(t_Stats, t_Armor_Value, t_Name, t_Level, t_Race, t_Proffesion, t_Monster_Weapon));
                if (t_tmp2 == 1)
                {
                    DungeonsBase.push_back(t_vec);
                }
                DungeonsBase[t_tmp1 - 1].push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_Equipment);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_tmp, t_Weapon, t_Helm, t_Armor, t_Gloves;
                std::string v_t_Bag;
                is >> t_tmp >> v_t_Bag >> t_Weapon >> t_Helm >> t_Armor >> t_Gloves;
                std::vector<int> v_Bag = splitData(v_t_Bag, ';');
                std::vector<std::shared_ptr<Item>> t_Bag;
                for (int& x : v_Bag)
                {
                    std::shared_ptr<Item> t_ptrI;
                    if (x != 0)t_ptrI = UsedItems[x - 1];
                    else t_ptrI = nullptr;
                    t_Bag.push_back(t_ptrI);
                }
                std::shared_ptr<Weapon> t_ptrW = std::dynamic_pointer_cast<Weapon>(UsedItems[t_Weapon - 1]);
                std::shared_ptr<Armor> t_ptrH = std::dynamic_pointer_cast<Armor>(UsedItems[t_Helm - 1]);
                std::shared_ptr<Armor> t_ptrA = std::dynamic_pointer_cast<Armor>(UsedItems[t_Armor - 1]);
                std::shared_ptr<Armor> t_ptrG = std::dynamic_pointer_cast<Armor>(UsedItems[t_Gloves - 1]);
                std::shared_ptr<Equipment> t_ptr = std::shared_ptr<Equipment>(new Equipment(t_Bag, t_ptrW, t_ptrH, t_ptrA, t_ptrG));
                Equipment_Data.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_Hero);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_tmp, t_Armor_Value, t_Level, v_t_ptrE, t_Gold, t_Expirience;
                std::string v_t_Stats, t_Race, t_Proffesion;
                Statistics t_Stats;
                is >> t_tmp >> v_t_Stats >> t_Armor_Value >> t_Level >> t_Race >> t_Proffesion >> t_Gold >> t_Expirience >> v_t_ptrE;
                std::vector<int> v_Stats = splitData(v_t_Stats, ';');
                if (v_Stats.size() == 5)
                {
                    t_Stats.Strength = v_Stats[0];
                    t_Stats.Dexterity = v_Stats[1];
                    t_Stats.Intelligence = v_Stats[2];
                    t_Stats.Stamina = v_Stats[3];
                    t_Stats.Luck = v_Stats[4];
                }
                else
                {
                    //Blad ze Statami
                    std::cout << "Zle staty";
                    break;
                }
                std::shared_ptr<Equipment> t_ptrE = Equipment_Data[v_t_ptrE - 1];
                std::shared_ptr<Hero> t_ptr = std::shared_ptr<Hero>(new Hero(t_Stats, t_Armor_Value, t_Level, t_Race, t_Proffesion, t_ptrE, t_Gold, t_Expirience));
                Hero_Data.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_Dungeon);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                int t_tmp, t_Floor, t_Progress;
                is >> t_tmp >> t_Floor >> t_Progress;
                std::shared_ptr<Monster> t_Oponent = DungeonsBase[t_Floor - 1][t_Progress - 1];
                std::shared_ptr<Dungeon> t_ptr = std::shared_ptr<Dungeon>(new Dungeon(t_Floor, t_Progress, t_Oponent));
                Dungeon_Data.push_back(t_ptr);
            }
        }
        file.close();
        file.open(f_MonsterBase);
        std::string t_Proffesion_MB;
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                if (t_line == "Mage:") t_Proffesion_MB = "Mage";
                else if (t_line == "Warrior:") t_Proffesion_MB = "Warrior";
                else if (t_line == "Hunter:") t_Proffesion_MB = "Hunter";
                else
                {
                    MonsterBase[t_Proffesion_MB].push_back(t_line);
                }
            }
        }
        file.close();
        bool t_Description = true;
        std::pair<std::string, std::string> t_pair;
        file.open(f_QuestBase);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                if (t_line == "SH:")
                {
                    if (t_Description == false) QuestBase.push_back(t_pair);
                    t_pair.first = "";
                    t_pair.second = "";
                    t_Description = true;
                }
                else if (t_line == "D:")t_Description = false;
                else
                {
                    if (t_Description)
                    {
                        t_pair.first += (t_line + " ");
                    }
                    else
                    {
                        t_pair.second += (t_line + "$n ");
                    }
                }


            }
        }
        file.close();
        file.open(f_ItemBase);
        std::string t_Proffesion_IB, t_Type_IB;
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                if (t_line == "Mage:") t_Proffesion_IB = "Mage";
                else if (t_line == "Warrior:") t_Proffesion_IB = "Warrior";
                else if (t_line == "Hunter:") t_Proffesion_IB = "Hunter";
                else if (t_line == "Weapon:") t_Type_IB = "Weapon";
                else if (t_line == "Helm:")t_Type_IB = "Helm";
                else if (t_line == "Armor:")t_Type_IB = "Armor";
                else if (t_line == "Gloves:")t_Type_IB = "Gloves";
                else ItemBase[t_Proffesion_IB][t_Type_IB].push_back(t_line);
            }
        }
        file.close();
        file.open(f_Date);
        while (file.good())
        {
            std::string t_line = "";

            getline(file, t_line);
            if (t_line == "")
            {
                if (file.good())continue;
                else break;
            }
            else
            {
                std::istringstream is(t_line);
                std::string t_Login, t_Password, v_t_Options;
                int t_tmp, t_ptrHero, t_ptrInn, t_ptrMerchant, t_ptrDungeon;
                bool t_lost;
                is >> t_tmp >> t_Login >> t_Password >> v_t_Options >> t_ptrHero >> t_ptrInn >> t_ptrMerchant >> t_ptrDungeon >> t_lost;
                std::vector<int> v_Options = splitData(v_t_Options, ';');
                Options t_Options;
                t_Options.FastGame = v_Options[0];
                t_Options.Hardcore = v_Options[1];
                std::shared_ptr<Options> tt_Options = std::shared_ptr<Options>(new Options(t_Options));

                std::shared_ptr<Hero> t_Hero_Status = Hero_Data[t_ptrHero - 1];
                std::shared_ptr<Inn> t_Inn_Status = Inn_Data[t_ptrInn - 1];
                std::shared_ptr<Merchant> t_Merchant_Status = Merchant_Data[t_ptrMerchant - 1];
                std::shared_ptr<Dungeon> t_Dungeon_Status = Dungeon_Data[t_ptrDungeon - 1];
                Account_Data t_AD(t_Login, t_Password, tt_Options, t_Hero_Status, t_Inn_Status, t_Merchant_Status, t_Dungeon_Status, t_lost);
                Data.push_back(t_AD);
            }
        }
        file.close();
    };
    bool Data_base::Check(std::string& t_login)
    {
        for (int i = 0; i < Data.size(); i++)
        {
            if (Data[i].Get_login() == t_login)return true;
        }
        return false;
    }
    std::string Data_base::Get_Pass(std::string& t_login)
    {
        for (int i = 0; i < Data.size(); i++)
        {
            if (Data[i].Get_login() == t_login)return Data[i].Get_Password();
        }
        return "";
    }
    std::shared_ptr<Account_Data> Data_base::Get_AD(std::string& t_login, std::string& t_password)
    {
        for (int i = 0; i < Data.size(); i++)
        {
            if (Data[i].Get_login() == t_login && Data[i].Get_Password() == t_password)return  std::make_shared<Account_Data>(Data[i]);
        }
        
        Account_Data tmp;
        return std::make_shared<Account_Data>(tmp);
    }
    void Data_base::Add_account(Account_Data& t_AD)
    {
        Data.push_back(t_AD);
    }
    std::string Data_base::Get_New_Item_Name(std::string& v_Proffesion, std::string& v_Type)
    {
        //srand(time(NULL));
        int t_rand = rand() % ItemBase[v_Proffesion][v_Type].size();
        return ItemBase[v_Proffesion][v_Type][t_rand];
    }
    std::string Data_base::Get_New_Monster_Name(std::string& v_Proffesion)
    {
        //srand(time(NULL));
        int t_rand = rand() % MonsterBase[v_Proffesion].size();
        return MonsterBase[v_Proffesion][t_rand];
    }
    std::pair<std::string, std::string> Data_base::Get_New_Quest()
    {
        //srand(time(NULL));
        int t_tmp = rand() % QuestBase.size();
        return QuestBase[t_tmp];
    }
    std::shared_ptr<Monster> Data_base::Get_Dungeon_Monster(int v_Floor, int v_Progress)
    {
        return DungeonsBase[v_Floor - 1][v_Progress - 1];
    }
    void Data_base::Save(std::string v_file)
    {
        std::string f_Date, f_Dungeon, f_DungeonBase, f_Equipment, f_ItemBase, f_Hero, f_Inn, f_Merchant, f_UsedItems, f_UsedMonster, f_UsedQuest, f_MonsterBase, f_QuestBase;
        std::ifstream file(v_file);
        if (file.good()) file >> f_Date >> f_Dungeon >> f_DungeonBase >> f_Equipment >> f_ItemBase >> f_Hero >> f_Inn >> f_Merchant >> f_UsedItems >> f_UsedMonster >> f_UsedQuest >> f_MonsterBase >> f_QuestBase;
        else return;
        std::ofstream output_UI(f_UsedItems);
        std::ofstream output_UM(f_UsedMonster);
        std::ofstream output_UQ(f_UsedQuest);
        std::ofstream output_Inn(f_Inn);
        std::ofstream output_Data(f_Date);
        std::ofstream output_Hero(f_Hero);
        std::ofstream output_Equipment(f_Equipment);
        std::ofstream output_Merchant(f_Merchant);
        std::ofstream output_Dungeon(f_Dungeon);
        if (output_Data.good())
        {
            int t_UsedMonster_number = 1;
            int t_UsedItem_Number = 1;
            int t_UsedQuest_Number = 1;
            int t_Inn_Number = 1;
            int t_Hero_Number = 1;
            for (int i = 0; i < DungeonsBase.size(); i++)
            {
                for (int j = 0; j < DungeonsBase[i].size(); j++)
                {
                    std::shared_ptr<Weapon> t_ptr_W = DungeonsBase[i][j]->Get_Weapon();
                    output_UI << t_UsedItem_Number << " W " << t_ptr_W->Get() << std::endl;
                    t_UsedItem_Number++;
                }
            }

            for (int x = 0; x < Data.size(); x++)
            {
                Account_Data t_AD = Data[x];
                output_Data << std::to_string(x + 1) << " " << t_AD.Get_login() << " " << t_AD.Get_Password() << " " << t_AD.Get_Settings()->Get();

                std::shared_ptr<Hero> t_ptr_H = t_AD.Get_Hero_status();
                output_Hero << t_Hero_Number << " " << t_ptr_H->Get() << " " << t_Hero_Number << std::endl;

                std::shared_ptr<Equipment> t_ptr_Eq = t_ptr_H->Get_Equipment();
                output_Equipment << t_Hero_Number << " ";
                bool b_i_exist = true;
                for (int y = 0; y < 6; y++)
                {
                    std::shared_ptr<Item> t_ptr_I = t_ptr_Eq->Get_Item(y);
                    if (t_ptr_I == nullptr)b_i_exist = false;
                    else
                    {
                        b_i_exist = true;
                        std::string t_Type = t_ptr_I->Get_Type();
                        if (t_Type == "Weapon")
                        {
                            std::shared_ptr<Weapon> t_ptr_W = std::dynamic_pointer_cast<Weapon>(t_ptr_I);
                            output_UI << t_UsedItem_Number << " W " << t_ptr_W->Get() << std::endl;
                        }
                        else
                        {
                            std::shared_ptr<Armor> t_ptr_A = std::dynamic_pointer_cast<Armor>(t_ptr_I);
                            output_UI << t_UsedItem_Number << " A " << t_ptr_A->Get() << std::endl;
                        }
                    }

                    if (b_i_exist)
                    {
                        output_Equipment << t_UsedItem_Number;
                        t_UsedItem_Number++;
                    }
                    else output_Equipment << "0";

                    if (y != 5)output_Equipment << ";";
                }

                std::shared_ptr<Weapon> t_ptr_W = t_ptr_Eq->Get_Weapon();
                output_UI << t_UsedItem_Number << " W " << t_ptr_W->Get() << std::endl;
                output_Equipment << " " << t_UsedItem_Number;
                t_UsedItem_Number++;
                for (int y = 0; y < 3; y++)
                {
                    std::shared_ptr<Armor> t_ptr_A = t_ptr_Eq->Get_Armor(y);
                    output_UI << t_UsedItem_Number << " A " << t_ptr_A->Get() << std::endl;
                    output_Equipment << " " << t_UsedItem_Number;
                    t_UsedItem_Number++;
                }
                output_Equipment << std::endl;

                output_Data << " " << t_Hero_Number;

                std::shared_ptr<Inn> t_ptr_Inn = t_AD.Get_Inn_status();
                output_Inn << t_Hero_Number;
                for (int j = 0; j < 3; j++)
                {
                    std::shared_ptr<Quest> t_ptr_Q = t_ptr_Inn->Get_Quest(j);
                    std::shared_ptr<Monster> t_ptr_M = t_ptr_Q->Get_Opponent();
                    std::shared_ptr<Weapon> t_ptr_W = t_ptr_M->Get_Weapon();
                    output_UI << t_UsedItem_Number << " W " << t_ptr_W->Get() << std::endl;
                    output_UM << t_UsedMonster_number << " " << t_ptr_M->Get() << " " << t_UsedItem_Number << std::endl;
                    output_UQ << t_UsedQuest_Number << " \"" << t_ptr_Q->Get_Short_Description() << "\" \"" << t_ptr_Q->Get_Description() << "\" " << std::to_string(t_ptr_Q->Get_Expirience()) << " " << std::to_string(t_ptr_Q->Get_Gold()) << " " << t_UsedMonster_number << std::endl;
                    output_Inn << " " << t_UsedQuest_Number;
                    t_UsedItem_Number++;
                    t_UsedMonster_number++;
                    t_UsedQuest_Number++;
                }
                output_Inn << std::endl;

                output_Data << " " << t_Hero_Number;

                std::shared_ptr<Merchant> t_ptr_Merchant = t_AD.Get_Merchant_status();
                output_Merchant << t_Hero_Number;
                for (int j = 0; j < 3; j++)
                {
                    std::shared_ptr<Item> t_ptr_I = t_ptr_Merchant->Get_Item(j);
                    std::string t_Type = t_ptr_I->Get_Type();
                    if (t_Type == "Weapon")
                    {
                        std::shared_ptr<Weapon> t_ptr_W = std::dynamic_pointer_cast<Weapon>(t_ptr_I);
                        output_UI << t_UsedItem_Number << " W " << t_ptr_W->Get() << std::endl;
                    }
                    else
                    {
                        std::shared_ptr<Armor> t_ptr_A = std::dynamic_pointer_cast<Armor>(t_ptr_I);
                        output_UI << t_UsedItem_Number << " A " << t_ptr_A->Get() << std::endl;
                    }
                    output_Merchant << " " << t_UsedItem_Number;
                    t_UsedItem_Number++;
                }
                output_Merchant << std::endl;

                output_Data << " " << t_Hero_Number;

                std::shared_ptr<Dungeon> t_ptr_Dungeon = t_AD.Get_Dungeon_status();
                output_Dungeon << t_Hero_Number << " " << t_ptr_Dungeon->Get_Floor() << " " << t_ptr_Dungeon->Get_Progress() << std::endl;
                output_Data << " " << t_Hero_Number << " " << t_AD.Get_Lost() << std::endl;
                t_Hero_Number++;
            }
        }
        output_UI.close();
        output_UM.close();
        output_UQ.close();
        output_Inn.close();
        output_Data.close();
        output_Hero.close();
        output_Equipment.close();
        output_Merchant.close();
        output_Dungeon.close();
    }
