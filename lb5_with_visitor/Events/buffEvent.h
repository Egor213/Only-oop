#ifndef buffEvent_h
#define buffEvent_h
#include "eventPattern.h"
#include "../Game/controller.h"
class BuffEvent : public GameEvent
{
public:
    BuffEvent(Controller& controller);
    BuffEvent* clone() override;
    void event() override;
    void acceptVisitor(IVisitorEvent&) override;
    
    
private:
    Controller& controller;
};

#endif