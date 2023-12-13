#include "game_tracker.h"

GameTracker::GameTracker(Game *game, IView *view) : game(game), view(view)
{
    game->addObserver(this);
}

void GameTracker::update(ViewEvent view_event)
{
    std::map<ViewEvent, std::function<void(IView *)>> choose_map = {
        {ViewEvent::ChooseLvl, [](IView *obj)
         {
             return obj->updateChooseLvl();
         }},
        {ViewEvent::EndGameLessHp, [](IView *obj)
         {
             return obj->updateEndGameLessHp();
         }},
        {ViewEvent::EndGame, [](IView *obj)
         {
             return obj->updateEndGame();
         }},
        {ViewEvent::Restart, [](IView *obj)
         {
             return obj->updateRestart();
         }},
        {ViewEvent::InvalidKey, [](IView *obj)
         {
             return obj->updateInvalideKey();
         }},
        {ViewEvent::InitGame, [](IView *obj)
         {
             return obj->update();
         }},
        {ViewEvent::ChangeCoords, [](IView *obj)
         {
             return obj->update();
         }},

    };
    choose_map[view_event](view);
}
