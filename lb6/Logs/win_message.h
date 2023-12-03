#ifndef win_message_h
#define win_message_h

#include "imessage.h"
#include "../Game/game.h"
class Game;
class LogTracker;
class WinMessage : public IMessage
{
public:
    WinMessage(Game* game, LogTracker* log_tracker);
    void update(LogEvent) override;
    std::map<LogsEnum, std::any> getData();

private:
    std::map<LogsEnum, std::any> stats;
    Game* game;
    LogTracker* log_tracker;
};

#endif