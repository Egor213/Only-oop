#include "file_controle.h"


FileCommandRead::FileCommandRead(ISetManagement* manage, const std::string& file_name) : file_name(file_name), counter_file_command(-1) 
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
        temp = getKeyByValue(symbol_command, bind_map);
    }
    else
        temp = Command::Quit;
    return temp;
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


