#include <iostream>
#include <string>

#include "player.hpp"
#include "deck.hpp"

int main() {
    Player player = Player("Rast", 0);
    Deck deck = Deck();
    std::cout << deck.GetClubs(0);
}