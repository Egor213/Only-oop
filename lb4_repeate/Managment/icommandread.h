#ifndef icommandread_h
#define icommandread_h
#include "commands.h"

class ICommandRead{

public:
    virtual Command read() = 0;
    virtual ~ICommandRead() {};
};

#endif