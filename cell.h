#ifndef cell_h
#define cell_h
#include <iostream>

class Cell
{

public:
    Cell(bool passability = true);
    void setPassability(bool passability);
    bool getPassability() const;

private:
    bool passability;
};

#endif
