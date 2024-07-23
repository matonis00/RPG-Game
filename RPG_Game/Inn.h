
#ifndef INN_H
#define INN_H
#include "Quest.h"
class Inn
{
    std::shared_ptr<Quest> First_Quest;
    std::shared_ptr<Quest> Second_Quest;
    std::shared_ptr<Quest> Third_Quest;

public:
    Inn();
    Inn(std::shared_ptr<Quest> v_First_Quest, std::shared_ptr<Quest> v_Second_Quest, std::shared_ptr<Quest> v_Third_Quest);
    std::shared_ptr<Quest> Get_First_Quest();
    std::shared_ptr<Quest> Get_Second_Quest();
    std::shared_ptr<Quest> Get_Third_Quest();
    std::shared_ptr<Quest> Get_Quest(int v);
};
#endif