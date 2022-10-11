#include <string>
#include "player.hpp"

Player::Player(const std::string name, const int points) {
    this->name = name;
    this->points = points;
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