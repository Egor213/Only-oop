#include "game_tracker.h"


GameTracker::GameTracker(Game* game, IView* view) : game(game), view(view)
{
    game->addObserver(this);
}

void GameTracker::update(ViewEvent view_event)
{
    switch (view_event)
    {
    case ViewEvent::ChooseLvl:
        view->updateChooseLvl();
        break;
    
    case ViewEvent::EndGameLessHp:
        view->updateEndGameLessHp();
        break;
    
    case ViewEvent::EndGame:
        view->updateEndGame();
        break;

    case ViewEvent::Restart:
        view->updateRestart();
        break;

    case ViewEvent::InvalidKey:
        view->updateInvalideKey();
        break;

    default:
        view->update();
        break;
    }
    
}

