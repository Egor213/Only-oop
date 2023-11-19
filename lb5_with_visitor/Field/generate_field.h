#ifndef generate_field_h
#define generate_field_h
#include "field.h"
#include "../Events/eventPattern.h"
#include "../Events/buffEvent.h"
#include "../Events/teleportEvent.h"
#include "../Game/controller.h"
#include "../Events/kill.h"
#include "../Events/debuffEvent.h"
#include "../Managment/read_file.h"
#include <sstream>
class GenField
{
public:
    GenField(unsigned level);
    ~GenField();
    void generateEvents(Controller& controller);
    Field* getField();
private:
    Field* field;
    unsigned level;
    unsigned width;
    unsigned height;
    std::vector<std::string> charVector;
    void generateFieldLv1();
    void generateFieldLv2();
    void placeEventLv1(Controller &controller);
    void placeEventLv2(Controller &controller);
    std::vector<std::string> parseFile(const std::string &file_name);
};

#endif