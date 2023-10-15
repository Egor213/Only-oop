#ifndef generate_field_cpp
#define generate_field_cpp
#include "generate_field.h"

GenField::GenField(Field &field, Controller &controller, unsigned level) : field(field), controller(controller)
{
    if (field.getWidth() != 15 || field.getHeight() != 15)
    {
        field.setSize(15, 15);
    }
    if (level == 1)
    {
        generateFieldLv1();
        placeEventLv1();
    }
    else
    {
        generateFieldLv1(); // тут будет генерате фиелд 2
        placeEventLv1();
    }
}

void GenField::generateFieldLv1()
{
    std::vector<std::string> charVector = {
        "+|+|+|||+ +|||+",
        "- - -   -     -",
        "- - + + + +|+ -",
        "- -   -   -   -",
        "- +|+|+|||+ +|-",
        "-   -     + - -",
        "- + +||||   - -",
        "- -       + - -",
        "- +|||+ +|+|+ -",
        "- -   - -     -",
        "- - + +|+ +|||-",
        "- - - -   -   -",
        "- + - + +|+ + -",
        "-   -       - -",
        "+|||+|||||||+ +"};

    /*  "+-+-+---+ +---+",
        "| | |   |     |",
        "| | + + + +-+ |",
        "| |   |   |   |",
        "| +-+-+---+ +-|",
        "|   |     + | |",
        "| + +----   | |",
        "| |       + | |",
        "| +---+ +-+-+ |",
        "| |   | |     |",
        "| | + +-+ +---|",
        "| | | |   |   |",
        "| + | + +-+ + |",
        "|   |       | |",
        "+---+-------+ +"}; */

    for (int i = 0; i < charVector.size(); i++)
    {
        for (int j = 0; charVector[i][j]; j++)
        {
            field.getCell(i, j).setView(charVector[i][j]);
            switch (charVector[i][j])
            {
            case '-':
            case '|':
            case '+':
                field.getCell(i, j).setPassability(false);
                break;
            default:
                field.getCell(i, j).setPassability(true);
                break;
            }
        }
    }
}

void GenField::placeEventLv1()
{
    field.getCell(1, 1).setEvent(new KillEvent(controller));
}

#endif