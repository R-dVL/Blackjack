#include <string>

class Player {

    private:
        std::string name;   // Player name
        int points = 0;     // Player points
        //std::string hand[3][13];   // Types and Cards
    
    public:
        Player(const std::string name);  // Constructor
        std::string GetName(void) const;  // Name Getter
        void SetName(const std::string name);  // Name Setter
        int GetPoints(void) const;  // Points getter
        void SetPoints(const int points);  // Points Setter
        //std::string GetHand(int type, int card) const;  // Hand Getter
        //void SetHand(int type, int card, std::string value);  // Hand Setter
};