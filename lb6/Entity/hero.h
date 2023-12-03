#ifndef hero_h
#define hero_h
#include <string>
#include <iostream>
#include <algorithm>
#include "../Game/direction.h"
class Hero
{

public:
    Hero() = default;
    Hero(int heal_points, int attack, int experience = 0);
    unsigned getStat(Stat stat) const;
    void setStat(Stat stat, int value);

private:
    unsigned experience;
    unsigned heal_points;
    unsigned attack;
};

#endif