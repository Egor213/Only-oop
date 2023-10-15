#ifndef debuffEvent_cpp
#define debuffEvent_cpp
#include "debuffEvent.h"

DebuffEvent::DebuffEvent(Controller &controller) : controller(controller) {}

void DebuffEvent::event()
{
    controller.addStat(ATK, -1);
    controller.addStat(HP, -5);
    std::cout << "Вызвано событие deBuffEvent:\n"
              << "ATK уменьшено на 1\n"
              << "HP уменьшено на 5\n";
}
DebuffEvent* DebuffEvent::clone()
{
    return new DebuffEvent(*this);
}

#endif