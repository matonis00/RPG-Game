#include "Inn.h"
Inn::Inn()
{
    First_Quest = std::shared_ptr<Quest>(new Quest());
    Second_Quest = std::shared_ptr<Quest>(new Quest());
    Third_Quest = std::shared_ptr<Quest>(new Quest());
}
Inn::Inn(std::shared_ptr<Quest> v_First_Quest, std::shared_ptr<Quest> v_Second_Quest, std::shared_ptr<Quest> v_Third_Quest) :First_Quest(v_First_Quest), Second_Quest(v_Second_Quest), Third_Quest(v_Third_Quest)
{
}

std::shared_ptr<Quest> Inn::Get_First_Quest()
{
    return First_Quest;
}
std::shared_ptr<Quest> Inn::Get_Second_Quest()
{
    return Second_Quest;
}
std::shared_ptr<Quest> Inn::Get_Third_Quest()
{
    return Third_Quest;
}
std::shared_ptr<Quest> Inn::Get_Quest(int v)
{
    if (v == 0)return First_Quest;
    else if (v == 1)return Second_Quest;
    else if (v == 2)return Third_Quest;
    else return nullptr;
}
