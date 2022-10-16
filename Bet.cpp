#include "Bet.h"

void Bet::accept_bets_from_players(std::vector<std::unique_ptr<Player>> &vector_of_players)
{
    for (auto itr = vector_of_players.begin(), itr_end = vector_of_players.end(); itr != itr_end; ++itr)
    {
        numbers_choosen_by_players.push_back((*itr)->make_a_bet());
    }
}
void Bet::settle_bets(int won_number, std::vector<std::unique_ptr<Player>> &vector_of_players)
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
                std::cout << "Player " << vector_of_players[i]->get_player_name() << " lost all money!"
                          << "/n";
                vector_of_players.erase(vector_of_players.begin() + i);
                if (vector_of_players.empty())
                {
                    std::cout << "All players lost!"
                              << "/n";
                }
            }
        }
        numbers_choosen_by_players.clear(); // clearing vector before next round
    }
}