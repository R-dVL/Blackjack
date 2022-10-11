#include <string>
#include "player.hpp"

Player::Player(const std::string name) {
    this->name = name;
    this->points = 0;
    this->hand[0][0] = "0";  // Clubs A
    this->hand[0][1] = "0";  // Clubs 1
    this->hand[0][2] = "0";  // Clubs 2
    this->hand[0][3] = "0";  // Clubs 3
    this->hand[0][4] = "0";  // Clubs 4
    this->hand[0][5] = "0";  // Clubs 5
    this->hand[0][6] = "0";  // Clubs 6
    this->hand[0][7] = "0";  // Clubs 7
    this->hand[0][8] = "0";  // Clubs 8
    this->hand[0][9] = "0";  // Clubs 9
    this->hand[0][10] = "0";  // Clubs 10
    this->hand[0][11] = "0";  // Clubs J
    this->hand[0][12] = "0";  // Clubs Q
    this->hand[0][13] = "0";  // Clubs K
    this->hand[1][0] = "0";  // Spades A
    this->hand[1][1] = "0";  // Spades 1
    this->hand[1][2] = "0";  // Spades 2
    this->hand[1][3] = "0";  // Spades 3
    this->hand[1][4] = "0";  // Spades 4
    this->hand[1][5] = "0";  // Spades 5
    this->hand[1][6] = "0";  // Spades 6
    this->hand[1][7] = "0";  // Spades 7
    this->hand[1][8] = "0";  // Spades 8
    this->hand[1][9] = "0";  // Spades 9
    this->hand[1][10] = "0";  // Spades 10
    this->hand[1][11] = "0";  // Spades J
    this->hand[1][12] = "0";  // Spades Q
    this->hand[1][13] = "0";  // Spades K
    this->hand[2][0] = "0";  // Diamonds A 
    this->hand[2][1] = "0";  // Diamonds 1
    this->hand[2][2] = "0";  // Diamonds 2
    this->hand[2][3] = "0";  // Diamonds 3
    this->hand[2][4] = "0";  // Diamonds 4
    this->hand[2][5] = "0";  // Diamonds 5
    this->hand[2][6] = "0";  // Diamonds 6
    this->hand[2][7] = "0";  // Diamonds 7
    this->hand[2][8] = "0";  // Diamonds 8
    this->hand[2][9] = "0";  // Diamonds 9
    this->hand[2][10] = "0";  // Diamonds 10
    this->hand[2][11] = "0";  // Diamonds J
    this->hand[2][12] = "0";  // Diamonds Q
    this->hand[2][13] = "0";  // Diamonds K
    this->hand[3][0] = "0";  // Hearts A
    this->hand[3][1] = "0";  // Hearts 1
    this->hand[3][2] = "0";  // Hearts 2
    this->hand[3][3] = "0";  // Hearts 3
    this->hand[3][4] = "0";  // Hearts 4
    this->hand[3][5] = "0";  // Hearts 5
    this->hand[3][6] = "0";  // Hearts 6
    this->hand[3][7] = "0";  // Hearts 7
    this->hand[3][8] = "0";  // Hearts 8
    this->hand[3][9] = "0";  // Hearts 9
    this->hand[3][10] = "0";  // Hearts 10
    this->hand[3][11] = "0";  // Hearts J
    this->hand[3][12] = "0";  // Hearts Q
    this->hand[3][13] = "0";  // Hearts K
}

std::string Player::GetName(void) const {
    return this->name;
}
void Player::SetName(std::string name) {
    this->name = name;
}
int Player::GetPoints(void) const {
    return this->points;
}
void Player::SetPoints(int points) {
    this->points = points;
}
std::string Player::GetHand(int type, int card) const {
    return this->hand[type][card];
}
void Player::SetHand(int type, int card, std::string value) {
    this->hand[type][card] = value;
}