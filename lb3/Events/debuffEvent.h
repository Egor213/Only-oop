#ifndef debuffEvent_h
#define debuffEvent_h
#include "eventPattern.h"
#include "../controller.h"
class DebuffEvent : public GameEvent
{
public:
    DebuffEvent(Controller& controller);
    DebuffEvent* clone() override;
    void event() override;
    
private:
    Controller& controller;
};

#endif