#ifndef move_h
#define move_h
#include "hero.h"

typedef struct Point{
    int x;
    int y;
}Point;

class Controller{

public:
    enum Side {Up, Down, Rigth, Left, Stay};
    Controller(Hero& hero, int x, int y);

    void move(Side side);
    

    //getters
    Point getPosition();

    //setters
    bool setPosition(int x, int y);

private:
    Hero& hero;
    Point position;
    bool check_position(int x, int y);
    bool step(Point& position, Side side);
};


#endif