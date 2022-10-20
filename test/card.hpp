#include <iostream>

class Card {
    private:
        std::string suit;
        std::string number;
        int value;

    public:
        Card(const std::string suit, const std::string number);
        void SetValue(const std::string number);
        int GetValue(void);
        void SetSuit(std::string suit);
        char GetSuit(void);
        void SetNumber(std::string number);
        int GetNumber(void);
};
