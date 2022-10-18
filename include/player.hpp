#include <string>
#include <map>
#include <iostream>
using namespace std;

class Player {

    private:
        string name;   // Player name
        int points;     // Player points
        multimap<string, string> hand;   // Types and Cards
    
    public:
        Player(const string name);  // Constructor
        string GetName(void) const;  // Name Getter
        void SetName(const std::string name);  // Name Setter
        int GetPoints(void) const;  // Points getter
        void SetPoints(const int points);  // Points Setter
        multimap<string, string> GetHand() const;  // Hand Getter
        void SetHand(map<string, string> cards);  // Hand Setter
        void EraseCard(string type, string value); // Card Eraser
        void ShowHand() const; // Show Hand
};