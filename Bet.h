#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Player_creator.h"

struct Bet
{
    std::vector<unsigned int> numbers_choosen_by_players;

    Bet() = default;
    ~Bet() = default;

    void accept_bets_from_players(std::vector<std::unique_ptr<Player>>&);
    void settle_bets(int, std::vector<std::unique_ptr<Player>>&);
};