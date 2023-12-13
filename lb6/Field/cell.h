#ifndef cell_h
#define cell_h
#include <iostream>
#include "../Events/eventPattern.h"
class Cell
{
public:
    Cell(bool passability = true);
    ~Cell();
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    void setPassability(bool passability);
    bool getPassability() const;
    void setEvent(GameEvent *);
    GameEvent *getEvent();
    void callEvent();

private:
    bool passability;
    GameEvent *event;
};

#endif
