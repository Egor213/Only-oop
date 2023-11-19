#ifndef VIEW_CPP
#define VIEW_CPP
#include "view.h"

View::View(Field &field, const Controller &controller) : field(field), controller(controller) {}

void View::printField() const
{
    std::cout << "Вход - X: " << field.getStart().x << " Y: " << field.getStart().y << '\n';
    std::cout << "Выход - X: " << field.getExit().x << " Y: " << field.getExit().y << '\n';
    for (int i = field.getHeight()-1; i >= 0  ; i--)
    {
        for (int j = 0; j < field.getWidth(); j++)
        {
            
            if (field.getCell(j, i).getPassability() == 1)
            {
                if (j == (controller.getPosition().x) && i == (controller.getPosition().y))
                    std::cout << '@';
                else
                    std::cout << ' '; 
            }
            else
            {
                std::cout << '*';
            }
                
            
        }
        std::cout << '\n';
    }
}

void View::printFieldPassability() const
{
    for (int i = 0; i < field.getHeight(); ++i)
    {
        for (int j = 0; j < field.getWidth(); ++j)
        {
            std::cout << field.getCell(i, j).getPassability();
        }
        std::cout << '\n';
    }
}

void View::printHero() const
{
    std::cout << controller.getStat(HP) << u8"\u2764" << " - heal_points" << '\n'
              << controller.getStat(ATK) << u8"\u2694" << " - attack" << '\n'
              << controller.getStat(EXP) << u8"\u2022" << " - experience" << '\n'
              << "X: " << controller.getPosition().x << " Y: " << controller.getPosition().y << " - current pos" << '\n';
}

#endif