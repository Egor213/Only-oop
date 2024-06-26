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
    while (1)
    {   
        stepCommand();
    }
}

void Game::getLvl()
{
    notify(ViewEvent::ChooseLvl);
    std::cin >> this->level;
    std::cin.ignore(100, '\n');
    checkCin(level);
    
}

void Game::checkCin(unsigned& temp)
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
    notify(ViewEvent::InitGame);
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
        notify(ViewEvent::EndGameLessHp);
        unsigned temp = 0;
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
        notify(ViewEvent::InvalidKey);
        break;
    case Command::Quit:
        finishGame();
        break;
    case Command::Restart:
        notify(ViewEvent::Restart);

        cleanPtr();
        initGame();
        break;
    default:
        controller->step(it);
        notify(ViewEvent::ChangeCoords);
        isEnd();
        break;
    }
}

void Game::finishGame()
{
    notify(ViewEvent::EndGame);
    cleanPtr();
    exit(0);
}

void Game::addObserver(Observer* apObserver)
{
    observers.push_back(apObserver);
}

void Game::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Game::notify(ViewEvent view_event)
{
    for (Observer* observer : observers)
        observer->update(view_event);
}



#endif