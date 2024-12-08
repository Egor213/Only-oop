#ifndef manage_logs_h
#define manage_logs_h

#include "console_output.h"
#include "file_output.h"

class ManageLogs
{
public:
    ManageLogs() = default;
    ~ManageLogs();
    std::vector<std::ostream*> getStream();


private:
    std::vector<std::ostream*> getOut();
    std::vector<std::ostream*> temp_vec;

};


#endif