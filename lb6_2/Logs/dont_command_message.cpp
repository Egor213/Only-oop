#include "dont_command_message.h"

DontCommandMessage::DontCommandMessage(char last_key)
{
    stats = {last_key};
}

std::string DontCommandMessage::print()
{
    std::map<Command, std::string> convert_command = {
        {Command::MoveLeft, "MoveLeft"},
        {Command::MoveDown, "MoveDown"},
        {Command::MoveRight, "MoveRight"},
        {Command::MoveUp, "MoveUp"},
        {Command::Quit, "Quit"},
        {Command::Restart, "Restart"},
        {Command::Invalid, "Invalid"}};
    std::string temp = "Key: ";
    temp += std::any_cast<char>(stats[0]);
    return temp;
}