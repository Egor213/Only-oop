#include "lose_message.h"


LoseMessage::LoseMessage(Game* game, LogTracker* log_tracker) : game(game), log_tracker(log_tracker) {}



void LoseMessage::update(LogEvent event) 
{
    if (event == LogEvent::LOSE)
    {
        stats = {
            {LogsEnum::LoseX, game->controller->getPosition().x},
            {LogsEnum::LoseY, game->controller->getPosition().y}
        };
        log_tracker->update(LogObservers::LoseGame);
    }
        
}

std::map<LogsEnum, std::any> LoseMessage::getData()
{
    return stats;
}
