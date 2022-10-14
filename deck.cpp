#include <string>
#include "deck.hpp"

//Constructor
Deck::Deck(void){
    
}
// Deck Getter
std::multimap<std::string, std::string> Deck::GetDeck() const {
    return this->deck;
}
// Deck Setter
void Deck::SetDeck(std::string type, std::string value) {
    this->deck.insert(std::pair<std::string, std::string>(type, value));
}
// Deck Card Eraser
void Deck::EraseCard(std::string type, std::string card) {
    for (auto iter = this->deck.begin(); iter != this->deck.end(); ++iter )
      if ((iter->first == type) && (iter->second == card)) {
        deck.erase(iter);
      }
}
// Shows Deck Map
void Deck::ShowCards() const {
    std::cout << "Deck:\nType\tCard\n";
   for (auto iter = this->deck.begin(); iter != this->deck.end(); ++iter )
      std::cout << iter->first << '\t' << iter->second << '\n';
      std::cout << std::endl;
}