#ifndef cell_h
#define cell_h
#include <iostream>
#include "../Events/eventPattern.h"
class Cell
{
public:
    Cell(bool passability = true);
    ~Cell();
    void setPassability(bool passability);
    bool getPassability() const;
    char getView() const;
    void setView(char);
    void setEvent(GameEvent *);
    GameEvent *getEvent();
    void callEvent();

private:
    bool passability;
    char view;
    GameEvent *event;
};

#endif
