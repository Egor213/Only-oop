#include "win_message.h"

WinMessage::WinMessage(Game* game, LogTracker* log_tracker) : game(game), log_tracker(log_tracker) {}

void WinMessage::update(LogEvent event)
{
    if (event == LogEvent::WIN)
    {
        stats = {
            {LogsEnum::HealPoint, game->controller->getStat(HP)},
            {LogsEnum::Attack, game->controller->getStat(ATK)},
            {LogsEnum::Experience, game->controller->getStat(EXP)}
        };
        log_tracker->update(LogObservers::WinGame);
    }
        
}

std::map<LogsEnum, std::any> WinMessage::getData()
{
    return stats;
}