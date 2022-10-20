#include "../include/deck.hpp"

//Constructor
Deck::Deck(void) {
    this->deck = {
        {"Clubs", "A"},
        {"Clubs", "2"},
        {"Clubs", "3"},
        {"Clubs", "4"},
        {"Clubs", "5"},
        {"Clubs", "6"},
        {"Clubs", "7"},
        {"Clubs", "8"},
        {"Clubs", "9"},
        {"Clubs", "10"},
        {"Clubs", "J"},
        {"Clubs", "Q"},
        {"Clubs", "K"},
        {"Diamonds", "A"},
        {"Diamonds", "2"},
        {"Diamonds", "3"},
        {"Diamonds", "4"},
        {"Diamonds", "5"},
        {"Diamonds", "6"},
        {"Diamonds", "7"},
        {"Diamonds", "8"},
        {"Diamonds", "9"},
        {"Diamonds", "10"},
        {"Diamonds", "J"},
        {"Diamonds", "Q"},
        {"Diamonds", "K"},
        {"Hearts", "A"},
        {"Hearts", "2"},
        {"Hearts", "3"},
        {"Hearts", "4"},
        {"Hearts", "5"},
        {"Hearts", "6"},
        {"Hearts", "7"},
        {"Hearts", "8"},
        {"Hearts", "9"},
        {"Hearts", "10"},
        {"Hearts", "J"},
        {"Hearts", "Q"},
        {"Hearts", "K"},
        {"Spades", "A"},
        {"Spades", "2"},
        {"Spades", "3"},
        {"Spades", "4"},
        {"Spades", "5"},
        {"Spades", "6"},
        {"Spades", "7"},
        {"Spades", "8"},
        {"Spades", "9"},
        {"Spades", "10"},
        {"Spades", "J"},
        {"Spades", "Q"},
        {"Spades", "K"},
    };
}
// Deck Getter
std::multimap<std::string, std::string> Deck::GetDeck(void) const {
    return this->deck;
}
// Deck Setter
void Deck::SetDeck(std::string type, std::string value) {
    this->deck.insert(std::pair<std::string, std::string>(type, value));
}
// Deck Card Eraser
void Deck::EraseCard(std::string type, std::string card) {
  typedef std::multimap<std::string, std::string>::iterator iterator;
  std::pair<iterator, iterator> iterpair = this->deck.equal_range(type);
  iterator it = iterpair.first;
  for (; it != iterpair.second; ++it) {
    if (it->second == card) { 
        this->deck.erase(it);
        break;
    }
  }
}
// Shows Deck Map
void Deck::ShowCards(void) const {
    std::cout << "Deck:\nType\tCard\n";
   for (auto iter = this->deck.begin(); iter != this->deck.end(); ++iter )
      std::cout << iter->first << '\t' << iter->second << '\n';
      std::cout << std::endl;
}
// Gets Random Card From Deck
std::map<std::string, std::string> Deck::GetRandCard(void) {
    srand (time(NULL));
    std::string type;
    std::string card;
    std::map<std::string, std::string> result;
    for (int i = this->deck.size(); i != 0; --i) {
        std::multimap<std::string, std::string>::iterator iter = this->deck.begin();
        advance(iter, rand() % this->deck.size());
        type = iter->first;
        card = iter->second;
    }
    result.insert(std::pair<std::string, std::string>(type, card));
    // Erasing the card from deck
    this->EraseCard(type, card);
    return result;
}