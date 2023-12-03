#ifndef setfilemanagement_h
#define setfilemanagement_h
#include "commands.h"
#include "isetmanagement.h"
#include "read_file.h"
#include <sstream>

class SetFileManagement: public ISetManagement
{
public:
    SetFileManagement(const std::string &file_name);
    std::map<Command, char> getKeyManagement();

private:
    std::vector<std::string> file_content;
    std::map<std::string, Command> string_command_map;
    std::map<Command, char> bind_command_map;
    bool hasCommandFile(const std::string& command_string) const;
    Command getCommandFromString(std::string& command_file);
    bool hasKeyInMap(char symbol, std::map<Command, char> map_check) const;
    void checkFullCommandBind() const;

};

#endif