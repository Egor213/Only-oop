#ifndef kill_cpp
#define kill_cpp
#include "kill.h"

KillEvent::KillEvent(Controller &controller) : controller(controller) {}

void KillEvent::event()
{
    controller.addStat(HP, -controller.getStat(HP));
    std::cout << "Вызвано событие KillEvent:\n"
              << "HP установленов 0\n";
}

KillEvent* KillEvent::clone()
{
    return new KillEvent(*this);
}

#endif