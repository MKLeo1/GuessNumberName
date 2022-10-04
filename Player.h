#pragma once
#include <string>

class Player
{
    std::string name;
    int player_coins = {0};
    unsigned int amount_bet_by_player = {0};
    unsigned int number_bet_by_player = {0};

public:
    Player();
    ~Player();

    unsigned int make_a_bet();
    void lost_bet();
    void won_bet();
    int get_player_coins();
    std::string get_player_name();
};
