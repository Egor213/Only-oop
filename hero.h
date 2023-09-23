#ifndef hero_h
#define hero_h
#include <string>
#include <iostream>
#define ERROR_VALUE throw std::out_of_range("Недопустимое значение переменной!")

class Hero{


public:
    Hero(std::string name, unsigned heal_points, unsigned mana_capacity, unsigned attack);
    Hero(std::string name, unsigned heal_points, unsigned mana_capacity, unsigned attack, unsigned experience);
    



    void getInformation();


    //getters
    unsigned getHP();
    unsigned getMC();
    unsigned getATK();
    std::string getName();
    unsigned getEXP();
    unsigned getSP();
    

    //setters
    bool setHP(unsigned heal_points);
    bool setMC(unsigned mana_capacity);
    bool setATK(unsigned attack);
    void setName(std::string name);
    bool setEXP(unsigned experience);
    bool setSP(unsigned star_points);


private:
    unsigned experience;
    unsigned star_points;   
    unsigned heal_points;
    unsigned mana_capacity;
    unsigned attack;
    std::string name;
    bool check_stat(int stat, int number1, int number2);
     
};



#endif