#include <string>
#include <map>

class Player {

    private:
        std::string name;   // Player name
        int points;     // Player points
        std::multimap<std::string, std::string> hand;   // Types and Cards
    
    public:
        Player(const std::string name);  // Constructor
        std::string GetName(void) const;  // Name Getter
        void SetName(const std::string name);  // Name Setter
        int GetPoints(void) const;  // Points getter
        void SetPoints(const int points);  // Points Setter
        std::multimap<std::string, std::string> GetHand() const;  // Hand Getter
        void SetHand(std::string type, std::string value);  // Hand Setter
        void EraseCard(std::string type, std::string value); // Card Eraser
        void ShowHand() const; // Show Hand
};