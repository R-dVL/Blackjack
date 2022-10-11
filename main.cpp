#include <iostream>
#include <string>

#include "player.hpp"
#include "deck.hpp"

int main() {
    Deck BlackJackDeck = Deck();
    
    std::cout << BlackJackDeck.GetClubs(1);
}