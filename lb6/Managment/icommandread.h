#ifndef icommandread_h
#define icommandread_h
#include "commands.h"
#include <map>
class ICommandRead{

public:
    virtual Command read() = 0;
    virtual std::map<Command, char> getBind() = 0;
    virtual char getLast() = 0;
    virtual ~ICommandRead() {};
};

#endif