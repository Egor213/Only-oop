#ifndef enemy_h
#define enemy_h
#include <iostream>
#include "../Field/field.h"
#include "../Field/point.h"
#include "../Game/controller.h"

template <typename Movement, typename Interaction>
class Enemy
{
public:
    Enemy(Field *field, Controller* controller) : field(field), controller(controller) {}

    void move()
    {
        moves.move(this);
    }

    void interaction()
    {
        inter.interaction(this);
    }

    bool addCoords(std::pair<int, int> temp)
    {

        Point new_coords = coords;
        new_coords.x += temp.first;
        new_coords.y += temp.second;
        if (setCoords(new_coords.x, new_coords.y))
            return true;
        return false;
    }

    bool setCoords(unsigned x, unsigned y)
    {
        if (field->getCell(x, y).getPassability() && x < field->getWidth()-1 && y < field->getHeight()-1 && x > 0 && y > 0)
        {
            if (controller->getPosition().x == x && controller->getPosition().y == y)
                interaction();
            else
                coords = {x, y};
            return true;
        }
        return false;
    }

    Point getCoords() const
    {
        return coords;
    }



    Controller* getPlayerController()
    {
        return controller;
    }



private:
    Controller* controller;
    Field *field;
    Movement moves;
    Interaction inter;
    Point coords;
};

#endif