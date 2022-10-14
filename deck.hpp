#include <iostream>
#include <string>
#include <map>

class Deck {
    private:
        std::multimap<std::string, std::string> deck;   // Types and Cards

    public:
        Deck(void);  // Constructor
        std::multimap<std::string, std::string> GetDeck() const;  // Hand Getter
        void SetDeck(std::string type, std::string value);  // Hand Setter
        void EraseCard(std::string type, std::string value); // Card Eraser
        void ShowCards() const; // Shows Deck Cards
};