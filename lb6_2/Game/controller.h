#ifndef controller_h
#define controller_h
#include "../Entity/hero.h"
#include "../Field/point.h"
#include "../Field/field.h"
#include "direction.h"
#include <vector>
#include "../Managment/commands.h"
class Controller
{

public:
    Controller(Hero &hero, Field &field);
    unsigned getStat(Stat stat) const;
    void addStat(Stat stat, int value);
    unsigned getWidth();
    unsigned getHeight();
    bool setPosition(unsigned x, unsigned y);
    Point getPosition() const;
    bool step(Command);
    bool getFlag();

private:
    Hero &hero;
    Field &field;
    Point position;
    bool checkPosition(unsigned x, unsigned y) const;
    void checkEvent(unsigned x, unsigned y);
    bool end_game;
};

#endif
