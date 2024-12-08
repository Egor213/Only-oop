#ifndef do_command_message_h
#define do_command_message_h

#include "imessage.h"

#include "../Game/game.h"
#include "../Managment/commands.h"
class Game;
class LogTracker;

class DoCommandMessage : public IMessage
{
public:
    DoCommandMessage(Game* game, LogTracker* log_tracker);
    void update(LogEvent);
    std::map<LogsEnum, std::any> getData();

private:
    std::map<LogsEnum, std::any> stats;
    Game *game;
    LogTracker* log_tracker;
};

#endif