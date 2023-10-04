#ifndef controller_cpp
#define controller_cpp
#include "controller.h"

Controller::Controller(Hero &hero, Field &field, unsigned x, unsigned y) : hero(hero), field(field), position(x, y)
{
    if (!checkPosition(x, y))
        this->position = {0, 0};
}

bool Controller::checkPosition(unsigned x, unsigned y) const
{
    if (x > field.getWidth() || y > field.getHeight())
        return false;
    return true;
}

Point Controller::getPosition() const
{
    return position;
}

bool Controller::setPosition(unsigned x, unsigned y)
{
    if (checkPosition(x, y) && !field.getCell(x, y).getPassability())
    {
        this->position = {x, y};
        return true;
    }
    return false;
}

bool Controller::step(Side side)
{
    int new_position_y = getPosition().y;
    int new_position_x = getPosition().x;
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
    if (!setPosition(new_position_x, new_position_y))
    {
        return false;
    }
    return true;
}

void Controller::addATK(int atk)
{
    hero.setATK(hero.getATK() + atk);
}
void Controller::addHP(int hp)
{
    hero.setHP(hero.getHP() + hp);
}
void Controller::addEXP(int exp)
{
    hero.setEXP(hero.getATK() + exp);
}

#endif
