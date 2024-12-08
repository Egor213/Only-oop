#ifndef buffEvent_h
#define buffEvent_h
#include "eventPattern.h"
#include "../controller.h"
class BuffEvent : public GameEvent
{
public:
    BuffEvent(Controller& controller);
    BuffEvent* clone() override;
    void event() override;
    
    
private:
    Controller& controller;
};

#endif