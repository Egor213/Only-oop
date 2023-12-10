#ifndef dont_command_message_h
#define dont_command_message_h

#include "imessage.h"

#include "../Game/game.h"
class Game;
class LogTracker;

class DontCommandMessage : public IMessage
{
public:
    DontCommandMessage(char last_key);
    std::string print();

private:
    std::vector<std::any> stats;
};

#endif