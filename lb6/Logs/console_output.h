#ifndef console_output_h
#define console_output_h

#include "IOutput.h"

class ConsoleOutput : public IOutput
{
public:
    ConsoleOutput() = default;
    std::ostream* getOutput() override;

};

#endif