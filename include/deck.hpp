#include <iostream>
#include <string>
#include <map>
#include <ctime>

class Deck {
    private:
        std::multimap<std::string, std::string> deck;   // Types and Cards

    public:
        Deck(void);  // Constructor
        std::multimap<std::string, std::string> GetDeck(void) const;  // Hand Getter
        void SetDeck(std::string type, std::string value);  // Hand Setter
        void EraseCard(std::string type, std::string value); // Card Eraser
        void ShowCards(void) const; // Shows Deck Cards
        std::map<std::string, std::string> GetRandCard(void);
};