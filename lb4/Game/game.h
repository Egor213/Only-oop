#ifndef game_h
#define game_h
#include "../Field/field.h"
#include "controller.h"
#include "../Managment/management.h"
#include "../Field/generate_field.h"
#include "../Game/view.h"
#include "../Managment/commands.h"
#include "../Managment/user_commands.h"
class Game
{
public:
    Game();
    ~Game();
    void initGame(unsigned hp, unsigned atk, unsigned level);
    void view() const;
    void step();
private:
    Field *field;
    Controller *controller;
    Management *management;
    InputCommand *com;
    Hero *hero;
    bool flag_run;
    unsigned level;
    void cleanPtr();
    bool isEnd();
};

#endif