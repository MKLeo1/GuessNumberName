#include "Player_creator.h"

void Player_creator::create_players(unsigned int number_of_players)
{
    for (int i = 0; i < number_of_players; i++)
    {
        vector_of_players.emplace_back(std::make_unique<Player>());
    }
}
