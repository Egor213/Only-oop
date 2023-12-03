#ifndef kill_h
#define kill_h
#include "eventPattern.h"
#include "../Game/controller.h"

class KillEvent : public GameEvent
{
public:
    KillEvent(Controller &controller);
    KillEvent* clone() override;
    void event() override;

private:
    Controller &controller;
};

#endif