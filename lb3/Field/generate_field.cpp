#ifndef generate_field_cpp
#define generate_field_cpp
#include "generate_field.h"

GenField::GenField(Field &field, Controller &controller, unsigned level) : field(field), controller(controller)
{
    if (level == 0 && (field.getWidth() != 15 || field.getHeight() != 15))
    {
        field.setSize(15, 15);
    }
    if (level != 0 && (field.getWidth() != 20 || field.getHeight() != 19))
    {
        field.setSize(19, 20);
    }

    if (level == 0)
    {
        generateFieldLv1();
        placeEventLv1();
    }
    else
    {
        generateFieldLv2();
        placeEventLv2();
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

void GenField::generateFieldLv2()
{
    /*
        "++ +---+----+-----+",
        "|  |   |    |     |",
        "| ++ + + ++ | +-+ |",
        "|    |    | | |   |",
        "+----+--+ | + | +-+",
        "|       | |   |   |",
        "| +---+ +-+---+ + |",
        "| |   +       | | |",
        "| +-+   +---+ +-+ |",
        "|   +--++ +       |",
        "| +    |    +---+ |",
        "| +-++ +---++   | |",
        "|   |  |   |  + | |",
        "+-+ | ++ + | ++ +-+",
        "|   |    | |  |    ",
        "| +-+----+ ++ +-+ |",
        "| |         | |   |",
        "| | +-------+ +---+",
        "| |               |", 20 высота
        "+-+---------------+"
*/
    std::vector<std::string> charVector = {
        "++ +|||+||||+|||||+",
        "-  -   -    -     -",
        "- ++ + + ++ - +|+ -",
        "-    -    - - -   -",
        "+||||+||+ - + - +|+",
        "-       - -   -   -",
        "- +|||+ +|+|||+ + -",
        "- -   +       - - -",
        "- +|+   +|||+ +|+ -",
        "-   +||++ +       -",
        "- +    -    +|||+ -",
        "- +|++ +|||++   - -",
        "-   -  -   -  + - -",
        "+|+ - ++ + - ++ +|+",
        "-   -    - -  -    ",
        "- +|+||||+ ++ +|+ -",
        "- -         - -   -",
        "- - +|||||||+ +|||+",
        "- -               -",
        "+|+|||||||||||||||+"};

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
    field.getCell(13, 11).setEvent(new BuffEvent(controller));
    field.getCell(4, 1).setEvent(new TeleportEvent(controller));
    field.getCell(5, 5).setEvent(new DebuffEvent(controller));
    field.getCell(9, 7).setEvent(new BuffEvent(controller));
}


void GenField::placeEventLv2()
{
    field.getCell(10, 1).setEvent(new DebuffEvent(controller));
    field.getCell(14, 1).setEvent(new KillEvent(controller));
    field.getCell(12, 3).setEvent(new DebuffEvent(controller));
    field.getCell(7, 5).setEvent(new BuffEvent(controller));
    field.getCell(9, 9).setEvent(new TeleportEvent(controller));
    field.getCell(2, 11).setEvent(new DebuffEvent(controller));
    field.getCell(16, 11).setEvent(new DebuffEvent(controller));
    field.getCell(12, 3).setEvent(new DebuffEvent(controller));
    field.getCell(18, 15).setEvent(new TeleportEvent(controller));
    field.getCell(15, 15).setEvent(new BuffEvent(controller));
    field.getCell(11, 17).setEvent(new BuffEvent(controller));
}

#endif