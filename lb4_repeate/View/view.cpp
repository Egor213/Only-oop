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
    viewManage();
    viewField();
}

void View::viewManage()
{
    std::map<Command, char> bind_key_map = game->manage->getBindKey();
    bind_key_map.erase(Command::Invalid);
    std::map<Command, std::string> convert_map = {
        {Command::MoveDown, "MoveDown"},
        {Command::MoveLeft, "MoveLeft"},
        {Command::MoveUp, "MoveUp"},
        {Command::MoveRight, "MoveRight"},
        {Command::Restart, "Restart"},
        {Command::Quit, "Quit"}};
    for (auto per : bind_key_map)
        std::cout << convert_map[per.first] << ": " << per.second << '\n';
}

void View::viewField()
{
    for (int i = game->field->getHeight() - 1; i >= 0; i--)
    {
        for (int j = 0; j < game->field->getWidth(); j++)
        {

            if (!game->field->getCell(j, i).getPassability())
                std::cout << '*';
            else
            {
                if (game->controller->getPosition().x == j && game->controller->getPosition().y == i)
                {
                    std::cout << '@';
                }
                else if (game->field->getExit().x == j && game->field->getExit().y == i)
                {
                    std::cout << 'E';
                }
                else
                    std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}