#ifndef generate_field_h
#define generate_field_h
#include "field.h"
#include "../Events/eventPattern.h"
#include "../Events/buffEvent.h"
#include "../Events/teleportEvent.h"
#include "../controller.h"
#include "../Events/kill.h"
#include "../Events/debuffEvent.h"
class GenField
{
public:
    GenField(Field& field, Controller& controller, unsigned level = 0);
    

private:
    Field& field;
    Controller& controller;
    void generateFieldLv1();
    void generateFieldLv2();
    void placeEventLv1();
    void placeEventLv2();

};

#endif