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
    Management input;
    game.setManagement(&input);
    game.run();
 
    
    return 0;
}
