#include "game_tracker.h"


GameTracker::GameTracker(Game* game, IView* view) : game(game), view(view)
{
    game->addObserver(this);
}

void GameTracker::update(ViewEvent view_event)
{
    view->update();
}

