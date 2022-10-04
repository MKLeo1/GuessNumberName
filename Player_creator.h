#pragma once
#include <vector>
#include <memory>
#include "Player.h"

class Player_creator : public Player
{
public:
    std::vector<std::unique_ptr<Player>> vector_of_players;
    Player_creator() = default;
    ~Player_creator() = default;
    void create_players(unsigned int);
};