#ifndef game_h
#define game_h
#include "../Field/field.h"
#include "controller.h"
#include "../Field/generate_field.h"
#include "../Managment/commands.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../Managment/management.h"
#include "../View/subject.h"
#include "../View/view_console.h"
class Game: public Subject
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();

    void run();
    void setManage(Management *manage);
    
    void addObserver(Observer* apObserver) override;
    void removeObserver(Observer* observer) override;
    void notify(ViewEvent view_event) override;

    friend class ViewConsole;

private:
    void initGame();
    void stepCommand();

    Field *field;
    Controller *controller;
    Management* manage;
    Hero *hero;
    GenField *create;

    std::vector<Observer*> observers;

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