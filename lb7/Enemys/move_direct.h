#ifndef move_direct_h
#define move_direct_h

class MoveDirect
{
public:
    template <typename EnemyType>
    void move(EnemyType *enemy)
    {
        Controller* coords_player = enemy->getPlayerController();
        int temp = 0;
        int enemy_coords_x = enemy->getCoords().x;
        int enemy_coords_y = enemy->getCoords().y;
        int dx = coords_player->getPosition().x - enemy_coords_x;
        int dy = coords_player->getPosition().y - enemy_coords_y;
        if (std::abs(dx) > std::abs(dy))
        {
            enemy_coords_x += (dx > 0) ? 1 : -1;
        }
        else
        {
            enemy_coords_y += (dy > 0) ? 1 : -1; 
        }
        if (enemy->setCoords(enemy_coords_x, enemy_coords_y))
            temp++;
        else if (enemy->setCoords(enemy->getCoords().x+1, enemy->getCoords().y))
            temp++;
        else if (enemy->setCoords(enemy->getCoords().x-1, enemy->getCoords().y))
            temp++;
        else if (enemy->setCoords(enemy->getCoords().x, enemy->getCoords().y+1))
            temp++;
        else if (enemy->setCoords(enemy->getCoords().x, enemy->getCoords().y-1))
            temp++;
    }
};

#endif