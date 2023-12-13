#include "set_console_management.h"

SetConsoleManagement::SetConsoleManagement()
{
    bind_manage_map = {
        {Command::MoveLeft, 0},
        {Command::MoveDown, 0},
        {Command::MoveRight, 0},
        {Command::MoveUp, 0},
        {Command::Quit, 0},
        {Command::Restart, 0},
        {Command::Invalid, 0}};

}

bool SetConsoleManagement::hasKeyInMap(char temp)
{
    for (const auto& per : bind_manage_map)
    {
        if (per.second == temp)
            return true;
    }
    return false;
}

std::map<Command, char> SetConsoleManagement::getKeyManagement()
{

    std::map<std::string, Command> string_command_map = {
        {"MoveLeft", Command::MoveLeft},
        {"MoveDown", Command::MoveDown},
        {"MoveRight", Command::MoveRight},
        {"MoveUp", Command::MoveUp},
        {"Quit", Command::Quit},
        {"Restart", Command::Restart},
    };
    std::cout << "Введите управление игроком\n";
    for (auto const& per : string_command_map)
    {
        while(1)
        {
            std::cout << per.first << ": ";
            char temp;
            std::cin >> temp;
            std::cin.ignore(100, '\n');
            if (!checkChar(temp))
            {
                std::cout << "Введите другую клавишу!\n";
                continue;
            }
            if (!hasKeyInMap(temp))
            {
                bind_manage_map[per.second] = temp;
                break;
            }
            else
                std::cout << "Вы пытаетесь ввести уже назначенный символ!\n";
        }
        
    }
    return bind_manage_map;
}

bool SetConsoleManagement::checkChar(char temp)
{
    return (temp < 33 || temp > 126) ? false : true;
}

