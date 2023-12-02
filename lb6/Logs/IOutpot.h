#ifndef ioutput_h
#define ioutput_h
#include <iostream>
#include <fstream>
#include <vector>
class IOuput
{
public:
    virtual std::ostream* getOutput() = 0;
    virtual ~IOuput() {};
};


#endif