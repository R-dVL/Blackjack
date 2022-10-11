#include <iostream>
#include <string>

class Deck {
    private:
        std::string deck[3][13];  // Types and Cards

    public:
        Deck(void);  // Constructor
        void SetCard(int type, int card, std::string value);  // Set Card
        std::string GetCard(int type, int card);  // Get Card
};