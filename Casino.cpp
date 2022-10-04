#include "Casino.h"
#include <iostream>

Casino::Casino()
{
    unsigned int number_of_players = {0};
    unsigned int numbers_range = {0};
}
Casino::Casino(unsigned int number_of_players, unsigned int numbers_range)
{
    this->number_of_players = number_of_players;
    this->numbers_range = numbers_range;
}

unsigned int Casino::set_number_of_players()
{
    unsigned int number_of_players;
    std::cout << "Set number of players: ";
    std::cin >> number_of_players;
    this->number_of_players = number_of_players;
    return number_of_players;
}
void Casino::set_numbers_range()
{
    unsigned int number_range = {0};
    std::cout << "Set range of random numbers. 1-";
    std::cin >> number_range;
    this->numbers_range = number_range;
}
