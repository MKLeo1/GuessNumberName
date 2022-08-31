#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include "Random_number_generator.h"
#include "Player.h"
#include "Casino.h"

int main()
{
    Casino Casino;
    Casino.set_random_number_range();
    Casino.set_number_of_players();
    Casino.create_players();
    while (true)
    {
        {
            Casino.accept_bets_from_players();
            std::unique_ptr<Random_number_generator> Rand_num_gen(new Random_number_generator(Casino.numbers_range));
            Rand_num_gen->draw_won_number(Casino.numbers_range);
            Casino.settle_bets(Rand_num_gen->won_number);
        }
    }
    return 0;
}