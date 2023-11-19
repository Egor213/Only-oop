#ifndef game_h
#define game_h
#include "../Field/field.h"
#include "controller.h"
#include "../Field/generate_field.h"
#include "../Game/view.h"
#include "../Managment/commands.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../Managment/management.h"

class Game
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();

    void run();
    void setManage(Management *manage);
    

private:
    void initGame();
    void stepCommand();

    Field *field;
    Controller *controller;
    Management* manage;
    Hero *hero;
    GenField *create;


    unsigned level;

    void cleanPtr();
    void isEnd();
    void checkCin(unsigned temp);
    void finishGame();
    unsigned hp;
    unsigned atk;

    void getLvl();
};

#endif