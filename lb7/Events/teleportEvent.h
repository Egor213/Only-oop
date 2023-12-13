#ifndef teleportEvent_h
#define teleportEvent_h
#include "eventPattern.h"
#include "../Game/controller.h"
#include <cstdlib>
#include <ctime>
class TeleportEvent : public GameEvent
{
public:
    TeleportEvent(Controller &controller);
    TeleportEvent* clone() override;
    void event() override;

private:
    Controller &controller;
};

#endif