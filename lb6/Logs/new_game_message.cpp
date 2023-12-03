#include "new_game_message.h"


NewGameMessage::NewGameMessage(Game* game, LogTracker* log_tracker) : game(game), log_tracker(log_tracker) {}


void NewGameMessage::update(LogEvent event)
{
    if (event == LogEvent::NEWGAME)
    {
        stats = {
            {LogsEnum::Height, game->field->getHeight()},
            {LogsEnum::Width, game->field->getWidth()},
            {LogsEnum::StartX, game->controller->getPosition().x},
            {LogsEnum::StartY, game->controller->getPosition().y}
        };
        log_tracker->update(LogObservers::NewGame);
    }
        
}

std::map<LogsEnum, std::any> NewGameMessage::getData()
{
    return stats;
}