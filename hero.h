#ifndef hero_h
#define hero_h
#include <string>
#include <iostream>
#include <algorithm>
class Hero
{

public:
    Hero() = default;
    Hero(std::string name, int heal_points, int attack, int experience = 0);
    unsigned getHP() const;
    unsigned getATK() const;
    std::string getName() const;
    unsigned getEXP() const;
    void setHP(int);
    void setATK(int);
    void setName(std::string name);
    void setEXP(int);

private:
    unsigned experience;
    unsigned heal_points;
    unsigned attack;
    std::string name;
};

#endif