#ifndef controller_h
#define controller_h
#include "hero.h"
#include "point.h"
#include "Field/field.h"
#include "direction.h"
class Controller
{

public:
    Controller(Hero &hero, Field &field, unsigned x, unsigned y);
    unsigned getStat(Stat stat) const;
    void addStat(Stat stat, int value);
    unsigned getWidth();
    unsigned getHeight();
    bool setPosition(unsigned x, unsigned y);
    Point getPosition() const;
    //временно так или нет
    bool step(Side);
private:
    Hero &hero;
    Field &field;
    Point position;
    bool checkPosition(unsigned x, unsigned y) const;
    void checkEvent(unsigned x, unsigned y);
    void isEnd();
    
};

#endif