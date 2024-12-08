#ifndef game_h
#define game_h
#include "../Field/field.h"
#include "controller.h"
#include "../Managment/management.h"
#include "../Field/generate_field.h"
#include "../Game/view.h"
#include "../Managment/commands.h"
#include <iostream>
//#include "../Managment/user_commands.h"
class Game
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();
    void initGame(bool restart_flag = false);
    void view() const;
    void stepConsole();
    void stepFile();
    bool getFlagFile();
private:
    Field *field;
    Controller *controller;
    Management management;
    Hero *hero;
    std::map<Command, char> key_map;
    std::map<Command, Side> command_map;
    std::vector<Command> arr_commands;
    Command getKeyByValue(const std::map<Command, char> &key_map, const char &value);
    unsigned level;
    bool flag_file;
    void cleanPtr();
    bool isEnd();
    void stepCommand();
    void finishGame();
    unsigned hp;
    unsigned atk;
    int counter_file_command = 0;
};

#endif