#include "Player.h"
#include <ios>
#include <limits>
#include <string>
#include <iostream>

Player::Player()
{
    std::cout << "Insert your name: ";
    std::cin >> name;

    std::cout << "Deposit your coins on game account. How much?: ";
    std::cin >> player_coins;
    this->name = name;
    this->player_coins = player_coins;
}

Player::~Player() { std::cout << "Player " << name << " lost"; }

unsigned int Player::make_a_bet()
{
    std::cout << Player::name << " - how much coins would you like to bet?(Your coins - " << player_coins << "): ";
    std::cin >> amount_bet_by_player;
    std::cout << Player::name << " - choose your lucky number: ";
    std::cin >> number_bet_by_player;
    return number_bet_by_player;
}
void Player::lost_bet()
{
    player_coins -= amount_bet_by_player;
    std::cout << "Player " << Player::name << " lost! " << "/n";
}
void Player::won_bet()
{
    player_coins += amount_bet_by_player;
    std::cout << "Player " << Player::name << " won!" << "/n";
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
