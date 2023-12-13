#ifndef file_controle_h
#define file_controle_h
#include "icommandread.h"
#include "read_file.h"
#include "isetmanagement.h"
class FileCommandRead: public ICommandRead
{
public:
    FileCommandRead(ISetManagement* manage, const std::string& file_name);
    Command read();
    std::map<Command, char> getBind();
    char getLast() override;

private:
    const std::string& file_name;
    std::map<Command, char> bind_map;
    ISetManagement* manage;
    unsigned counter_file_command;
    std::vector<std::string> commands_vec;
    Command getKeyByValue(char temp, std::map<Command, char> bind_map);
    char last_key;
};

#endif