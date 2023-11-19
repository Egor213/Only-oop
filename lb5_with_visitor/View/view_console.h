#ifndef view_console_h
#define view_console_h
#include "game_tracker.h"
#include "../Game/game.h"
#include "iview.h"
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <typeinfo>
#include "view_console_events.h"
class GameTracker;
class Game;

class ViewConsole: public IView
{
public:
    ViewConsole(Game* game);
    ~ViewConsole();
    void update();
    void updateChooseLvl();
    void updateEndGame();
    void updateRestart();
    void updateEndGameLessHp();
    void updateInvalideKey();
    
    //EVENTS
    void viewBuffEvent();
    void viewDebuffEvent();
    void viewKillEvent();
    void viewTeleportEvent();

private:
    Game* game;
    GameTracker* game_tracker;
    void viewManage();
    void viewField();
    void viewHero();



};


#endif