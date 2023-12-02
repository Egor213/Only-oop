#ifndef console_output_h
#define console_output_h

#include "IOutpot.h"

class ConsoleOutput : public IOuput
{
public:
    ConsoleOutput() = default;
    std::ostream* getOutput() override;

};

#endif