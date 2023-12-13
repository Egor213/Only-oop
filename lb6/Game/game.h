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
#include "../Logs/imessage_subject.h"
#include "../Logs/win_message.h"
#include "../Logs/log_tracker.h"
class LogTracker;

class Game: public Subject, public IMessageSubject
{
public:
    Game(unsigned hp, unsigned atk);
    ~Game();

    void run();
    void setManage(Management *manage);
    
    void addObserver(Observer* apObserver) override;
    void removeObserver(Observer* observer) override;
    void notify(ViewEvent view_event) override;

    void addLogObserver(IMessage* apObserver) override;
    void notifyLog(LogEvent) override;

    Command getLastCommand();

    friend class ViewConsole;
    friend class WinMessage;
    friend class NewGameMessage;
    friend class LoseMessage;
    friend class DontCommandMessage;
    friend class DoCommandMessage;

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
    std::vector<IMessage*> logs_observers;

    char last_key;
    unsigned level;
    void cleanPtr();
    void isEnd();
    void checkCin(unsigned& temp);
    void finishGame();
    unsigned hp;
    unsigned atk;
    void getLvl();

    Command last_command;
};

#endif