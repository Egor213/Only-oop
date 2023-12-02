#include "console_output.h"



std::ostream* ConsoleOutput::getOutput()
{
    return &std::cout;
}