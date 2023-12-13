#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game(unsigned hp, unsigned atk) : hp(hp), atk(atk), level(3), field(nullptr), controller(nullptr), hero(nullptr), manage(nullptr), game_flag(true){
    log_tracker = new LogTracker(this);
}

Game::~Game()
{
    cleanPtr();
    
}

void Game::run()
{
    initGame();
    while (game_flag)
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
    notifyLog(LogEvent::NEWGAME);
    
}

void Game::cleanPtr()
{
    delete hero;
    delete controller;
    delete create;
}

void Game::isEnd()
{
    if (hero->getStat(HP) <= 0 || controller->getPosition() == field->getExit())
    {
        notify(ViewEvent::EndGameLessHp);

        if (controller->getPosition() == field->getExit())
            notifyLog(LogEvent::WIN);
        else
            notifyLog(LogEvent::LOSE);
        
        unsigned temp = 0;
        std::cin >> temp;
        checkCin(temp);
        if (temp == 0)
            finishGame();
        else
        {
            cleanPtr();
            initGame();
        }
        
    }
}

Command Game::getLastCommand()
{
    return last_command;
}



void Game::stepCommand()
{
    Command it = manage->getCommand();
    last_command = it;
    switch (it)
    {
    case Command::Invalid:
        notify(ViewEvent::InvalidKey);
        notifyLog(LogEvent::DONTCOMMAND);
        break;
    case Command::Quit:
        finishGame();
        notifyLog(LogEvent::DOCOMMAND);
        break;
    case Command::Restart:
        notify(ViewEvent::Restart);
        notifyLog(LogEvent::DOCOMMAND);
        cleanPtr();
        initGame();
        break;
    default:
        controller->step(it);
        notify(ViewEvent::ChangeCoords);
        notifyLog(LogEvent::DOCOMMAND);
        isEnd();
        break;
    }
}

void Game::finishGame()
{
    notify(ViewEvent::EndGame);
    game_flag = false;
}

void Game::addObserver(Observer* apObserver)
{
    observers.push_back(apObserver);
}

void Game::addLogObserver(IMessage* aObserver)
{
    logs_observers.push_back(aObserver);
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

void Game::notifyLog(LogEvent event)
{
    for (IMessage* log_observer : logs_observers)
        log_observer->update(event);
}



#endif