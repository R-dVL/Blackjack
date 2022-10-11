#include <string>
#include "deck.hpp"

//Constructor
Deck::Deck(void){
    // Clubs
    this->clubs[0] = 'A';
    this->clubs[1] = '1';
    this->clubs[2] = '2';
    this->clubs[3] = '3';
    this->clubs[4] = '4';
    this->clubs[5] = '5';
    this->clubs[6] = '6';
    this->clubs[7] = '7';
    this->clubs[8] = '8';
    this->clubs[9] = '9';
    this->clubs[10] = '10';
    this->clubs[11] = 'J';
    this->clubs[12] = 'Q';
    this->clubs[13] = 'K';
    // Hearts
    this->hearts[0] = 'A';
    this->hearts[1] = '1';
    this->hearts[2] = '2';
    this->hearts[3] = '3';
    this->hearts[4] = '4';
    this->hearts[5] = '5';
    this->hearts[6] = '6';
    this->hearts[7] = '7';
    this->hearts[8] = '8';
    this->hearts[9] = '9';
    this->hearts[10] = '10';
    this->hearts[11] = 'J';
    this->hearts[12] = 'Q';
    this->hearts[13] = 'K';
    // Diamonds
    this->diamonds[0] = 'A';
    this->diamonds[1] = '1';
    this->diamonds[2] = '2';
    this->diamonds[3] = '3';
    this->diamonds[4] = '4';
    this->diamonds[5] = '5';
    this->diamonds[6] = '6';
    this->diamonds[7] = '7';
    this->diamonds[8] = '8';
    this->diamonds[9] = '9';
    this->diamonds[10] = '10';
    this->diamonds[11] = 'J';
    this->diamonds[12] = 'Q';
    this->diamonds[13] = 'K';
    // Spades
    this->spades[0] = 'A';
    this->spades[1] = '1';
    this->spades[2] = '2';
    this->spades[3] = '3';
    this->spades[4] = '4';
    this->spades[5] = '5';
    this->spades[6] = '6';
    this->spades[7] = '7';
    this->spades[8] = '8';
    this->spades[9] = '9';
    this->spades[10] = '10';
    this->spades[11] = 'J';
    this->spades[12] = 'Q';
    this->spades[13] = 'K';
}
// Clubs setter and getter
char Deck::GetClubs(int card) {
    return this-> clubs[card];
}
void Deck::SetClubs(int card, char value) {
    this->clubs[card] = value;
}
// Hearts setter and getter
char Deck::GetHearts(int card) {
    return this-> hearts[card];
}
void Deck::SetHearts(int card, char value) {
    this->hearts[card] = value;
}
// Diamonds setter and getter
char Deck::GetDiamonds(int card) {
    return this-> diamonds[card];
}
void Deck::SetDiamonds(int card, char value) {
    this->diamonds[card] = value;
}
// Spades setter and getter
char Deck::GetSpades(int card) {
    return this-> spades[card];
}
void Deck::SetSpades(int card, char value) {
    this->spades[card] = value;
}

char Deck::StealCard(std::string type, int card) {
    if (type == "clubs") {
        this->GetClubs(card);
        this->SetClubs(card, '0');
    }
    else if (type == "diamonds") {
        this->GetDiamonds(card);
        this->SetDiamonds(card, '0');
    }
    else if (type == "hearts") {
        this->GetHearts(card);
        this->SetHearts(card, '0');
    }
    else if (type == "spades") {
        this->GetSpades(card);
        this->SetSpades(card, '0');
    }
}