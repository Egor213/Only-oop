#ifndef cell_cpp
#define cell_cpp
#include "cell.h"

Cell::Cell(bool passability) : passability(passability), event(nullptr) {}

Cell::~Cell()
{
    delete event;
}

bool Cell::getPassability() const
{
    return passability;
}

char Cell::getView() const
{
    return view;
}

void Cell::setView(char view)
{
    this->view = view;
}

void Cell::setPassability(bool passability)
{
    this->passability = passability;
}

void Cell::setEvent(GameEvent *event)
{
    this->event = event;
}

GameEvent *Cell::getEvent()
{
    return event;
}

void Cell::callEvent()
{
    event->event();
}

#endif
