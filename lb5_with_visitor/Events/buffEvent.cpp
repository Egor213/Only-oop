#ifndef buffEvent_cpp
#define buffEvent_cpp
#include "buffEvent.h"

BuffEvent::BuffEvent(Controller &controller) : controller(controller) {}

void BuffEvent::event()
{
    controller.addStat(ATK, 2);
    controller.addStat(HP, 10);
    controller.addStat(EXP, 100);
}

BuffEvent* BuffEvent::clone()
{
    return new BuffEvent(*this);
}

void BuffEvent::acceptVisitor(IVisitorEvent& obj)
{
    obj.visit(*this);
}

#endif