#include "card.hpp"

Card::Card(const std::string suit, const std::string number) {
    this->suit = suit;
    this->number = number;
    if (number == "A") {
        this->value = 1 || 11;
    }
}