#ifndef debuffEvent_h
#define debuffEvent_h
#include "eventPattern.h"
#include "../Game/controller.h"
class DebuffEvent : public GameEvent
{
public:
    DebuffEvent(Controller& controller);
    DebuffEvent* clone() override;
    void event() override;
    void acceptVisitor(IVisitorEvent&) override;
    
private:
    Controller& controller;
};

#endif