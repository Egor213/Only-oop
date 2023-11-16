#include "setfilemanagement.h"

SetFileManagement::SetFileManagement(const std::string &file_name)
{
    ReadFile file(file_name);
    file_content = file.read();

    string_command_map = {
        {"MoveLeft", Command::MoveLeft},
        {"MoveDown", Command::MoveDown},
        {"MoveRight", Command::MoveRight},
        {"MoveUp", Command::MoveUp},
        {"Quit", Command::Quit},
        {"Restart", Command::Restart},
    };
    
}

std::map<Command, char> SetFileManagement::getKeyManagement()
{
    bind_command_map = {
        {Command::MoveLeft, 0},
        {Command::MoveDown, 0},
        {Command::MoveRight, 0},
        {Command::MoveUp, 0},
        {Command::Quit, 0},
        {Command::Restart, 0},
        {Command::Invalid, 0}};

    for (auto str : file_content)
    {
        if (str.length() > 1)
        {
            char key;
            std::string command;
            std::istringstream iss(str);
            iss >> command >> key;
            if (key < 33 || key > 126)
                throw std::runtime_error("Недопустимое значение ключа " + str);
            if (hasKeyInMap(key, bind_command_map))
                throw std::runtime_error("Вы пытаесь назначить две одинаковые клавиши на одну команду! " + str);
            if (!command.empty() && command.back() == ':')
                command.erase(command.size() - 1); // убираем : в конце строки

            bind_command_map[getCommandFromString(command)] = key;
        }
    }
    checkFullCommandBind();
    return bind_command_map;
}

void SetFileManagement::checkFullCommandBind() const
{
    if (hasKeyInMap(0, bind_command_map))
        throw std::runtime_error("Заполнены не все комманды! ");
}

bool SetFileManagement::hasCommandFile(const std::string &command_file) const
{
    auto pos = string_command_map.find(command_file);
    return pos != string_command_map.end() ? true : false;
}

Command SetFileManagement::getCommandFromString(std::string &command_file)
{
    if (hasCommandFile(command_file))
        return string_command_map[command_file];
    return Command::Invalid;
}

bool SetFileManagement::hasKeyInMap(char symbol, std::map<Command, char> map_check) const
{
    for (const auto &pair : map_check)
    {
        if (pair.first == Command::Invalid)
            continue;
        if (pair.second == symbol)
            return true;
    }
    return false;
}