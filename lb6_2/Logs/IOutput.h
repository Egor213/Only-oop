#ifndef ioutput_h
#define ioutput_h
#include <iostream>
#include <fstream>
#include <vector>
class IOutput
{
public:
    virtual std::ostream* getOutput() = 0;
    virtual ~IOutput() {};
};


#endif