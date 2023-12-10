#include "new_game_message.h"

NewGameMessage::NewGameMessage(unsigned height, unsigned width, unsigned x, unsigned y)
{
    stats = {height, width, x, y};
}

std::string NewGameMessage::print()
{
    std::string temp = "Height: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[0]));
    temp += " Width: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[1]));
    temp += " StartX: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[2]));
    temp += " StartY: ";
    temp += std::to_string(std::any_cast<unsigned>(stats[3]));
    return temp;
}