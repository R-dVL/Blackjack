#include <iostream>
#include <string>

class Deck {
    private:
        std::string clubs[13];
        std::string diamonds[13];
        std::string hearts[13];
        std::string spades[13];

    public:
        Deck(void);  // Constructor
        void StealCard(std::string type, int card);  // Steal card from deck
        // Clubs setter and getter
        void SetClubs(int card, std::string value);
        std::string GetClubs(int card);
        // Hearts setter and getter
        void SetHearts(int card, std::string value);
        std::string GetHearts(int card);
        // Diamonds setter and getter
        void SetDiamonds(int card, std::string value);
        std::string GetDiamonds(int card);
        // Spades setter and getter
        void SetSpades(int card, std::string value);
        std::string GetSpades(int card);
};