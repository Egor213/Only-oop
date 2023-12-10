#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game(unsigned hp, unsigned atk) : hp(hp), atk(atk), level(3), field(nullptr), controller(nullptr), hero(nullptr), manage(nullptr), game_flag(true)
{
    log_tracker = new LogTracker;
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

void Game::checkCin(unsigned &temp)
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
    NewGameMessage new_game_mess(field->getHeight(), field->getWidth(), field->getStart().x, field->getStart().y);
    log_tracker->update(new_game_mess);
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
        {
            WinMessage win_message(controller->getStat(HP), controller->getStat(ATK), controller->getStat(EXP));
            log_tracker->update(win_message);
        }
        else
        {
            LoseMessage lose_message(controller->getPosition().x, controller->getPosition().y);
            log_tracker->update(lose_message);
        }

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

void Game::stepCommand()
{
    Command it = manage->getCommand();
    switch (it)
    {
    case Command::Invalid:
    {
        notify(ViewEvent::InvalidKey);
        DontCommandMessage dont_command_message(manage->getKey());
        log_tracker->update(dont_command_message);
        break;
    }

    case Command::Quit:
    {
        finishGame();
        DoCommandMessage do_message(manage->getKey(), it);
        log_tracker->update(do_message);
        break;
    }

    case Command::Restart:
    {
        notify(ViewEvent::Restart);
        DoCommandMessage do_message(manage->getKey(), it);
        log_tracker->update(do_message);
        cleanPtr();
        initGame();
        break;
    }

    default:
    {
        controller->step(it);
        notify(ViewEvent::ChangeCoords);
        DoCommandMessage do_message(manage->getKey(), it);
        log_tracker->update(do_message);
        isEnd();
        break;
    }
    }
}

void Game::finishGame()
{
    notify(ViewEvent::EndGame);
    game_flag = false;
}

void Game::addObserver(Observer *apObserver)
{
    observers.push_back(apObserver);
}

void Game::removeObserver(Observer *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Game::notify(ViewEvent view_event)
{
    for (Observer *observer : observers)
        observer->update(view_event);
}

#endif