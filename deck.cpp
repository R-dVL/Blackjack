#include "deck.hpp"

//Constructor
Deck::Deck(void){
    this->deck.insert(pair<string, string>("Clubs", "A"));
    this->deck.insert(pair<string, string>("Clubs", "2"));
    this->deck.insert(pair<string, string>("Clubs", "3"));
    this->deck.insert(pair<string, string>("Clubs", "4"));
    this->deck.insert(pair<string, string>("Clubs", "5"));
    this->deck.insert(pair<string, string>("Clubs", "6"));
    this->deck.insert(pair<string, string>("Clubs", "7"));
    this->deck.insert(pair<string, string>("Clubs", "8"));
    this->deck.insert(pair<string, string>("Clubs", "9"));
    this->deck.insert(pair<string, string>("Clubs", "10"));
    this->deck.insert(pair<string, string>("Clubs", "J"));
    this->deck.insert(pair<string, string>("Clubs", "Q"));
    this->deck.insert(pair<string, string>("Clubs", "K"));
}
// Deck Getter
multimap<string, string> Deck::GetDeck() const {
    return this->deck;
}
// Deck Setter
void Deck::SetDeck(string type, string value) {
    this->deck.insert(pair<string, string>(type, value));
}
// Deck Card Eraser
void Deck::EraseCard(string type, string card) {
    for (auto iter = this->deck.begin(); iter != this->deck.end(); ++iter )
      if ((iter->first == type) && (iter->second == card)) {
        deck.erase(iter);
      }
}
// Shows Deck Map
void Deck::ShowCards(void) const {
    cout << "Deck:\nType\tCard\n";
   for (auto iter = this->deck.begin(); iter != this->deck.end(); ++iter )
      cout << iter->first << '\t' << iter->second << '\n';
      cout << endl;
}
// Gets Random Card From Deck
/*map<string, string> Deck::GetRandCard(void) {
    srand (time(NULL));
    vector<string> types = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string randType = types[(1 + (rand() % 4))];
    auto it = this->deck.equal_range(randType);
    advance(it, rand() % this->deck.count(randType));
    string card = it->;
    map<string, string> result = {randType, card};
}*/