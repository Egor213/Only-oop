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
    DoCommandMessage(char last_key, Command last_command);
    std::string print();

private:
    std::vector<std::any> stats;
};

#endif