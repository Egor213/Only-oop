#ifndef generate_field_cpp
#define generate_field_cpp
#include "generate_field.h"

GenField::GenField(unsigned level) : width(0), height(0)
{

    this->level = level;
    if (level == 0)
    {
        charVector = parseFile("Field/map1.txt");
        field = new Field(height, width);
    }
    else
    {
        charVector = parseFile("Field/map2.txt");
        field = new Field(height, width);
    }

    if (level == 0)
    {
        generateFieldLv1();
        field->setStart({14, 13});
        field->setExit({0, 9});
    }
    else
    {
        generateFieldLv2();
        field->setStart({14, 18});
        field->setExit({0, 2});
    }
}

void GenField::generateEvents(Controller &controller)
{
    if (level == 0)
        placeEventLv1(controller);
    else
        placeEventLv2(controller);
}

Field *GenField::getField()
{
    return field;
}

GenField::~GenField()
{
    delete field;
}

std::vector<std::string> GenField::parseFile(const std::string &file_name)
{
    ReadFile file(file_name);
    std::vector<std::string> arr_game = file.read();
    std::istringstream iss(arr_game[0] + arr_game[1]);
    std::string temp_width;
    std::string temp_height;
    iss >> temp_height >> width >> temp_width >> height;
    if (temp_width != "width:" || temp_height != "height:" || height < 3 || height > 100 || width < 3 || width > 100)
    {
        throw std::runtime_error("Ошибка считывания");
    }
    arr_game.erase(arr_game.begin(), arr_game.begin() + 2);
    for (int i = 0; i < arr_game.size(); i++)
    {
        size_t found = arr_game[i].find('\n');
        while (found != std::string::npos)
        {
            arr_game[i].erase(found, 1);
            found = arr_game[i].find('\n');
        }
        if (arr_game[i].length() != height || arr_game.size() != width)
        {
            throw std::runtime_error("Ошибка считывания");
        }
    }
    return arr_game;
}

void GenField::generateFieldLv1()
{
    for (int i = 0; i < charVector.size(); i++)
    {
        for (int j = 0; charVector[i][j]; j++)
        {
            field->getCell(i, j).setView(charVector[i][j]);
            switch (charVector[i][j])
            {
            case '-':
            case '|':
            case '+':
                field->getCell(i, j).setPassability(false);
                break;
            default:
                field->getCell(i, j).setPassability(true);
                break;
            }
        }
    }
}

void GenField::generateFieldLv2()
{
    for (int i = 0; i < charVector.size(); i++)
    {
        for (int j = 0; charVector[i][j]; j++)
        {
            field->getCell(i, j).setView(charVector[i][j]);
            switch (charVector[i][j])
            {
            case '-':
            case '|':
            case '+':
                field->getCell(i, j).setPassability(false);
                break;
            default:
                field->getCell(i, j).setPassability(true);
                break;
            }
        }
    }
}

void GenField::placeEventLv1(Controller &controller)
{
    field->getCell(1, 1).setEvent(new KillEvent(controller));
    field->getCell(13, 11).setEvent(new BuffEvent(controller));
    field->getCell(4, 1).setEvent(new TeleportEvent(controller));
    field->getCell(5, 5).setEvent(new DebuffEvent(controller));
    field->getCell(9, 7).setEvent(new BuffEvent(controller));
    //удалится
    field->getCell(1, 1).setView('k');
    field->getCell(13, 11).setView('b');
    field->getCell(4, 1).setView('t');
    field->getCell(5, 5).setView('d');
    field->getCell(9, 7).setView('b');
}

void GenField::placeEventLv2(Controller &controller)
{
    field->getCell(10, 1).setEvent(new DebuffEvent(controller));
    field->getCell(14, 1).setEvent(new KillEvent(controller));
    field->getCell(12, 3).setEvent(new DebuffEvent(controller));
    field->getCell(7, 5).setEvent(new BuffEvent(controller));
    field->getCell(9, 9).setEvent(new TeleportEvent(controller));
    field->getCell(2, 11).setEvent(new DebuffEvent(controller));
    field->getCell(16, 11).setEvent(new DebuffEvent(controller));
    field->getCell(12, 3).setEvent(new DebuffEvent(controller));
    field->getCell(18, 15).setEvent(new TeleportEvent(controller));
    field->getCell(16, 15).setEvent(new BuffEvent(controller));
    field->getCell(11, 17).setEvent(new BuffEvent(controller));
    //удалится
    field->getCell(10, 1).setView('d');
    field->getCell(14, 1).setView('k');
    field->getCell(12, 3).setView('d');
    field->getCell(7, 5).setView('b');
    field->getCell(9, 9).setView('t');
    field->getCell(2, 11).setView('d');
    field->getCell(16, 11).setView('d');
    field->getCell(12, 3).setView('d');
    field->getCell(18, 15).setView('t');
    field->getCell(16, 15).setView('b');
    field->getCell(11, 17).setView('b');
}

#endif