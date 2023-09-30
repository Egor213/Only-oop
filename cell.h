#ifndef cell_h
#define cell_h
#include <iostream>

class Cell{

public:
    Cell(bool passability = 1);
    ~Cell();
    void setPassability(bool passability);
    bool getPassability();
    int* get_event();
    void set_event(int* event);
private:
    bool passability;
    //в будущем тут будет указатель на интерфеис события
    int* event = nullptr;
};  





#endif