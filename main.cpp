#include <iostream>
#include "hero.h"
#include "controller.h"
int main(void){
    Hero mob("Dog", 1, 0, 4);
    Controller controller_mob(mob, 5, 0);
    std::cout << '\n';
    controller_mob.move(controller_mob.Down);
    mob.getInformation();
    std::cout << controller_mob.getPosition().x << ' ' << controller_mob.getPosition().y << '\n' ;
    return 0;
}   
