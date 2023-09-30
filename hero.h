#ifndef hero_h
#define hero_h
#include <string>
#include <iostream>
#define ERROR_VALUE throw std::out_of_range("Недопустимое значение переменной!")

class Hero{


public:
    Hero() = default;
    Hero(std::string name, unsigned heal_points, unsigned attack, unsigned experience = 0);
    



    void getInformation();


    //getters
    unsigned getHP();
    unsigned getATK();
    std::string getName();
    unsigned getEXP();
  
    

    //setters
    bool setHP(unsigned);
    bool setATK(unsigned);
    void setName(std::string name);
    bool setEXP(unsigned);


private:
    unsigned experience; 
    unsigned heal_points;
    unsigned attack;
    std::string name;
    bool check_stat(int stat, int number1, int number2);
     
};



#endif