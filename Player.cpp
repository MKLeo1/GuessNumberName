#include "Player.h"

Player::Player() : name("Player"), player_coins(100), amount_bet_by_player(0), number_bet_by_player(0){};

Player::Player(std::string name, int player_coins, unsigned int amount_bet_by_player, unsigned int number_bet_by_player)
{
    this->name = name;
    this->player_coins = player_coins;
    this->amount_bet_by_player = amount_bet_by_player;
    this->number_bet_by_player = number_bet_by_player;
}

Player::~Player() { std::cout << "Player " << name << " game over. "; }

unsigned int Player::make_a_bet()
{
    std::cout << Player::name << " - how much coins would you like to bet?(Your coins - " << player_coins << "): ";
    std::cin >> amount_bet_by_player;
    std::cout << Player::name << " - choose your lucky number:";
    std::cin >> number_bet_by_player;
    return number_bet_by_player;
}
unsigned int Player::lost_bet()
{
    player_coins -= amount_bet_by_player;
    return player_coins;
    
}
unsigned int Player::won_bet()
{
    player_coins += amount_bet_by_player;
    return player_coins;
}
int Player::get_player_coins()
{
    int get_coins = player_coins;
    return get_coins;
}
std::string Player::get_player_name()
{
    std::string get_name = name;
    return get_name;
}

