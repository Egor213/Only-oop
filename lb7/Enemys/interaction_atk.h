#ifndef interaction_atk_h
#define interaction_atk_h
#include <iostream>

class InteractionATK
{
public:

    template <typename EnemyType>
    void interaction(EnemyType *enemy)
    {
        enemy->attack();
    }
};

#endif