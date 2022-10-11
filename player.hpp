#include <string>

class Player {

    private:
        std::string name;   // Player name
        int points = 0;     // Player points
    
    public:
        Player(const std::string name, const int points);  // Constructor

        int GetPoints(void) const;  // Points getter
        void SetPoints(const int points);  // Points Setter
        std::string GetName(void) const;  // Name Getter
        void SetName(const std::string name);  // Name Setter
        
};