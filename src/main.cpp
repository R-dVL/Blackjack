#include "../include/player.hpp"
#include "../include/deck.hpp"

using namespace std;

Deck deck = Deck();
Player player = Player("Player");
Player house = Player("The House");

// Automatic selection in NPC turns
int NPCTurn(Player NPC) {
    if (NPC.GetPoints() <= 10) {
        return 1;

    } else if (NPC.GetPoints() > 10) {
        srand (time(NULL));
        int randomNumber = 1 + (rand() % 6);

        if ((NPC.GetPoints() >= 18) && (randomNumber == 6)) {
            return 1;

        } else if ((NPC.GetPoints() < 17) && (NPC.GetPoints() >= 15) && (randomNumber >= 4)) {
            return 1;

        } else if ((NPC.GetPoints() < 15) && (randomNumber >= 2)){
            return 1;

        } else {
            return 2;
        }
    }
}
// Count player points
int CountPoints(Player jugador) {
    int points = 0;
    int ases = 0;
    int conv = 0;
    multimap<string, string> hand = jugador.GetHand();
    for (auto iter = hand.begin(); iter != hand.end(); ++iter) {
        if (iter->second == "J") {
            points += 10;
        } else if (iter->second == "Q") {
            points += 10;
        } else if (iter->second == "K") {
            points += 10;
        } else if (iter->second == "A") {
            ases += 1;
        } else {
            conv = stoi(iter->second);
            points += conv;
        }
    }
    if ((points <= 10) && (ases == 1)) {
        points += 11;
    } else if ((points > 10) && (ases >= 1)){
        points += ases;
    }
    return points;
}
// Resolution
void Resolution (Player foo, Player casino) {
    cout << foo.GetName() << " have " << foo.GetPoints() << " points." << endl;
    cout << casino.GetName() << " have " << casino.GetPoints() << " points." << endl;
    if ((foo.GetPoints() == 21) && (casino.GetPoints() != 21)) {
        cout << "¡BlackJack!\n" << endl;
    } else if ((foo.GetPoints() > casino.GetPoints()) && (foo.GetPoints() < 21)) {
        cout << "You won!\n" << endl;
    } else if ((foo.GetPoints() < 21) && (casino.GetPoints() > 21)) {
        cout << "That was close...\n" << endl;
    } else {
        cout << "The House always win.\n" << endl;
    }
    system("PAUSE");
}
// Game
int main() {
    // Start
    system("cls");
    cout << "How should I call you?\n";
    string playerName;
    cin >> playerName;
    player.SetName(playerName);
    system("cls");
    cout << "Ok " << player.GetName() << ", Let's start..." << endl;
    cout << endl;
    system("PAUSE");
    system("cls");

    // Set Rounds
    cout << "Enter the number of rounds: ";
    int rounds;
    cin >> rounds;
    int roundNumber = 1;

    // Game loop
    while (rounds != 0) {
        system("cls");
        cout << "Round " << roundNumber << endl;
        cout << "=========" << endl;

        // Player Turn
        while (true) {
            cout << "Your turn, what do you want to do?\n" << "1. Draw card.\n" << "2. Pass your turn.\n" << endl;
            int election;
            cin >> election;
            system("cls");

            if (election == 1) {
                player.SetHand(deck.GetRandCard());
                cout << player.GetName() <<" draws a card" << endl;
                player.ShowHand();
                cout << endl;
                system("PAUSE");
                system("cls");
                break;

            } else if (election == 2) {
                cout << player.GetName() << "pass his turn\n" << endl;
                system("PAUSE");
                system("cls");
                break;

            } else {
                cout << "Enter a valid option\n" << endl;
                system("PAUSE");
                continue;
            }
        }
        // NPC Turns
        house.SetPoints(CountPoints(house)); 

        if (NPCTurn(house) == 1) {
            house.SetHand(deck.GetRandCard());
            cout << house.GetName() <<" draws a card\n" << endl;
            system("PAUSE");

        } else {
            cout << house.GetName() << " pass his turn\n" << endl;
            system("PAUSE");
        }
        
        ++roundNumber;
        --rounds;
    }
    // Points count
    // Player
    system("cls");
    cout << player.GetName() << " shows his hand: \n" << endl;
    player.ShowHand();
    cout << endl;
    player.SetPoints(CountPoints(player)); 
    cout << player.GetName() << "'s points: " << player.GetPoints() << endl;
    cout << endl;
    system("PAUSE");

    // The House
    system("cls");
    cout << house.GetName() << " shows his hand: \n" << endl;
    house.ShowHand();
    cout << endl;
    house.SetPoints(CountPoints(house)); 
    cout << house.GetName() << "'s points: " << house.GetPoints() << endl;
    cout << endl;
    system("PAUSE");

    // Game Resolution
    system("cls");
    Resolution(player, house);
}