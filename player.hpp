#include <string>

class Player {

    protected:
        std::string name;
        int points;
    
    public:
        Player(const int points, const std::string & name);

        int GetPoints(void) const;
        void SetPoints(const int points);
        std::string & GetName(void) const;
        void SetName(const std::string & name);
        
};