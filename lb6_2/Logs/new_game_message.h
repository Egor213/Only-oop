#ifndef new_game_message_h
#define new_game_message_h

#include "imessage.h"

class NewGameMessage : public IMessage
{
public:
    NewGameMessage(unsigned height, unsigned width, unsigned x, unsigned y);
    std::string print();

private:
    std::vector<std::any> stats;

};

#endif