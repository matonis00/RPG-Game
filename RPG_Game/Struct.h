
#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include  <memory>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <map>
#include<windows.h>
#include<locale.h>
#include <conio.h>
#include <queue>

struct Options
{
    bool FastGame;
    bool Hardcore;
    friend std::ostream& operator<<(std::ostream& s, Options x);
    Options Get();
};

struct Statistics
{
    int Strength = 0;
    int Dexterity = 0;
    int Intelligence = 0;
    int Stamina = 0;
    int Luck = 0;

    Statistics operator+=(Statistics x);
    Statistics operator=(int x);
    Statistics operator+=(int x);
    Statistics operator+(Statistics x);
    friend std::ostream& operator<<(std::ostream& s, Statistics& x);
};

#endif
