#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include "Random_number_generator.h"
#include "Player.h"
#include "Casino.h"
#include "Bet.h"
#include "Player_creator.h"

int main()
{
    Casino Casino_object;
    Casino_object.set_numbers_range();
    Casino_object.set_number_of_players();
    Player_creator Player_creator_object;
    Player_creator_object.create_players(Casino_object.number_of_players);
    while (true)
    {
        {
            // std::unique_ptr<Bet> Bet_ptr(new Bet());
            // Bet_ptr->accept_bets_from_players(Player_creator_object.vector_of_players);
            Bet Bet_object;
            Bet_object.accept_bets_from_players(Player_creator_object.vector_of_players);
            std::unique_ptr<Random_number_generator> Rand_num_gen(new Random_number_generator(Casino_object.numbers_range));
            Rand_num_gen->draw_won_number(Casino_object.numbers_range);
            Bet_object.settle_bets(Rand_num_gen->won_number, Player_creator_object.vector_of_players);
        }
    }
    return 0;
}