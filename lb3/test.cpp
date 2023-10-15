#include <iostream>
#include <vector>
#include <string>
int main()
{
    std::vector<std::string> charVector = {
        "+-+-+---+ ----+",
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
        "+---+-------+ +"
        };
    for (int i = 0; i < charVector.size(); i++)
    {
        for (int j = 0; charVector[i][j]; j++)
        {
            std::cout << charVector[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}