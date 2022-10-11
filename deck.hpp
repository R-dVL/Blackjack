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
        char StealCard(int card);  // Steal card from deck
        // Clubs setter and getter
        void SetClubs(std::string card[]);
        char GetClubs(int card);
        // Hearts setter and getter
        void SetHearts(std::string card[]);
        std::string GetHearts(int card);
        // Diamonds setter and getter
        void SetDiamonds(std::string card[]);
        std::string GetDiamonds(int card);
        // Spades setter and getter
        void SetSpades(std::string card[]);
        std::string GetSpades(int card);
};