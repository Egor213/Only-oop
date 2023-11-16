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
#include "../Managment/console_read.h"
class Game
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();

    void run();
    void setManage(ISetManagement *manage);
    

private:
    void initGame();
    void stepCommand();

    Field *field;
    Controller *controller;
    ISetManagement *manage;
    ICommandRead *reader;
    Hero *hero;
    GenField *create;

    std::map<Command, char> bind_command_map;
    std::vector<Command> arr_commands;
    unsigned level;
    bool flag_file;
    void cleanPtr();
    void isEnd();
    void checkCin(unsigned temp);
    void finishGame();
    unsigned hp;
    unsigned atk;
    int counter_file_command;
    void getLvl();
};

#endif