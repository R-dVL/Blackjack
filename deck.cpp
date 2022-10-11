#include <string>
#include "deck.hpp"

//Constructor
Deck::Deck(void){
    this->deck[0][0] = "A";  // Clubs A
    this->deck[0][1] = "1";  // Clubs 1
    this->deck[0][2] = "2";  // Clubs 2
    this->deck[0][3] = "3";  // Clubs 3
    this->deck[0][4] = "4";  // Clubs 4
    this->deck[0][5] = "5";  // Clubs 5
    this->deck[0][6] = "6";  // Clubs 6
    this->deck[0][7] = "7";  // Clubs 7
    this->deck[0][8] = "8";  // Clubs 8
    this->deck[0][9] = "9";  // Clubs 9
    this->deck[0][10] = "10";  // Clubs 10
    this->deck[0][11] = "J";  // Clubs J
    this->deck[0][12] = "Q";  // Clubs Q
    this->deck[0][13] = "K";  // Clubs K
    this->deck[1][0] = "A";  // Spades A
    this->deck[1][1] = "1";  // Spades 1
    this->deck[1][2] = "2";  // Spades 2
    this->deck[1][3] = "3";  // Spades 3
    this->deck[1][4] = "4";  // Spades 4
    this->deck[1][5] = "5";  // Spades 5
    this->deck[1][6] = "6";  // Spades 6
    this->deck[1][7] = "7";  // Spades 7
    this->deck[1][8] = "8";  // Spades 8
    this->deck[1][9] = "9";  // Spades 9
    this->deck[1][10] = "10";  // Spades 10
    this->deck[1][11] = "J";  // Spades J
    this->deck[1][12] = "Q";  // Spades Q
    this->deck[1][13] = "K";  // Spades K
    this->deck[2][0] = "A";  // Diamonds A 
    this->deck[2][1] = "1";  // Diamonds 1
    this->deck[2][2] = "2";  // Diamonds 2
    this->deck[2][3] = "3";  // Diamonds 3
    this->deck[2][4] = "4";  // Diamonds 4
    this->deck[2][5] = "5";  // Diamonds 5
    this->deck[2][6] = "6";  // Diamonds 6
    this->deck[2][7] = "7";  // Diamonds 7
    this->deck[2][8] = "8";  // Diamonds 8
    this->deck[2][9] = "9";  // Diamonds 9
    this->deck[2][10] = "10";  // Diamonds 10
    this->deck[2][11] = "J";  // Diamonds J
    this->deck[2][12] = "Q";  // Diamonds Q
    this->deck[2][13] = "K";  // Diamonds K
    this->deck[3][0] = "A";  // Hearts A
    this->deck[3][1] = "1";  // Hearts 1
    this->deck[3][2] = "2";  // Hearts 2
    this->deck[3][3] = "3";  // Hearts 3
    this->deck[3][4] = "4";  // Hearts 4
    this->deck[3][5] = "5";  // Hearts 5
    this->deck[3][6] = "6";  // Hearts 6
    this->deck[3][7] = "7";  // Hearts 7
    this->deck[3][8] = "8";  // Hearts 8
    this->deck[3][9] = "9";  // Hearts 9
    this->deck[3][10] = "10";  // Hearts 10
    this->deck[3][11] = "J";  // Hearts J
    this->deck[3][12] = "Q";  // Hearts Q
    this->deck[3][13] = "K";  // Hearts K
}
// Clubs setter and getter
std::string Deck::GetCard(int type, int card) {
    return this->deck[type][card];
}
void Deck::SetCard(int type, int card, std::string value) {
    this->deck[type][card] = value;
}