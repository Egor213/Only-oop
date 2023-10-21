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
#include "Managment/management.h"
int main(void)
{
    Game game;
    game.initGame(10, 2, 1);
    while(1)
    {
        system("clear");
        game.view();
        game.step();
    }
    
    
    return 0;
}
