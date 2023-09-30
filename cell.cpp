#ifndef cell_cpp
#define cell_cpp
#include "cell.h"

Cell::Cell(bool passability) : passability(passability){}

Cell::~Cell(){
    delete event;
}

bool Cell::getPassability(){
    return passability;
}


int* Cell::get_event(){
    return event;
}

void Cell::set_event(int* event){
    this->event = event;
}

void Cell::setPassability(bool passability){
    this->passability = passability;
}


#endif