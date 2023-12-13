#ifndef move_random_h
#define move_random_h
#include <iostream>
#include "enemy.h"

#include <ctime>
#include <cstdlib>
class MoveRandom
{
public:
    template <typename EnemyType>
    void move(EnemyType *enemy)
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        while (true)
        {
            int randomNumber = std::rand() % 4;
            std::vector<std::pair<int, int>> temp = {{1,0},{-1,0},{0,1}, {0,-1}};
            if (enemy->addCoords(temp[randomNumber]))
                break;
        } 
    }

};

#endif