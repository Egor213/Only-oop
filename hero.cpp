#ifndef hero_cpp
#define hero_cpp
#include "hero.h"


bool Hero::check_stat(int stat, int number1, int number2){
    if (stat < number1 || stat > number2)
        return false;
    return true;
}

Hero::Hero(std::string name, unsigned heal_points, unsigned attack, unsigned experience): name(name){
        this->heal_points = check_stat(heal_points, 1, 1001) ? heal_points : ERROR_VALUE;
        this->attack = check_stat(attack, 0, 501) ? attack : ERROR_VALUE;
        this->experience = check_stat(experience, 0, 10001) ? experience : ERROR_VALUE;
    }

void Hero::getInformation(){
    std::cout << name << " - name" << '\n'
              << heal_points << u8"\u2764" << " - heal_points" <<'\n' 
              << attack << u8"\u2694" << " - attack" << '\n'
              << experience << u8"\u2022" << " - experience" << '\n';
}


//getters
unsigned Hero::getEXP(){
    return experience;
}
unsigned Hero::getHP(){
    return heal_points;
}
unsigned Hero::getATK(){
    return attack;
}
std::string Hero::getName(){
    return name;
}


//setters
bool Hero::setHP(unsigned heal_points){
    if (check_stat(heal_points, 1, 1001)){
        this->heal_points = heal_points;
        return true;
    }
    return false;   
}
bool Hero::setATK(unsigned attack){
    if (check_stat(attack, 0, 501)){
        this->attack =  attack;
        return true;
    }
    return false;
}
void Hero::setName(std::string name){
    this->name = name;
}
bool Hero::setEXP(unsigned experience){
    if (check_stat(experience, 0, 10001)){
        this->experience = experience;
        return true;
    }
    return false;
}



#endif