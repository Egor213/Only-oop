#ifndef enemy_h
#define enemy_h
#include <iostream>
#include "../Field/field.h"
#include "../Field/point.h"

template<typename Movement, typename Interaction>
class Enemy
{
 public:
    Enemy(Field* field) : field(field) {}

    void move()
    {
        moves.move();
    }

    void interaction()
    {
        inter.interaction();
    }


    void setCoords(unsigned x, unsigned y)
    {
        if (field->getCell(x, y).getPassability() && x < field->getWidth() && y < field->getHeight())
        {
            coords = {x, y};
        }
    }


    Point getCoords() const
    {
        return coords;
    }



private:
    Field* field;
    Movement moves;
    Interaction inter;
    Point coords;
};



#endif