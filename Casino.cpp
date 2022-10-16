#include "Casino.h"
#include <iostream>

Casino::Casino() : number_of_players(4), numbers_range(10)
{
}
Casino::Casino(unsigned int number_of_players, unsigned int numbers_range)
{
    this->number_of_players = number_of_players;
    this->numbers_range = numbers_range;
} 
unsigned int Casino::get_number_of_players()
{
    unsigned int get_number_of_players = number_of_players;
    return get_number_of_players;
}; 
unsigned int Casino::get_numbers_range()
{
    unsigned int get_number_range = numbers_range;
    return get_number_range;
};
