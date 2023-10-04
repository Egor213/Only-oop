#ifndef controller_h
#define controller_h
#include "hero.h"
#include "point.h"
#include "field.h"

class Controller
{

public:
    enum Side
    {
        Up,
        Down,
        Rigth,
        Left,
        Stay
    };
    Controller(Hero &hero, Field &field, unsigned x, unsigned y);

private:
    Hero &hero;
    Field &field;
    Point position;

    bool checkPosition(unsigned x, unsigned y) const;
    bool step(Side);
    Point getPosition() const;
    bool setPosition(unsigned x, unsigned y);
    void addHP(int);
    void addEXP(int);
    void addATK(int);
};

#endif
