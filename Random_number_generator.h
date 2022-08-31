#pragma once

class Random_number_generator
{
public:
    int won_number = {0};

    Random_number_generator();
    Random_number_generator(int);
    ~Random_number_generator();

    int draw_won_number(unsigned int &);
};