#ifndef hero_cpp
#define hero_cpp
#include "hero.h"

Hero::Hero(int heal_points, int attack, int experience)
{
    this->heal_points = std::clamp(heal_points, 1, 1000);
    this->attack = std::clamp(attack, 1, 500);
    this->experience = std::clamp(experience, 0, 10000);
}

unsigned Hero::getStat(Stat stat) const
{
    unsigned step = 0;
    switch (stat)
    {
    case HP:
        step = heal_points;
        break;
    case ATK:
        step = attack;
        break;
    case EXP:
        step = experience;
        break;
    }
    return step;
}

void Hero::setStat(Stat stat, int value)
{
    switch (stat)
    {
    case HP:
        this->heal_points = std::clamp(value, 0, 1000);
        break;
    case ATK:
        this->attack = std::clamp(value, 0, 500);
        break;
    case EXP:
        this->experience = std::clamp(value, 0, 10000);
        break;
    }
}

#endif