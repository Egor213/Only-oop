#ifndef field_h
#define field_h
#include "field.h"
const unsigned MIN_SIZE_FIELD = 3;
const unsigned MAX_SIZE_FIELD = 100;

Field::Field(unsigned height, unsigned width) : start({0, 0}), exit({0, 0})
{
    this->width = std::clamp(width, MIN_SIZE_FIELD, MAX_SIZE_FIELD);
    this->height = std::clamp(height, MIN_SIZE_FIELD, MAX_SIZE_FIELD);
    initField(this->width, this->height);
}

Field::Field(const Field &other) : width(other.width), height(other.height)
{
    initField(width, height);
    start = other.start;
    exit = other.exit;
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            arr_cells[i][j] = other.arr_cells[i][j];
        }
    }
}

Field &Field::operator=(const Field &other)
{
    if (this != &other)
    {
        Field temp(other);
        swaps(*this, temp);
    }
    return *this;
}

Field::Field(Field &&other)
{
    swaps(*this, other);
}

Field &Field::operator=(Field &&other)
{
    if (this != &other)
        swaps(*this, other);
    return *this;
}

Field::~Field()
{
    for (int i = 0; i < width; ++i)
    {
        delete[] arr_cells[i];
    }
    delete[] arr_cells;
}


bool Field::setExit(Point end)
{
    if (end.x < width && end.y < height)
    {
        exit = end;
        return true;
    }
    return false;
}
bool Field::setStart(Point start)
{
    if (start.x < width && start.y < height)
    {
        this->start = start;
        return true;
    }
    return false;
}
Point Field::getStart() const
{
    return start;
}
Point Field::getExit() const
{
    return exit;
}

unsigned Field::getHeight() const
{
    return height;
}
unsigned Field::getWidth() const
{
    return width;
}

Cell &Field::getCell(unsigned x, unsigned y)
{
    return arr_cells[x][y];
}


void Field::swaps(Field& first, Field& second)
{
    std::swap(first.start, second.start);
    std::swap(first.exit, second.exit);
    std::swap(first.width, second.width);
    std::swap(first.height, second.height);
    std::swap(first.arr_cells, second.arr_cells);
}

void Field::initField(unsigned width, unsigned height)
{
    arr_cells = new Cell *[width];
    for (int i = 0; i < width; ++i)
    {
        arr_cells[i] = new Cell[height];
    }
}

#endif
