#include "Struct.h"


std::ostream& operator<<(std::ostream& s, Options x)
{
    s << x.FastGame << ";" << x.Hardcore;
    return s;
}
Options Options::Get()
{
    return *this;
}

Statistics Statistics::operator+=(Statistics x)
{
    Strength += x.Strength;
    Dexterity += x.Dexterity;
    Intelligence += x.Intelligence;
    Stamina += x.Stamina;
    Luck += x.Luck;
    return *this;
}
Statistics Statistics::operator=(int x)
{
    Strength = x;
    Dexterity = x;
    Intelligence = x;
    Stamina = x;
    Luck = x;
    return *this;
}
Statistics Statistics::operator+=(int x)
{
    Strength += x;
    Dexterity += x;
    Intelligence += x;
    Stamina += x;
    Luck += x;
    return *this;
}
Statistics Statistics::operator+(Statistics x)
{
    Statistics v;
    v.Strength = this->Strength + x.Strength;
    v.Dexterity = this->Dexterity + x.Dexterity;
    v.Intelligence = this->Intelligence + x.Intelligence;
    v.Stamina = this->Stamina + x.Stamina;
    v.Luck = this->Luck + x.Luck;
    return v;
}
std::ostream& operator<<(std::ostream& s, Statistics& x)
{
    if (x.Strength != 0)s << " Sil: " << x.Strength;
    if (x.Dexterity != 0)s << " Zre: " << x.Dexterity;
    if (x.Intelligence != 0)s << " Int:" << x.Intelligence;
    if (x.Stamina != 0)s << " Wyt: " << x.Stamina;
    if (x.Luck != 0)s << " Szc: " << x.Luck;
    return s;
}