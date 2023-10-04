#ifndef field_cpp
#define field_cpp
#include <iostream>
#include "cell.h"
#include "point.h"
#include <algorithm>

class Field{
    
public:

    Field(unsigned height = 3, unsigned width = 3);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();
    Point getStart() const;
    Point getExit() const;
    bool setStart(Point start);
    bool setExit(Point end);
    unsigned getWidth() const;
    unsigned getHeight() const;
	Cell& getCell(unsigned x, unsigned y);
    
private:
	Cell** arr_cells;
    Point start;
    Point exit;
    unsigned width;
    unsigned height;
    void initField(unsigned width, unsigned height);
    void swaps(Field& first, Field& second);
};

#endif
