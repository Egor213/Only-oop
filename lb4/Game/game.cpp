#ifndef game_cpp
#define game_cpp
#include "game.h"

Game::Game(unsigned hp, unsigned atk) : hp(hp), atk(atk), level(3), counter_file_command(0), flag_file(false), field(nullptr), controller(nullptr), hero(nullptr)
{
    command_map = {
        {Command::MoveUp, Up},
        {Command::MoveDown, Down},
        {Command::MoveRight, Rigth},
        {Command::MoveLeft, Left},
    };
}

Game::~Game()
{
    std::cout << "Game деструктор\n";
    cleanPtr();
}

void Game::initGame(bool restart_flag)
{
    std::cout << "Введите номер уровень 0 или 1: ";
    std::cin >> level;
    std::cout << "Введите 0, если игра из консоли, иначе игра из файла: ";
    std::cin >> flag_file;
    if (flag_file)
        arr_commands = management.commandFile("Managment/commands.txt");
    if (!restart_flag)
        key_map = management.bindKey("Managment/rule.txt");
    this->hero = new Hero(hp, atk);
    this->field = new Field(1, 1);
    this->level = level;
    this->controller = new Controller(*hero, *field);
    GenField create;
    create.generate(*field, *controller, level);
    controller->setPosition(field->getStart().x, field->getStart().y);
}

void Game::view() const
{
    View test(*field, *controller);
    management.control_scheme();
    test.printHero();
    test.printField();
}

void Game::cleanPtr()
{
    delete hero;
    delete field;
    delete controller;
}

bool Game::isEnd()
{
    if (hero->getStat(HP) <= 0)
    {
        return 1;
    }
    return 0;
}

void Game::stepConsole()
{
    stepCommand();
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

        std::cout << "Завершите программу - 0 или совершите рестарт - 1: ";
        int temp = 0;
        std::cin >> temp;
        if (temp == 0)
        {
            finishGame();
        }
        else
        {
            cleanPtr();
            initGame(true);
        }
    }
}

Command Game::getKeyByValue(const std::map<Command, char> &key_map, const char &value)
{
    for (const auto &pair : key_map)
    {
        if (pair.second == value)
        {
            return pair.first;
        }
    }
    return Command::Invalid;
}

void Game::stepCommand()
{
    char temp;
    system("stty raw");
    std::cout << "Введите клавишу: ";
    temp = getchar();
    system("stty cooked echo");
    Command it = getKeyByValue(key_map, temp);
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
        initGame(true);
        break;
    default:
        controller->step(command_map[it]);
        break;
    }
    std::cout << "\033[F";
    std::cout << "\033[K";
    system("stty cooked echo");
}

void Game::finishGame()
{
    std::cout << "Выход из игры\n";
    cleanPtr();
    exit(0);
}

bool Game::getFlagFile()
{
    return flag_file;
}

void Game::stepFile()
{
    switch (arr_commands[counter_file_command])
    {
    case Command::Quit:
        finishGame();
        break;
    default:
        controller->step(command_map[arr_commands[counter_file_command]]);
        counter_file_command++;
        break;
    }
    if (counter_file_command == arr_commands.size()+1)
        finishGame();
    
}

#endif