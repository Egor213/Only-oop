#ifndef management_h
#define management_h

#include "isetmanagement.h"
#include "icommandread.h"

#include "enum_readers.h"
#include "enum_setters.h"
#include "console_read.h"
#include "set_file_management.h"

#include <iostream>
#include <map>

class Management
{
public:
    Management();
    ~Management();
    Command getCommand();

private:
    ISetManagement* setter;
    ICommandRead* reader;
    void checkCin(unsigned);
    ISetManagement* getSetters();
    ICommandRead* getReaders(ISetManagement* setter);
    std::string file_name;

    template<typename ValueType>
    bool hasNumberMap(int temp, std::map<int, ValueType> temp_map)
    {
        auto pos = temp_map.find(temp);
        return pos != temp_map.end() ? true : false;
    }
};

#endif