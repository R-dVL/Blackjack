#include "../include/player.hpp"

// Constructor
Player::Player(const string name) {
    this->name = name;
    this->points = 0;
    this->hand;
}
// Name Getter
string Player::GetName(void) const {
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
multimap<string, string> Player::GetHand() const {
    return this->hand;
}
// Hand Setter
void Player::SetHand(map<string, string> cards) {
    string type;
    string card;
    for (auto iter = cards.begin(); iter != cards.end(); ++iter) {
        type = iter->first;
        card = iter->second;
    }
    this->hand.insert(pair<string, string>(type, card));
}
// Hand Card Eraser
void Player::EraseCard(string type, string card) {
    for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter )
      if ((iter->first == type) && (iter->second == card)) {
        hand.erase(iter);
      }
}
// Shows Hand
void Player::ShowHand() const {
    cout << this->name << "'s hand:\nType\tCard\n";
    cout << "=====\t=====" << endl;;
   for (auto iter = this->hand.begin(); iter != this->hand.end(); ++iter )
      cout << iter->first << ", " << iter->second << '\n';
      cout << endl;
}