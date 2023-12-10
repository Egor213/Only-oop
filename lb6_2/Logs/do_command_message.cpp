#include "do_command_message.h"

DoCommandMessage::DoCommandMessage(char last_key, Command last_command)
{
    stats = {last_key, last_command};
}

std::string DoCommandMessage::print()
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
    temp += " Command: ";
    temp += (convert_command[std::any_cast<Command>(stats[1])]);
    return temp;
}