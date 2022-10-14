#include <string>
#include <iostream>
#include "player.hpp"

// Constructor
Player::Player(const std::string name) {
    this->name = name;
    this->points = 0;
    this->hand;
}
// Name Getter
std::string Player::GetName(void) const {
    return this->name;
}
// Name Setter
void Player::SetName(std::string name) {
    this->name = name;
}
// Points Getter
int Player::GetPoints(void) const {
    return this->points;
}
// Points Setter
void Player::SetPoints(int points) {
    this->points = points;
}
// Hand Getter
std::multimap<std::string, std::string> Player::GetHand() const {
    return this->hand;
}
// Hand Setter
void Player::SetHand(std::string type, std::string value) {
    this->hand.insert(std::pair<std::string, std::string>(type, value));
}
// Hand Card Eraser
void Player::EraseCard(std::string type, std::string card) {
    for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter )
      if ((iter->first == type) && (iter->second == card)) {
        hand.erase(iter);
      }
}
// Shows Hand
void Player::ShowHand() const {
    std::cout << this->name << " hand:\nType\tCard\n";
   for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter )
      std::cout << iter->first << '\t' << iter->second << '\n';
      std::cout << std::endl;
}