#ifndef game_h
#define game_h
#include "../Field/field.h"
#include "controller.h"
#include "../Managment/management.h"
#include "../Field/generate_field.h"
#include "../Game/view.h"
#include "../Managment/commands.h"
#include <iostream>
#include <chrono>
#include <thread>

class Game
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();
    void initGame();
    void view() const; //удалится
    void stepFile();
    void run();
    void setManagement(Management *management);
    void stepCommand();

private:
    Field *field;
    Controller *controller;
    Management *management;
    Hero *hero;
    GenField *create;
    std::map<Command, char> key_map;
    std::map<Command, Side> command_map;
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
    void getLvlFile();
};

#endif