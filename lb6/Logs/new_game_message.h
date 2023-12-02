#ifndef new_game_message_h
#define new_game_message_h

#include "imessage.h"

#include "../Game/game.h"
class Game;
class LogTracker;

class NewGameMessage : public IMessage
{
public:
    NewGameMessage(Game* game, LogTracker* log_tracker);
    void update(LogEvent);
    std::map<LogsEnum, std::any> getData();

private:
    std::map<LogsEnum, std::any> stats;
    Game* game;
    LogTracker* log_tracker;
};

#endif