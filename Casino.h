#pragma once
#include <vector>
#include <memory>
#include "Player.h"

class Casino
{
public:
    unsigned int number_of_players = {0};
    unsigned int numbers_range = {0}; // e.g. if numbers_range = 10, won_number is beetwen 1-10;
    std::vector<Player*> vector_of_players;
    std::vector<unsigned int> numbers_choosen_by_players;
    
    Casino();
    Casino(unsigned int, unsigned int);
    ~Casino();
    unsigned int set_number_of_players();
    void set_random_number_range();
    void create_players();
    void accept_bets_from_players();
    void settle_bets(unsigned int);

    friend class Random_number_generator;
};