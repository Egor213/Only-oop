
#include "Game/game.h"
#include "View/view.h"

int main(void)
{
    /* Game game(10, 2);
    Management input;
    game.setManagement(&input);
    game.run(); */
    /* SetFileManagement test("Managment/rule.txt");   
    Game game(10, 2);
    game.setManage(&test);
    game.run(); */
   // ConsoleCommandRead pricolchick(test);
     Management test;
    Game game(10, 2);
    game.setManage(&test);
    View view(&game);
    game.run(); 

    return 0;
}
