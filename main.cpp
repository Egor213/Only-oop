#include <iostream>
#include "hero.h"
#include "controller.h"
#include "cell.h"
#include "field.h"
int main(void){
    Hero mob("hero", 1,0,4);
    Field game_field(10,10);
    game_field.set_coords_start({1,2});
    Controller controller_mob(mob, game_field, 5, 0);
    std::cout << '\n';
   // controller_mob.step(controller_mob.Down);
    mob.getInformation();
    std::cout << '\n';
    game_field.print_field();
    Field field = game_field;
    std::cout << '\n';
    field.print_field();

    return 0;
}   
