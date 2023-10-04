#ifndef cell_cpp
#define cell_cpp
#include "cell.h"

Cell::Cell(bool passability) : passability(passability) {}

bool Cell::getPassability() const
{
    return passability;
}

void Cell::setPassability(bool passability)
{
    this->passability = passability;
}

#endif
