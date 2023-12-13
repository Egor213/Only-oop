#include "do_command_message.h"

DoCommandMessage::DoCommandMessage(Game *game, LogTracker* log_tracker) : game(game), log_tracker(log_tracker) {}

void DoCommandMessage::update(LogEvent event)
{
    if (event == LogEvent::DOCOMMAND)
    {
        stats = {
            {LogsEnum::Key, game->manage->getKey()},
            {LogsEnum::Commands, game->getLastCommand()}};
        log_tracker->update(LogObservers::DoCommand);
    }

}

std::map<LogsEnum, std::any> DoCommandMessage::getData()
{
    return stats;
}


