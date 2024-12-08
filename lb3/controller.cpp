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

void Controller::isEnd()
{
    if (hero.getStat(HP) <= 0)
    {
        std::cout << "Игра завершена!\n";
    }
    if (hero.getStat(ATK) < 0)
    {
        hero.setStat(ATK, 0);
    }
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

bool Controller::step(Side side)
{
    int new_position_y = getPosition().y;
    int new_position_x = getPosition().x;
    field.getCell(new_position_x, new_position_y).setView(' ');
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
        field.getCell(getPosition().x, getPosition().y).setView('@');
        return false;
    }
    if (getPosition() == field.getExit())
    {
        hero.setStat(HP, 0);
    }
    field.getCell(new_position_x, new_position_y).setView('@');
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
        isEnd();
        delete field.getCell(x, y).getEvent();
        field.getCell(x, y).setEvent(nullptr);
    }
}

#endif