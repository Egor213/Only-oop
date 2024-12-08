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
    cleanPtr();
}

void Game::run()
{
    initGame();
    while (1)
    {
        system("clear");
        view();
        if (!flag_file)
            stepCommand();
        else
        {
            stepFile();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void Game::getLvlFile()
{
    std::cout << "Введите номер уровень 0 или 1: ";
    std::cin >> this->level;
    checkCin(level);
    std::cout << "Введите 0, если игра из консоли, 1 - игра из файла: ";
    std::cin >> this->flag_file;
    checkCin(flag_file);
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

void Game::setManagement(Management *management)
{
    this->management = management;
    key_map = management->bindKey("Managment/rule.txt");
}

void Game::initGame()
{
    getLvlFile();
    if (flag_file)
        arr_commands = management->commandFile("Managment/commands.txt");
    this->hero = new Hero(hp, atk);
    this->create = new GenField(level);
    this->field = create->getField();
    this->controller = new Controller(*hero, *field);
    create->generateEvents(*controller);
    controller->setPosition(field->getStart().x, field->getStart().y);
}

void Game::view() const
{
    View test(*field, *controller);
    management->control_scheme();
    test.printHero();
    test.printField();
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
        system("clear");
        view();
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
    char temp = management->getCommand();
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
        initGame();
        break;
    default:
        controller->step(command_map[it]);
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



void Game::stepFile()
{
    counter_file_command = 0;
    if (arr_commands[counter_file_command] == Command::Quit)
    {
        finishGame();
    }
    else
    {
        controller->step(command_map[arr_commands[counter_file_command]]);
        counter_file_command++;
    }
    if (counter_file_command == arr_commands.size() + 1)
        finishGame();
}

#endif