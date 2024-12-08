#include "view_console.h"

ViewConsole::ViewConsole(Game *game) : game(game), game_tracker(new GameTracker(game, this))
{
}

ViewConsole::~ViewConsole()
{
    delete game_tracker;
}

void ViewConsole::update()
{
    system("clear");
    viewManage();
    std::cout << std::string(30, '-') << '\n';
    viewHero();
    std::cout << std::string(30, '-') << '\n';
    viewField();
}

void ViewConsole::updateChooseLvl()
{
    std::cout << "Введите номер уровень 0 или 1: ";
}

void ViewConsole::updateRestart()
{
    update();
    std::cout << "Рестарт!\n";
}

void ViewConsole::updateEndGameLessHp()
{
    update();
    if (game->controller->getPosition() == game->field->getExit())
        std::cout << "Поздравляем с победой!\n";
    else if (game->controller->getStat(HP) < 1)
        std::cout << "Игра закончена!\nВаше здоровье меньше нуля!\n";
    else 
        std::cout << "Игра закончена!\n";
    std::cout << "Завершите программу - 0 или совершите рестарт - 1: ";
}

void ViewConsole::updateEndGame()
{
    update();
    std::cout << "Игра закончена!\n";
}

void ViewConsole::updateInvalideKey()
{
    update();
    std::cout << "Введена неверная клавиша!\n";
}

void ViewConsole::viewManage()
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

void ViewConsole::viewField()
{
    ViewConsoleEvent visitor = ViewConsoleEvent(*this);
    for (int i = game->field->getHeight() - 1; i >= 0; i--)
    {
        for (int j = 0; j < game->field->getWidth(); j++)
        {

            if (!game->field->getCell(j, i).getPassability())
                std::cout << '*';
            else
            {
                if (game->controller->getPosition().x == j && game->controller->getPosition().y == i)
                    std::cout << '@';
                else if (game->field->getExit().x == j && game->field->getExit().y == i)
                    std::cout << 'E';
                else if (game->field->getStart().x == j && game->field->getStart().y == i)
                    std::cout << 'S';
                else if (game->field->getCell(j, i).getEvent() != nullptr)
                    game->field->getCell(j, i).getEvent()->acceptVisitor(visitor);
                else
                    std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

void ViewConsole::viewHero()
{
    std::cout << game->controller->getStat(HP) << u8"\u2764" << " - heal_points" << '\n'
              << game->controller->getStat(ATK) << u8"\u2694" << " - attack" << '\n'
              << game->controller->getStat(EXP) << u8"\u2022" << " - experience" << '\n'
              << "X: " << game->controller->getPosition().x << " Y: " << game->controller->getPosition().y << " - current pos" << '\n';
}


void ViewConsole::viewBuffEvent()
{
    std::cout << 'b';
}

void ViewConsole::viewDebuffEvent()
{
    std::cout << 'd';
}

void ViewConsole::viewKillEvent()
{
    std::cout << 'k';
}

void ViewConsole::viewTeleportEvent()
{
    std::cout << 't';
}