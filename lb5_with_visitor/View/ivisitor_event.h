#ifndef ivisitor_event_h
#define ivisitor_event_h

class BuffEvent;
class DebuffEvent;
class KillEvent;
class TeleportEvent;

class IVisitorEvent
{
public:
    virtual void visit(BuffEvent) = 0;
    virtual void visit(DebuffEvent) = 0;
    virtual void visit(KillEvent) = 0;
    virtual void visit(TeleportEvent) = 0;
};


#endif