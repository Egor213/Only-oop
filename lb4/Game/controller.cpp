#ifndef controller_cpp
#define controller_cpp
#include "controller.h"

Controller::Controller(Hero &hero, Field &field) : hero(hero), field(field), position({0, 0})
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
    char temp = field.getCell(getPosition().x, getPosition().y).getView();
    field.getCell(getPosition().x, getPosition().y).setView(' ');
    if (checkPosition(x, y) && field.getCell(x, y).getPassability())
    {
        if (temp != '@')
            field.getCell(getPosition().x, getPosition().y).setView(temp);
        this->position = {x, y};
        field.getCell(x, y).setView('@');
        checkEvent(x, y);

        return true;
    }
    field.getCell(getPosition().x, getPosition().y).setView(temp);
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
    if (getPosition() == field.getExit())
    {
        hero.setStat(HP, 0);
    }
    return true;
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
