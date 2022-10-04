#pragma once
#include <vector>
#include <memory>


class Casino
{
public:
    unsigned int number_of_players = {0};
    unsigned int numbers_range = {0}; // e.g. if numbers_range = 10, won_number is beetwen 1-10;
 //    std::vector<std::unique_ptr<Player>> vector_of_players;
    // std::vector<unsigned int> numbers_choosen_by_players;

    Casino();
    Casino(unsigned int, unsigned int);
    ~Casino() = default;
    unsigned int set_number_of_players();
    void set_numbers_range();
};