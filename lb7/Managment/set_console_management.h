#ifndef setconsolemanagement_h
#define setconsolemanagement_h
#include "commands.h"
#include "isetmanagement.h"
#include <iostream>
class SetConsoleManagement: public ISetManagement
{
public:
    SetConsoleManagement();
    std::map<Command, char> getKeyManagement();

private:
    std::map<Command, char> bind_manage_map;
    bool hasKeyInMap(char temp);
    bool checkChar(char);
};

#endif