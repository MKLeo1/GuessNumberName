#include "Random_number_generator.h"
#include <random>
#include <iostream>

Random_number_generator::Random_number_generator()
{
    this->won_number = {0};
}
Random_number_generator::Random_number_generator(int won_number)
{
    this->won_number = won_number;
}
Random_number_generator::~Random_number_generator() {}

int Random_number_generator::draw_won_number(unsigned int &numbers_range)
{
    std::random_device random_device;
    std::mt19937 rand_number_generator(random_device()); // used random_device to seed the random number generator
    std::uniform_int_distribution<int> distribution(1, numbers_range);
    won_number = distribution(rand_number_generator);
    std::cout << "Won number: " << won_number;
    return won_number;
}