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
    Field field;
    Controller cont(mob, field, 2, 1);
    View view(field, cont);
    GenField a(field, cont, 1);

    std::cout << "\n";
    view.printField();
    std::cout << field.getCell(12,3).getEvent() << " - field1 BASE" <<'\n';
    Field field2(field);
    Controller cont2(mob, field2, 2, 1);
    View view2(field2, cont2);
    std::cout << field2.getCell(12,3).getEvent() << " - field2 NO BASE" <<'\n';
    //field.setExit({11, 17});
    /* field.setExit({0, 9});
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
    std::cout << "\n"; */

    return 0;
}
