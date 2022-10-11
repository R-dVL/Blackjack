#include <string>
#include "deck.hpp"

Deck::Deck(void){
    this->clubs[0] = 'A';
}

char Deck::GetClubs(int card) {
    return this-> clubs[card];
}
