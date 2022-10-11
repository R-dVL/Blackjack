#include <iostream>
#include <string>

class Deck {
    private:
        std::string deck[3][13];  //0 = Clubs, 1 = Spades, 2 = Diamonds, 3 = Hearts

    public:
        Deck(void);  // Constructor
        void SetCard(int type, int card, std::string value);  // Set Card
        std::string GetCard(int type, int card);  // Get Card
};