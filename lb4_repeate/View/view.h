#ifndef view_h
#define view_h
#include "game_tracker.h"
#include "../Game/game.h"

class GameTracker;
class Game;

class View
{
public:
    View(Game* game);
    ~View();
    void update();

private:
    Game* game;
    GameTracker* game_tracker;

};


#endif