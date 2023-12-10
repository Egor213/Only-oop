#include "lose_message.h"

LoseMessage::LoseMessage(unsigned x, unsigned y)
{
    stats = {x, y};
}

std::string LoseMessage::print()
{
    std::string temp = "LoseX: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[0]));
    temp += " LoseY: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[1]));
    return temp;
}