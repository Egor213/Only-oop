#ifndef view_console_h
#define view_console_h
#include "game_tracker.h"
#include "../Game/game.h"
#include "iview.h"

class GameTracker;
class Game;

class ViewConsole: public IView
{
public:
    ViewConsole(Game* game);
    ~ViewConsole();
    void update();

private:
    Game* game;
    GameTracker* game_tracker;
    void viewManage();
    void viewField();

};


#endif