#include "file_controle.h"


FileCommandRead::FileCommandRead(ISetManagement* manage, const std::string& file_name) : file_name(file_name), counter_file_command(-1), last_key('0')
{
    ReadFile file(file_name);
    commands_vec = file.read();
    bind_map = manage->getKeyManagement();
}


Command FileCommandRead::read()
{
    counter_file_command++;
    Command temp;
    if (counter_file_command < commands_vec.size())
    {
        char symbol_command = commands_vec[counter_file_command][0];
        last_key = symbol_command;
        temp = getKeyByValue(symbol_command, bind_map);
    }
    else
        temp = Command::Quit;
    return temp;
}

std::map<Command, char> FileCommandRead::getBind()
{
    return bind_map;
}

char FileCommandRead::getLast()
{
    return last_key;
}

Command FileCommandRead::getKeyByValue(char temp, std::map<Command, char> bind_map)
{
    for (const auto& per : bind_map)
    {
        if (per.second == temp)
            return per.first;
    }
    return Command::Invalid;
}


