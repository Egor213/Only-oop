#ifndef buffEvent_cpp
#define buffEvent_cpp
#include "buffEvent.h"

BuffEvent::BuffEvent(Controller &controller) : controller(controller) {}

void BuffEvent::event()
{
    controller.addStat(ATK, 2);
    controller.addStat(HP, 10);
    controller.addStat(EXP, 100);
    std::cout << "Вызвано событие BuffEvent:\n"
              << "ATK увеличено на 2\n"
              << "HP увеличено на 10\n"
              << "EXP увеличено на 100\n";
}

#endif