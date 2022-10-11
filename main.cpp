#include <iostream>
#include <string>

#include "player.hpp"
#include "deck.hpp"

int main() {
    Player Player1 = Player("Rast");
    Deck BlackJackDeck = Deck();
    
    std::cout << BlackJackDeck.GetClubs(1);
}