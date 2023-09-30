#ifndef controller_h
#define controller_h
#include "hero.h"
#include "point.h"
#include "field.h"

class Controller{

public:
    enum Side {Up, Down, Rigth, Left, Stay};
    Controller(Hero& hero, Field& field, int x, int y);

    
    
    

    
private:
    Hero& hero;
    Field& field;
    Point position;
    
    bool check_position(int x, int y);
    bool step(Side);
    //getters
    Point get_position();
    //setters
    bool set_position(int x, int y);
    void addHP(int);
    void addEXP(int);
    void addATK(int);
    
};


#endif
