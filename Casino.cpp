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
Casino::~Casino() {}

unsigned int Casino::set_number_of_players()
{
    unsigned int number_of_players;
    std::cout << "Set number of players: ";
    std::cin >> number_of_players;
    this->number_of_players = number_of_players;
    return number_of_players;
}
void Casino::set_random_number_range()
{
    unsigned int number_range = {0};
    std::cout << "Set range of random numbers. 1-";
    std::cin >> number_range;
    this->numbers_range = number_range;
}
void Casino::create_players()
{
    for (int i = 0; i < number_of_players; i++)
    {
        Player *player = new Player;
        vector_of_players.push_back(player);
    }
}
void Casino::accept_bets_from_players()
{
    for (auto itr = vector_of_players.begin(), itr_end = vector_of_players.end(); itr != itr_end; ++itr)
    {
        numbers_choosen_by_players.push_back((*itr)->make_a_bet());
    }
}
void Casino::settle_bets(unsigned int won_number)
{
    for (int i = 0; i < vector_of_players.size(); i++)
    {
        if (numbers_choosen_by_players[i] == won_number)
        {
            vector_of_players[i]->won_bet();
        }
        else
        {
            vector_of_players[i]->lost_bet();
            if (vector_of_players[i]->get_player_coins() <= 0)
            {
                std::cout << "Player " << vector_of_players[i]->get_player_name() << " lost all money!";
                // I'd prefer std::advance
                vector_of_players.erase(vector_of_players.begin() + i);
            }
        }
        numbers_choosen_by_players.clear(); //clearing vector before next round
    }
}