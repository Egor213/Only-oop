#ifndef generate_field_h
#define generate_field_h
#include "field.h"
#include "../Events/eventPattern.h"
#include "../Events/buffEvent.h"
#include "../Events/teleportEvent.h"
#include "../Game/controller.h"
#include "../Events/kill.h"
#include "../Events/debuffEvent.h"
class GenField
{
public:
    GenField() = default;
    void generate(Field &field, Controller &controller, unsigned level);
private:
    void generateFieldLv1(Field &field, Controller &controller);
    void generateFieldLv2(Field &field, Controller &controller);
    void placeEventLv1(Field &field, Controller &controller);
    void placeEventLv2(Field &field, Controller &controller);
};

#endif