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
    if (this->event != nullptr)
    {
        delete this->event;
    }
    this->event = event;
}

GameEvent *Cell::getEvent()
{
    return event;
}

void Cell::callEvent()
{
    event->event();
    delete event;
    event = nullptr;
}

Cell::Cell(const Cell &other) : passability(other.passability), view(other.view), event(nullptr)
{
    if (other.event != nullptr)
    {
        event = other.event->clone();
    }
}

Cell &Cell::operator=(const Cell &other)
{
    Cell temp(other);
    std::swap(passability, temp.passability);
    std::swap(view, temp.view);
    std::swap(event, temp.event);
    return *this;
}



#endif
