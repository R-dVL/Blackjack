#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Deck {
    private:
        multimap<string, string> deck;   // Types and Cards

    public:
        Deck(void);  // Constructor
        multimap<string, string> GetDeck() const;  // Hand Getter
        void SetDeck(string type, string value);  // Hand Setter
        void EraseCard(string type, string value); // Card Eraser
        void ShowCards(void) const; // Shows Deck Cards
        map<string, string> GetRandCard(void);
};