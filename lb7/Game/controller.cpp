#ifndef controller_cpp
#define controller_cpp
#include "controller.h"

Controller::Controller(Hero &hero, Field &field) : hero(hero), field(field), position({0, 0}), end_game(false)
{
}

bool Controller::checkPosition(unsigned x, unsigned y) const
{
    if (x >= field.getWidth() || y >= field.getHeight())
    {
        return false;
    }
    return true;
}

Point Controller::getPosition() const
{
    return position;
}

bool Controller::setPosition(unsigned x, unsigned y)
{
    if (checkPosition(x, y) && field.getCell(x, y).getPassability())
    {
        this->position = {x, y};
        checkEvent(x, y);

        return true;
    }
    return false;
}

bool Controller::step(Command side)
{
    int new_position_y = getPosition().y;
    int new_position_x = getPosition().x;
    switch (side)
    {
    case Command::MoveUp:
        new_position_y++;
        break;
    case Command::MoveDown:
        new_position_y--;
        break;
    case Command::MoveRight:
        new_position_x++;
        break;
    case Command::MoveLeft:
        new_position_x--;
        break;
    }
    if (!setPosition(new_position_x, new_position_y))
    {
        return false;
    }
    if (getPosition() == field.getExit())
    {
        end_game = true;
    }
    return true;
}

bool Controller::getFlag()
{
    return end_game;
}

void Controller::addStat(Stat stat, int value)
{
    switch (stat)
    {
    case ATK:
        hero.setStat(ATK, hero.getStat(ATK) + value);
        break;
    case HP:
        hero.setStat(HP, hero.getStat(HP) + value);
        break;
    case EXP:
        hero.setStat(EXP, hero.getStat(EXP) + value);
        break;
    }
}

unsigned Controller::getStat(Stat stat) const
{
    unsigned step = 0;
    switch (stat)
    {
    case HP:
        step = hero.getStat(HP);
        break;
    case ATK:
        step = hero.getStat(ATK);
        break;
    case EXP:
        step = hero.getStat(EXP);
        break;
    }
    return step;
}

unsigned Controller::getHeight()
{
    return field.getHeight();
}

unsigned Controller::getWidth()
{
    return field.getWidth();
}

void Controller::checkEvent(unsigned x, unsigned y)
{
    if (field.getCell(x, y).getEvent() != nullptr)
    {
        field.getCell(x, y).callEvent();
    }
}



#endif
