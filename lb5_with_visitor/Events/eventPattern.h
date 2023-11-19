#ifndef eventPattern_h
#define eventPattern_h
#include "../View/ivisitor_event.h"

class GameEvent
{
public:
    virtual void event() = 0;
    virtual GameEvent* clone() = 0;
    virtual void acceptVisitor(IVisitorEvent&) = 0;
    virtual ~GameEvent(){};
};

#endif