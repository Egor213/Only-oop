#include "Game/game.h"
#include "View/view_console.h"
#include "Logs/manage_logs.h"



#include "Enemys/move_random.h"
#include "Enemys/interaction_atk.h"
#include "Enemys/enemy.h"


int main(void)
{
    Management test;
    Game game(10, 2);
    game.setManage(&test);
    ViewConsole view(&game);
    
   // ManageLogs log();
    game.run(); 

    return 0;
}
