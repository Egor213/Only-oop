#ifndef management_h
#define management_h
#include "commands.h"
#include "read_file.h"
#include <map>
#include <sstream>
class Management
{
public:
    Management();
    std::map<Command, char> bindKey(const std::string &file_name);
    std::vector<Command> commandFile(const std::string &file_name);
    void control_scheme() const;
    
private:
    std::vector<std::string> lines;
    std::map<Command, char> key_map;
    std::map<std::string, Command> commands_map;
    Command stringToCommand(const std::string &command);
    std::string getKeyByValue(const std::map<std::string, Command> &commands_map, const Command &value) const;
    void checkKeyMap(const char value);
};

#endif