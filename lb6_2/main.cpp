#include "Game/game.h"
#include "View/view_console.h"
#include "Logs/manage_logs.h"






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
