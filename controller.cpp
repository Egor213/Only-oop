#ifndef move_cpp
#define move_cpp
#include "controller.h"
#include "constants.h"

Controller::Controller(Hero& hero, int x, int y) : hero(hero){
    check_position(x, y);
    this->position.x = x;
    this->position.y = y;
}


bool Controller::check_position(int x, int y){
    if (x < 0 || x > WIDTH || y < 0 || y > HEIGTH)
        return false;
    return true;
}

Point Controller::getPosition(){
    return position;
}

bool Controller::setPosition(int x, int y){
    if (check_position(x, y)){
        this->position.x = x;
        this->position.y = y;
        return true;
    }
    return false;
}


bool Controller::step(Point& position, Side side){
    int new_position = 0;
    switch (side)
    {
    case Up:
        new_position = getPosition().y + 1;
        break;
    case Down:
        new_position = getPosition().y - 1;
        break;
    case Rigth:
        new_position = getPosition().x + 1;
        break;
    case Left:
        new_position = getPosition().x - 1;
        break;
    }
    if (setPosition(position.x, new_position)){
        return true;
    }else{
        return false;
    }
}

void Controller::move(Side side){
    switch (side)
    {
    case Up:
        step(position, Up);
        break;
    case Down:
        step(position, Down);
        break;
    case Rigth:
        step(position, Rigth);
        break;
    case Left:
        step(position, Left);
        break;
    case Stay:
        std::cout << "ОСТАЛСЯ НА МЕСТЕ" << '\n';
        break;
    }
}

#endif