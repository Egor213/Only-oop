#ifndef management_cpp
#define management_cpp
#include "management.h"

Management::Management()
{
    key_map = {
        {Command::MoveLeft, 0},
        {Command::MoveDown, 0},
        {Command::MoveRight, 0},
        {Command::MoveUp, 0},
        {Command::Quit, 0},
        {Command::Restart, 0},
        {Command::Invalid, 0}};
    commands_map = {
        {"MoveLeft", Command::MoveLeft},
        {"MoveDown", Command::MoveDown},
        {"MoveRight", Command::MoveRight},
        {"MoveUp", Command::MoveUp},
        {"Quit", Command::Quit},
        {"Restart", Command::Restart},
    };
}

std::map<Command, char> Management::bindKey(const std::string &file_name)
{
    ReadFile file(file_name);
    lines = file.read();
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].length() > 0)
        {
            char key;
            std::string command;
            std::istringstream iss(lines[i]);
            iss >> command >> key;
            if (key < 33 || key > 126)
            {
                throw std::runtime_error("Неудалось считать ключ " + lines[i]);
            }
            if (!command.empty())
            {
                command.erase(command.size() - 1);
            }
            checkKeyMap(key);
            key_map[stringToCommand(command)] = key;
            if (key_map[Command::Invalid] != 0)
            {
                throw std::runtime_error("Ошибка считывания");
            }
        }
    }
    return key_map;
}

Command Management::stringToCommand(const std::string &command)
{
    if (commands_map.count(command) > 0)
        return commands_map[command];
    else
        return Command::Invalid;
}

std::string Management::getKeyByValue(const std::map<std::string, Command> &commands_map, const Command &value) const
{
    for (const auto &pair : commands_map)
    {
        if (pair.second == value)
            return pair.first;
    }
    throw std::out_of_range("Значение не найдено");
}

void Management::control_scheme() const
{
    for (const auto &pair : key_map)
    {
        if (pair.first != Command::Invalid)
            std::cout << getKeyByValue(commands_map, pair.first) << " - " << pair.second << '\n';
    }
}

void Management::checkKeyMap(const char value)
{
    for (const auto &pair : key_map)
    {
        if (pair.second == value)
            throw std::runtime_error("Неверные значение клавишь у комманд!");
    }
}

std::vector<Command> Management::commandFile(const std::string &file_name)
{
    ReadFile file(file_name);
    lines = file.read();
    std::vector<Command> arr_commands;
    std::string temp;
    std::string command;
    std::istringstream iss(lines[0]);
    iss >> temp;
    while (true)
    {
        if(!iss)
            break;
        iss >> command;
        arr_commands.push_back(stringToCommand(command));
    }
    for (auto pair : arr_commands)
    {
        if (pair == Command::Invalid)
        {
            throw std::runtime_error("Неверная команда в файле!");
        }
    }
    return arr_commands;
}

Command Management::getCommand()
{
    char temp;
    system("stty raw");
    std::cout << "Введите клавишу: ";
    temp = getchar();
    system("stty cooked echo");
    std::cout<<'\n';
    Command it = getKeyByValueCommand(key_map, temp);
    return it;
}

Command Management::getKeyByValueCommand(const std::map<Command, char> &key_map, const char &value)
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

#endif