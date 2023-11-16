#ifndef console_read_h
#define console_read_h
#include "icommandread.h"
#include <termios.h>
#include <cstdio>
#include <unistd.h>
#include <stdio.h>
#include "setfilemanagement.h"


class ConsoleCommandRead: public ICommandRead
{
public:
    ConsoleCommandRead(ISetManagement* manage);
    Command read();


private:
    ISetManagement* manage;
    char getSymbol() const;
    Command convert(const char symbol) const;
    std::map<Command, char> bind_command_map;
};
#endif