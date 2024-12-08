#ifndef game_tracker_h
#define game_tracker_h

#include "observer.h"
#include <iostream>
#include "../Game/game.h"
#include "view_console.h"
#include "iview.h"
class ViewConsole;
class Game;

class GameTracker: public Observer
{

public:
    GameTracker(Game* game, IView* view);
    void update(ViewEvent view_event) override;

private:
    Game* game;
    IView* view;

};


#endif