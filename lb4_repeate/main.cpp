#include <iostream>
#include "Entity/hero.h"
#include "Game/controller.h"
#include "Field/cell.h"
#include "Field/field.h"
#include <algorithm>
#include <numeric>
#include "Game/view.h"
#include "Field/generate_field.h"
#include "Game/game.h"
#include "Managment/read_file.h"
#include <vector>
#include <string>

#include <chrono>
#include <thread>
#include "Managment/setfilemanagement.h"
#include "Managment/console_read.h"
int main(void)
{
    /* Game game(10, 2);
    Management input;
    game.setManagement(&input);
    game.run(); */
    SetFileManagement test("Managment/rule.txt");   
    Game game(10, 2);
    game.setManage(&test);
    game.run();
   // ConsoleCommandRead pricolchick(test);
   
    
    return 0;
}
