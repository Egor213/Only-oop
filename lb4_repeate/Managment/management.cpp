#include "management.h"

Management::Management()
{    
    setter = getSetters();
    reader = getReaders(setter);
}

Management::~Management()
{
    delete reader;
    delete setter;
}

void Management::checkCin(unsigned temp)
{
    if (std::cin.fail())
    {
        temp = 0;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }
}

ISetManagement* Management::getSetters()
{
    std::map<int, Setters> setters_map = {
        {0, Setters::File},
        {1, Setters::Console}};
    int temp;
    while (1)
    {
        std::cout << "Введите номер откуда будет происходить считывание управления\n\t0 - считывание из файла\n\t1 - считывание из терминала\n";
        std::cin >> temp;
        checkCin(temp);
        if (hasNumberMap(temp, setters_map))
        {
            switch (setters_map[temp])
            {
            case Setters::File:
                return new SetFileManagement("Managment/rule.txt");
            case Setters::Console:
                return new SetConsoleManagement;
            }
        }
        else
            std::cout << "Введите другое значение!\n";
             
    }
}

ICommandRead* Management::getReaders(ISetManagement* setter)
{
    std::map<int, Readers> readers_map = {
        {0, Readers::File},
        {1, Readers::Console}};
    int temp;
    while (1)
    {
        std::cout << "Введите номер откуда будет происходить считывание взаимодействия с игрой\n\t0 - считывание из файла\n\t1 - считывание из терминала\n";
        std::cin >> temp;
        checkCin(temp);
        if (hasNumberMap(temp, readers_map))
        {
            switch(readers_map[temp])
            {
                case Readers::Console:
                    std::cin.ignore(100, '\n');
                    return new ConsoleCommandRead(setter);
                case Readers::File:
                    return new FileCommandRead(setter, "Managment/commands.txt");
            }

        }
        else
            std::cout << "Введите другое значение!\n";
    }
}

Command Management::getCommand()
{
    return reader->read();
}

std::map<Command, char> Management::getBindKey()
{
    return reader->getBind();
}