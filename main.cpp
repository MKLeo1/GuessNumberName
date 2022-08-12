#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
    std::string name;
    int deposit_money;
    uint bet_amount;
    uint bet_number;

    void set_player_starting_values()
    {
        std::string m_name;
        int m_deposit_money;
        std::cin >> m_name;
        std::cout << "Deposit your coins on game account. How much?: ";
        std::cin >> m_deposit_money;

        this->name = m_name;
        this->deposit_money = m_deposit_money;
    }
    int make_a_bet()
    {
        std::cout << name << " how much money would you like to bet?(Your coins - " << deposit_money << "): ";
        std::cin >> bet_amount;
        std::cout << name << " - choose your lucky number: ";
        std::cin >> bet_number;
        std::cout << std::endl;
        return bet_number;
    }
    void withdraw()
    {
        deposit_money += bet_amount * 2;
    }
    void deposit()
    {
        deposit_money -= bet_amount;
    }
};

class CasinoAccount
{
public:
    long long casino_money;
    uint number_range;
    uint won_number;
    uint number_of_players;
    std::vector<uint> numbers_choosen_by_players;
    std::vector<uint> bet_numbers;

    void set_random_number_range()
    {
        uint m_number_range;
        std::cout << "Set range of random numbers. 1-";
        std::cin >> m_number_range;
        std::cout << std::endl;

        this->number_range = m_number_range;
    }
    void draw_win_number()
    {
        won_number = rand() % number_range + 1;
        std::cout << std::endl
                  << "Won number: " << won_number << std::endl;
    }
};

int main()
{
    std::vector<Player *> vector_of_players;
    CasinoAccount casino_data;

    std::cout << "Set number of players: ";
    std::cin >> casino_data.number_of_players;

    for (int i = 0; i < casino_data.number_of_players; i++)
    {
        Player *player = new Player;
        std::cout << "Player " << i + 1 << " - insert your name: ";
        player->set_player_starting_values();
        vector_of_players.push_back(player);
    }

    casino_data.set_random_number_range();
    while (true)
    {
        if (vector_of_players.empty())
        {
            std::cout << "All players lost!";
            return 0;
        }
        for (std::vector<Player *>::iterator itr = vector_of_players.begin(), itr_end = vector_of_players.end(); itr != itr_end; ++itr)
        {
            casino_data.numbers_choosen_by_players.push_back((*itr)->make_a_bet());
        }

        casino_data.draw_win_number();
        for (int i = 0; i < vector_of_players.size(); i++)
        {
            if (casino_data.numbers_choosen_by_players[i] == casino_data.won_number)
            {
                vector_of_players[i]->withdraw();
            }
            else
            {
                vector_of_players[i]->deposit();
                if (vector_of_players[i]->deposit_money <= 0)
                {
                    std::cout << "Player " << vector_of_players[i]->name << " lost all money!" << std::endl;
                    vector_of_players.erase(vector_of_players.begin() + i);
                }
            }
        }
        casino_data.numbers_choosen_by_players.clear();
    }
}