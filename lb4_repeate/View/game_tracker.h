#ifndef game_tracker_h
#define game_tracker_h

#include "observer.h"
#include <iostream>
#include "../Game/game.h"
#include "view.h"

class View;
class Game;

class GameTracker: public Observer
{

public:
    GameTracker(Game* game, View* view);
    void update(ViewEvent view_event) override;

private:
    Game* game;
    View* view;

};


#endif