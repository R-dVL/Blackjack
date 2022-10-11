#include <iostream>
#include <string>

#include "player.hpp"
#include "deck.hpp"

int main() {
    Player player = Player("Rast", 0);
    Deck deck = Deck();
    std::cout << deck.GetClubs(10) << std::endl;
    deck.StealCard("clubs", 10);
    std::cout << deck.GetClubs(10) << std::endl;
    deck.SetClubs(10, "10");
    std::cout << deck.GetClubs(10) << std::endl;
}