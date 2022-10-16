#pragma once
#include <vector>
#include <memory>
#include "Player.h"
// struct responsible for create and store players
struct Player_creator : public Player
{
    std::vector<std::unique_ptr<Player>> vector_of_players;
    Player_creator() = default;
    ~Player_creator() = default;
    
    void create_players(unsigned int);
};