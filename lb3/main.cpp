#include <iostream>
#include "hero.h"
#include "controller.h"
#include "Field/cell.h"
#include "Field/field.h"
#include <algorithm>
#include <numeric>
#include "view.h"
#include "Field/generate_field.h"
int main(void)
{
    Hero mob(1, 0, 4);
    Field field(15, 15);
    Controller cont(mob, field, 2, 1);
    View view(field, cont);
    for (int i = 1; i < 6; i++)
        field.getCell(i, 3).setPassability(false);
    GenField a(field, cont);
    field.setExit({0, 9});
    field.setStart({14, 13});
    field.getCell(2, 1).setView('@');
    std::cout << "\n";
    view.printHero();
    cont.step(Left);
    std::cout << "\n";
    view.printHero();
    std::cout << "\n";
   // field.getCell(1, 1).callEvent();
    
    std::cout << "\n";
    view.printField();
    std::cout << "\n";

    return 0;
}
