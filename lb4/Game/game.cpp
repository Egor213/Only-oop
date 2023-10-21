#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game() : level(0), flag_run(0), field(nullptr), controller(nullptr), management(nullptr), hero(nullptr), com(nullptr)
{
}

Game::~Game()
{
    std::cout << "Game деструктор\n";
    cleanPtr();
}

void Game::initGame(unsigned hp, unsigned atk, unsigned level)
{
    this->hero = new Hero(hp, atk);
    this->field = new Field(1, 1);
    this->level = level;
    this->controller = new Controller(*hero, *field, 0, 0);
    GenField create;
    create.generate(*field, *controller, level);
    controller->setPosition(field->getStart().x, field->getStart().y);
    this->com = new InputCommand("Managment/rule.txt", *controller);
     
}



void Game::view() const
{
    View test(*field, *controller);
    com->control_scheme();
    test.printHero();
    test.printField();
}

void Game::cleanPtr()
{
    delete hero;
    delete field;
    delete controller;
    delete management;
}

bool Game::isEnd()
{
    if (hero->getStat(HP) <= 0)
    {
        return 1;
    }
    return 0;
}

void Game::step()
{
    com->stepCommand();
    if (isEnd())
    {
        system("clear");
        view();
        if (controller->getPosition() == field->getExit())
        {
            std::cout << "Поздравляем с победой!\n";
        }
        else
        {
            std::cout << "Игра закончена!\nВаше здоровье меньше нуля!\n";
        }
        
        cleanPtr();
        exit(0);
    }
}

#endif