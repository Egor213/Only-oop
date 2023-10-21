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
#include <chrono>
#include <thread>
int main(void)
{
    Game game(10, 2);
    game.initGame();
    
     while(1)
    {
        system("clear");
        game.view();
        if (!game.getFlagFile())
        {
            game.stepConsole();
        }
        else
        {
            game.stepFile();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
            
        
    }

    return 0;
}
