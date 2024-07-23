
#ifndef FUNCTION_H
#define FUNCTION_H
#include "Struct.h"
std::string Random_Type();
std::string Random_Proffesion();
std::string Random_Race();
std::string Connect_Stats(Statistics v_Stats);
std::vector<int> splitData(const std::string& s, char t_char);
void clearQueue(std::queue<int>& q);
#endif
