#ifndef point_cpp
#define point_cpp
#include "point.h"

Point::Point(unsigned x, unsigned y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    if (x == other.x && y == other.y)
    {
        return true;
    }
    return false;
}

#endif