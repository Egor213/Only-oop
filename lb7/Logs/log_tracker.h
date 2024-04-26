#ifndef log_tracker_h
#define log_tracker_h
#include "../Game/game.h"
#include <ctime>

#include "win_message.h"
#include "new_game_message.h"
#include "dont_command_message.h"
#include "do_command_message.h"
#include "lose_message.h"
#include "manage_logs.h"

class WinMessage;
class LoseMessage;
class NewGameMessage;
class DontCommandMessage;
class DoCommandMessage;

enum class LogObservers
{
    DoCommand,
    DontCommand,
    NewGame,
    WinGame,
    LoseGame
};

class LogTracker
{
public:
    LogTracker(Game* game);
    ~LogTracker();
    void update(LogObservers);
    
   
private:
    Game* game;
    WinMessage* win;
    LoseMessage* lose;
    NewGameMessage* new_game_mess;
    DontCommandMessage* dont_mess;
    DoCommandMessage* do_mess;

    ManageLogs* manage_out;
  
   std::vector<std::ostream*> outs;


};

#endif