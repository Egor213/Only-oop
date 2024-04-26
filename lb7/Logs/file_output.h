#ifndef file_output_h
#define file_output_h

#include "IOutpot.h"
#include <string.h>

class FileOutput : public IOuput
{
public:
    FileOutput(const std::string &file_name);
    ~FileOutput();
    std::ostream* getOutput();


private:
    std::ofstream file;
};

#endif