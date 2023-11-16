#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game(unsigned hp, unsigned atk) : hp(hp), atk(atk), level(3), field(nullptr), controller(nullptr), hero(nullptr)
{}

Game::~Game()
{
    cleanPtr();
}

void Game::run()
{
    initGame();
    while (1)
    {
        stepCommand();
    }
}

void Game::getLvl()
{
    std::cout << "Введите номер уровень 0 или 1: ";
    std::cin >> this->level;
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

void Game::setManage(ISetManagement *manage)
{
    this->manage = manage;
    bind_command_map = manage->getKeyManagement();
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
    reader = new ConsoleCommandRead(manage);  // можно менять под условия (считывание из терминала)
}

void Game::cleanPtr()
{
    delete hero;
    delete controller;
    delete create;
    delete reader;
}

void Game::isEnd()
{
    if (hero->getStat(HP) <= 0)
    {
        if (controller->getPosition() == field->getExit())
            std::cout << "Поздравляем с победой!\n";
        else
            std::cout << "Игра закончена!\nВаше здоровье меньше нуля!\n";

        std::cout << "Завершите программу - 0 или совершите рестарт - 1: ";
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
    Command it = reader->read();
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
        std::cout << "x: " << controller->getPosition().x << "y: " << controller->getPosition().y << '\n';
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