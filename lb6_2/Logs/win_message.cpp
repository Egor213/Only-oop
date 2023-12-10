#include "win_message.h"

WinMessage::WinMessage(int hp, int atk, int exp)
{
    stats = {hp, atk, exp};
}

std::string WinMessage::print()
{
    std::string temp = "HP: ";
    temp += std::to_string(std::any_cast<int>(stats[0]));
    temp += " ATK: ";
    temp += std::to_string(std::any_cast<int>(stats[1]));
    temp += " EXP: ";
    temp += std::to_string(std::any_cast<int>(stats[2]));
    return temp;
}