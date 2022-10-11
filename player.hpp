#include <string>

class Player {

    private:
        std::string name;   // Player name
        int points = 0;     // Player points
    
    public:
        Player(const std::string name);  // Constructor

        // Getters and setters
        int GetPoints(void) const;
        void SetPoints(const int points);
        std::string GetName(void) const;
        void SetName(const std::string name);
        
};