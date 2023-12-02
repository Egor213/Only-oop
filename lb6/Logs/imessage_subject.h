#ifndef imessage_subject_h
#define imessage_subject_h
#include "imessage.h"





class IMessageSubject
{
public:
    virtual void addLogObserver(IMessage* apObserver) = 0;
    virtual void notifyLog(LogEvent) = 0;
    virtual ~IMessageSubject() {}
};

#endif