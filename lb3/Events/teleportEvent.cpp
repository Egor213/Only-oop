#ifndef teleportEvent_cpp
#define teleportEvent_cpp
#include "teleportEvent.h"

TeleportEvent::TeleportEvent(Controller &controller) : controller(controller) {}

void TeleportEvent::event()
{
    std::srand(std::time(0));
    int x = 0;
    int y = 0;
    while (true)
    {
        x = std::rand() % (controller.getWidth());
        y = std::rand() % (controller.getHeight());
        if (controller.setPosition(x, y))
            break;
    }
    std::cout << "Вызвано событие TeleportEvent:\n"
              << "Вы были перемещены на клетку с координатами Х: "
              << x << " Y: " << y << '\n';

}

#endif