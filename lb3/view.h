#ifndef VIEW_H
#define VIEW_H
#include "Field/field.h"
#include "controller.h"

class View
{
public:
    View(Field &field, const Controller &controller);
    void printField() const;
    void printHero() const;
    void printFieldPassability() const;
private:
    Field &field;
    const Controller &controller;
};

#endif