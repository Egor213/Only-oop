#ifndef interaction_tolk_h
#define interaction_tolk_h

class InteractionTolk
{
public:
    template <typename EnemyType>
    void interaction(EnemyType *enemy)
    {
        
        Controller* coords_player = enemy->getPlayerController();
        int temp = 0;
        int player_x = coords_player->getPosition().x;
        int player_y = coords_player->getPosition().y;

        int dx = player_x - enemy->getCoords().x;;
        int dy = player_y - enemy->getCoords().y;
        if (dx < 0)
        {
            if(coords_player->setPosition(player_x-1, player_y))
                temp++;
            else if (coords_player->setPosition(player_x, player_y+1))
                temp++;
            else if (coords_player->setPosition(player_x, player_y-1))
                temp++;
            else if (coords_player->setPosition(player_x+1, player_y))
                temp++;
        }
        else if (dx > 0)
        {
            if(coords_player->setPosition(player_x+1, player_y))
                temp++;
            else if (coords_player->setPosition(player_x, player_y+1))
                temp++;
            else if (coords_player->setPosition(player_x, player_y-1))
                temp++;
            else if (coords_player->setPosition(player_x-1, player_y))
                temp++;
        }
        else if (dy > 0)
        {
            if(coords_player->setPosition(player_x, player_y+1))
                temp++;
            else if (coords_player->setPosition(player_x+1, player_y))
                temp++;
            else if (coords_player->setPosition(player_x-1, player_y))
                temp++;
            else if (coords_player->setPosition(player_x, player_y-1))
                temp++;
        }
        else
        {
            if(coords_player->setPosition(player_x, player_y-1))
                temp++;
            else if (coords_player->setPosition(player_x+1, player_y))
                temp++;
            else if (coords_player->setPosition(player_x, player_y+1))
                temp++;
            else if (coords_player->setPosition(player_x-1, player_y))
                temp++;
        }
    }
};

#endif