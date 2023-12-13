#ifndef isetmanagement_h
#define isetmanagement_h
#include <map>
#include "commands.h"

class ISetManagement{
public:

    virtual std::map<Command, char> getKeyManagement() = 0;
    virtual ~ISetManagement() {};
};

#endif