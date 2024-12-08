#ifndef user_commands_h
#define user_commands_h
#include "management.h"
#include "../Game/direction.h"
#include "../Game/controller.h"
class InputCommand
{
public:
    InputCommand(const std::string &file_name, Controller &controller);
    void stepCommand();
    void control_scheme();

private:
    Management management;
    Controller &controller;
    std::map<Command, char> key_map;
    std::map<Command, Side> command_map;
    Command getKeyByValue(const std::map<Command, char> &key_map, const char &value);
};

#endif