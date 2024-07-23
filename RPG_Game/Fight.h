#ifndef FIGHT_H
#define FIGHT_H
#include "Function.h"
#include "Hero.h"
#include "Monster.h"
#include <queue>
bool Fight(std::shared_ptr<Hero> v_Hero, std::shared_ptr<Monster> v_Monster, Options v_Settings, std::queue<int> & v_hits,bool &v_heroStarts);
#endif 


