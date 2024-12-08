#ifndef dont_command_message_h
#define dont_command_message_h

#include "imessage.h"

#include "../Game/game.h"
class Game;
class LogTracker;

class DontCommandMessage : public IMessage
{
public:
    DontCommandMessage(Game* game, LogTracker* log_tracker);
    void update(LogEvent);
    std::map<LogsEnum, std::any> getData();

private:
    std::map<LogsEnum, std::any> stats;
    Game *game;
    LogTracker* log_tracker;
};

#endif