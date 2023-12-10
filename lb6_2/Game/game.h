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
#include "../Logs/imessage.h"
#include "../Logs/win_message.h"
#include "../Logs/log_tracker.h"
#include "../Logs/new_game_message.h"
#include "../Logs/lose_message.h"
#include "../Logs/dont_command_message.h"
#include "../Logs/do_command_message.h"
class LogTracker;

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
    bool game_flag;
    Field *field;
    Controller *controller;
    Management* manage;
    Hero *hero;
    GenField *create;


    LogTracker* log_tracker;
    std::vector<Observer*> observers;

    char last_key;
    unsigned level;
    void cleanPtr();
    void isEnd();
    void checkCin(unsigned& temp);
    void finishGame();
    unsigned hp;
    unsigned atk;
    void getLvl();
};

#endif