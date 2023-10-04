#ifndef hero_cpp
#define hero_cpp
#include "hero.h"

Hero::Hero(std::string name, int heal_points, int attack, int experience) : name(name)
{
    this->heal_points = std::clamp(heal_points, 1, 1000);
    this->attack = std::clamp(attack, 1, 500);
    this->experience = std::clamp(experience, 0, 10000);
}


unsigned Hero::getEXP() const
{
    return experience;
}
unsigned Hero::getHP() const
{
    return heal_points;
}
unsigned Hero::getATK() const
{
    return attack;
}
std::string Hero::getName() const
{
    return name;
}

// setters
void Hero::setHP(int heal_points)
{
    this->heal_points = std::clamp(heal_points, 0, 1000);
}
void Hero::setATK(int attack)
{
    this->attack = std::clamp(attack, 0, 500);
}
void Hero::setName(std::string name)
{
    this->name = name;
}
void Hero::setEXP(int experience)
{
    this->experience = std::clamp(experience, 0, 10000);
}

#endif