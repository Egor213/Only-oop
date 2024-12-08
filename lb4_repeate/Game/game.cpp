#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game(unsigned hp, unsigned atk) : hp(hp), atk(atk), level(3), field(nullptr), controller(nullptr), hero(nullptr), manage(nullptr){}

Game::~Game()
{
    cleanPtr();
}

void Game::run()
{
    initGame();
    View view(*field, *controller); // НЕ ЗАБЫТЬ УДАЛИТЬ
    while (1)
    {
        system("clear");// НЕ ЗАБЫТЬ УДАЛИТЬ 
        view.printField();// НЕ ЗАБЫТЬ УДАЛИТЬ
        
        stepCommand();
    }
}

void Game::getLvl()
{
    std::cout << "Введите номер уровень 0 или 1: ";
    std::cin >> this->level;
    std::cin.ignore(100, '\n');
    checkCin(level);
}

void Game::checkCin(unsigned temp)
{
    if (std::cin.fail())
    {
        temp = 0;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

void Game::setManage(Management *manage)
{
    this->manage = manage;
}

void Game::initGame()
{
    getLvl();
    this->hero = new Hero(hp, atk);
    this->create = new GenField(level);
    this->field = create->getField();
    this->controller = new Controller(*hero, *field);
    create->generateEvents(*controller);
    controller->setPosition(field->getStart().x, field->getStart().y);
}

void Game::cleanPtr()
{
    delete hero;
    delete controller;
    delete create;
}

void Game::isEnd()
{
    if (hero->getStat(HP) <= 0)
    {
        int temp = 0;
        std::cin >> temp;
        checkCin(temp);
        if (temp == 0)
            finishGame();
        cleanPtr();
        initGame();
    }
}



void Game::stepCommand()
{
    Command it = manage->getCommand();
    switch (it)
    {
    case Command::Invalid:
        std::cout << "Введена неверная клавиша\n";
        break;
    case Command::Quit:
        finishGame();
        break;
    case Command::Restart:
        std::cout << "Рестарт\n";
        cleanPtr();
        initGame();
        break;
    default:
        controller->step(it);
        isEnd();
        break;
    }
}

void Game::finishGame()
{
    std::cout << "Выход из игры\n";
    cleanPtr();
    exit(0);
}



#endif