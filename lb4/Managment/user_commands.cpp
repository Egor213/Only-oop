#ifndef user_commands_cpp
#define user_commands_cpp
#include "user_commands.h"

InputCommand::InputCommand(const std::string &file_name, Controller &controller) : controller(controller)
{
    key_map = management.bindKey(file_name);
    command_map = {
        {Command::MoveUp, Up},
        {Command::MoveDown, Down},
        {Command::MoveRight, Rigth},
        {Command::MoveLeft, Left},
    };
}

void InputCommand::stepCommand()
{
    char temp;
    system("stty raw");
    std::cout << "Введите клавишу: ";
    temp = getchar();
    system("stty cooked echo");
    Command it = getKeyByValue(key_map, temp);
    switch (it)
    {
    case Command::Invalid:
        std::cout << "Введена неверная клавиша\n";
        break;
    case Command::Quit:
        std::cout << "\nВыход из игры\n";
        exit(0);
        break;
    case Command::Restart:
        std::cout << "Рестарт\n";
        break;
    default:
        controller.step(command_map[it]);
        break;
    }
    std::cout << "\033[F";
    std::cout << "\033[K";
    system("stty cooked echo");
}

Command InputCommand::getKeyByValue(const std::map<Command, char> &key_map, const char &value)
{
    for (const auto &pair : key_map)
    {
        if (pair.second == value)
        {
            return pair.first;
        }
    }
    return Command::Invalid;
}

void InputCommand::control_scheme()
{
    management.control_scheme();
}

#endif