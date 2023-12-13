#ifndef imessage_h
#define imessage_h
#include <any>
#include <map>
#include <iomanip>
#include <functional>

#include <typeinfo>
enum class LogEvent
{
    WIN,
    LOSE,
    NEWGAME,
    DOCOMMAND,
    DONTCOMMAND
};

enum LogsEnum
{
    Key,
    Commands,
    LoseY,
    LoseX,
    Height,
    Width,
    StartX,
    StartY,
    HealPoint,
    Attack,
    Experience
};

class IMessage
{
public:
    virtual void update(LogEvent) = 0;
    virtual ~IMessage() {}
    virtual std::map<LogsEnum, std::any> getData() = 0;
};

#endif