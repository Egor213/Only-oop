#ifndef win_message_h
#define win_message_h

#include "imessage.h"
#include "../Game/game.h"
class Game;
class LogTracker;
class WinMessage : public IMessage
{
public:
    WinMessage(int hp, int atk, int exp);
    std::string print();

private:
    std::vector<std::any> stats;

};

#endif