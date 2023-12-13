#include "dont_command_message.h"

DontCommandMessage::DontCommandMessage(Game *game, LogTracker* log_tracker) : game(game), log_tracker(log_tracker) {}

void DontCommandMessage::update(LogEvent event)
{
    if (event == LogEvent::DONTCOMMAND)
    {
        stats = {
            {LogsEnum::Key, game->manage->getKey()}};
        log_tracker->update(LogObservers::DontCommand);
    }
}

std::map<LogsEnum, std::any> DontCommandMessage::getData()
{
    return stats;
}