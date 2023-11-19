#ifndef view_console_events_h
#define view_console_events_h

#include "ivisitor_event.h"
#include "view_console.h"

class ViewConsoleEvent: public IVisitorEvent
{
public:
    ViewConsoleEvent(ViewConsole& view);
    void visit(BuffEvent) override;
    void visit(DebuffEvent) override;
    void visit(KillEvent) override;
    void visit(TeleportEvent) override;

private:
    ViewConsole& view;

};


#endif