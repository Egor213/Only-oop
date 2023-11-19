#include "view_console_events.h"



ViewConsoleEvent::ViewConsoleEvent(ViewConsole& view) : view(view) {}

void ViewConsoleEvent::visit(BuffEvent buff_event)
{
    return view.viewBuffEvent();
}

void ViewConsoleEvent::visit(KillEvent kill_event)
{
    return view.viewKillEvent();
}

void ViewConsoleEvent::visit(DebuffEvent debuff_event)
{
    return view.viewDebuffEvent();
}

void ViewConsoleEvent::visit(TeleportEvent teleport_event)
{
    return view.viewTeleportEvent();
}