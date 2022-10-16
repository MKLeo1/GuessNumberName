#pragma once

struct Random_number_generator
{
    int won_number = {0};

    Random_number_generator();
    Random_number_generator(int);
    ~Random_number_generator() = default;

    int draw_won_number(unsigned int const&);
};