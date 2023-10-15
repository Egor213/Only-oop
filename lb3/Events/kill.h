#ifndef kill_h
#define kill_h
#include "eventPattern.h"
#include "../controller.h"

class KillEvent : public GameEvent
{
public:
    KillEvent(Controller &controller);
    void event() override;

private:
    Controller &controller;
};

#endif