#ifndef kill_cpp
#define kill_cpp
#include "kill.h"

KillEvent::KillEvent(Controller &controller) : controller(controller) {}

void KillEvent::event()
{
    controller.addStat(HP, -controller.getStat(HP));
}

KillEvent* KillEvent::clone()
{
    return new KillEvent(*this);
}

void KillEvent::acceptVisitor(IVisitorEvent& obj)
{
    obj.visit(*this);
}

#endif