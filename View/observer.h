#ifndef observer_h
#define observer_h
#include "enum_view_events.h"

class Observer
{
    
public:
    virtual void update(ViewEvent view_event) = 0;
    virtual ~Observer() {}


};


#endif