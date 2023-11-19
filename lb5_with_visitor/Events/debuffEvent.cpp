#ifndef debuffEvent_cpp
#define debuffEvent_cpp
#include "debuffEvent.h"

DebuffEvent::DebuffEvent(Controller &controller) : controller(controller) {}

void DebuffEvent::event()
{
    controller.addStat(ATK, -1);
    controller.addStat(HP, -5);
    if (controller.getStat(ATK) < 0)
    {
        controller.addStat(ATK, -1*controller.getStat(ATK));
    }
}
DebuffEvent* DebuffEvent::clone()
{
    return new DebuffEvent(*this);
}

void DebuffEvent::acceptVisitor(IVisitorEvent& obj)
{
    obj.visit(*this);
}

#endif