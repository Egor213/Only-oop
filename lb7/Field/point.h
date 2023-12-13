#ifndef point_h
#define point_h

class Point
{
public:
    unsigned x;
    unsigned y;
    Point(unsigned x = 0, unsigned y = 0);
    bool operator==(const Point& other) const;
    Point& operator+=(const Point& other);
};

#endif