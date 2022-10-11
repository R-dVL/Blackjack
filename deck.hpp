#include <iostream>
#include <string>

class Deck {
    private:
        char clubs[13];
        char diamonds[13];
        char hearts[13];
        char spades[13];

    public:
        Deck(void);  // Constructor
        char StealCard(std::string type, int card);  // Steal card from deck
        // Clubs setter and getter
        void SetClubs(int card, char value);
        char GetClubs(int card);
        // Hearts setter and getter
        void SetHearts(int card, char value);
        char GetHearts(int card);
        // Diamonds setter and getter
        void SetDiamonds(int card, char value);
        char GetDiamonds(int card);
        // Spades setter and getter
        void SetSpades(int card, char value);
        char GetSpades(int card);
};