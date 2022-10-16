#pragma once
// class responsible for game rules
class Casino 
{
    unsigned int number_of_players = {4};
    unsigned int numbers_range = {10}; // e.g. if numbers_range = 10, won_number is beetwen 1-10;
public:
    Casino();
    Casino(unsigned int, unsigned int);
    ~Casino() = default;

    unsigned int get_number_of_players();
    unsigned int get_numbers_range();
};