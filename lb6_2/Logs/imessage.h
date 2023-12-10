#ifndef imessage_h
#define imessage_h
#include <any>
#include <map>
#include <iomanip>
#include <functional>

#include <typeinfo>



class IMessage
{
public:
    virtual ~IMessage() {};
    virtual std::string print() = 0;
};

#endif