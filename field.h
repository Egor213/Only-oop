#ifndef field_cpp
#define field_cpp
#include <iostream>
#include "cell.h"
#include "point.h"
#include <algorithm>
class Field{
    
public:

    Field(int height = 0, int width = 0);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();

    void print_field();
    Cell** array_cells;
    

    Point get_coords_start();
    Point get_coords_end();
    bool set_coords_start(Point start);
    bool set_coords_end(Point end);
    int get_width();
    int get_height();

    
private:
    Point start_position;
    Point end_position;
    int width;
    int height;
    void del_field(int width);
    void init_field(int width, int height);
};

#endif