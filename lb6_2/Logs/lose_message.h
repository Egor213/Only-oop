#ifndef lose_message_h
#define lose_message_h

#include "imessage.h"
#include "../Game/game.h"

class Game;

class LoseMessage : public IMessage
{
public:
    LoseMessage(unsigned x, unsigned y);
    std::string print();


private:
    std::vector<std::any> stats;
};
#endif