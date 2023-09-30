#ifndef controller_cpp
#define controller_cpp
#include "controller.h"



Controller::Controller(Hero& hero, Field& field, int x, int y) : hero(hero),  field(field), position(x,y){
    if (!check_position(x, y))
        ERROR_VALUE;
}


bool Controller::check_position(int x, int y){
    if (x < 0 || x > field.get_width() || y < 0 || y > field.get_height())
        return false;
    return true;
}

Point Controller::get_position(){
    return position;
}



bool Controller::set_position(int x, int y){
    if (check_position(x, y) && !field.array_cells[x][y].getPassability()){
        this->position = {x, y};
        return true;
    }
    return false;
}


bool Controller::step(Side side){
    int new_position_y = get_position().y;
    int new_position_x = get_position().x;
    switch (side)
    {
    case Up:
        new_position_y++;
        break;
    case Down:
        new_position_y--;
        break;
    case Rigth:
        new_position_x++;
        break;
    case Left:
        new_position_x--;
        break;
    }
    if (!set_position(new_position_x, new_position_y)){
        std::cerr << "Перемещение на данную клетку невозможно!" << '\n';
        return false;
    }
    return true;
}


void Controller::addATK(int atk){
    hero.setATK(hero.getATK() + atk);
}
void Controller::addHP(int hp){
    hero.setHP(hero.getHP() + hp);
}
void Controller::addEXP(int exp){
    hero.setEXP(hero.getATK() + exp);
}



#endif