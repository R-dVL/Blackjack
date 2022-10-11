#include <iostream>
#include <string>

#include "player.hpp"
#include "deck.hpp"

int main() {
    std::cout << "Introduce tu nombre: " << std::endl;
    std::string name;
    std::cin >> name;
    Player player = Player(name);
    std::cout << player.GetName();
}