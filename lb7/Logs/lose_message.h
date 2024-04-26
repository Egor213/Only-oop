#ifndef lose_message_h
#define lose_message_h

#include "imessage.h"
#include "../Game/game.h"

class Game;

class LoseMessage : public IMessage
{
public:
    LoseMessage(Game* game, LogTracker* log_tracker);
    void update(LogEvent);
    std::map<LogsEnum, std::any> getData();


private:
    std::map<LogsEnum, std::any> stats;
    Game* game;
    LogTracker* log_tracker;
};
#endif