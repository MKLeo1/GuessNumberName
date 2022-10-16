#pragma once
#include <string>
#include <iostream>

class Player
{
    std::string name;
    int player_coins = {100};
    unsigned int amount_bet_by_player = {0};
    unsigned int number_bet_by_player = {0};

public:
    Player();
    Player(std::string, int, unsigned int, unsigned int);
    ~Player();

    unsigned int make_a_bet();
    unsigned int lost_bet();
    unsigned int won_bet();
    int get_player_coins();
    std::string get_player_name();
};
