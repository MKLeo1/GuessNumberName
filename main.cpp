#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include "Casino.h"
#include "Player_creator.h"
#include "Player.h"
#include "Bet.h"
#include "Random_number_generator.h"

int main()
{
    Casino Casino_object;
    Player_creator Player_creator_object;
    Player_creator_object.create_players(Casino_object.get_number_of_players());
    while (true)
    {
        {
            Bet Bet_object;
            Bet_object.accept_bets_from_players(Player_creator_object.vector_of_players);

            std::unique_ptr<Random_number_generator> Rand_num_gen(new Random_number_generator(Casino_object.get_numbers_range()));
            Rand_num_gen->draw_won_number(Casino_object.get_numbers_range());

            Bet_object.settle_bets(Rand_num_gen->won_number, Player_creator_object.vector_of_players);
        }
    }
    return 0;
}