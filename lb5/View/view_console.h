#ifndef view_console_h
#define view_console_h
#include "game_tracker.h"
#include "../Game/game.h"
#include "iview.h"
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <typeinfo>

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

private:
    Game* game;
    GameTracker* game_tracker;
    void viewManage();
    void viewField();
    void viewHero();
    char getCharEvent(GameEvent*);


};


#endif