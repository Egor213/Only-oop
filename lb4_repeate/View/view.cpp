#include "view.h"

View::View(Game *game) : game(game), game_tracker(new GameTracker(game, this))
{
}

View::~View()
{
    delete game_tracker;
}

void View::update()
{
    system("clear");
    std::cout << "Вход - X: " << game->field->getStart().x << " Y: " << game->field->getStart().y << '\n';
    std::cout << "Выход - X: " << game->field->getExit().x << " Y: " << game->field->getExit().y << '\n';
    for (int i = game->field->getHeight() - 1; i >= 0; i--)
    {
        for (int j = 0; j < game->field->getWidth(); j++)
        {
            
            if (!game->field->getCell(j,i).getPassability())
                std::cout << '*';
            else
            {
                if (game->controller->getPosition().x == j && game->controller->getPosition().y == i)
                    std::cout << '@';
                else
                    std::cout << ' ';
            }
                
        }
        std::cout << '\n';
    }
}