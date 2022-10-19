#include "../include/player.hpp"
#include "../include/deck.hpp"

using namespace std;

Deck deck = Deck();
Player player = Player("Player");
Player house = Player("The House");
Player NPC1 = Player("Krin");
Player NPC2 = Player("La Mekarda");
Player NPC3 = Player("Jotita Suaj");

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
// Game Resolution
void Resolution (Player foo, Player casino) {
    // Player/NPC Hand
    system("cls");
    cout << foo.GetName() << " shows his hand: \n" << endl;
    foo.ShowHand();
    cout << foo.GetName() << "'s points: " << foo.GetPoints() << endl;
    cout << endl;
    system("PAUSE");
    // The House Hand
    system("cls");
    cout << casino.GetName() << " shows his hand: \n" << endl;
    casino.ShowHand();
    cout << casino.GetName() << "'s points: " << casino.GetPoints() << endl;
    cout << endl;
    system("PAUSE");
    //Resolution
    system("cls");
    cout << foo.GetName() << " have " << foo.GetPoints() << " points.\n" << endl;
    cout << casino.GetName() << " have " << casino.GetPoints() << " points.\n" << endl;
    if ((foo.GetPoints() == 21) && (casino.GetPoints() != 21)) {
        cout << "BlackJack!" << endl;
    } else if ((foo.GetPoints() > casino.GetPoints()) && (foo.GetPoints() < 21)) {
        cout << "You won!" << endl;
    } else if ((foo.GetPoints() < 21) && (casino.GetPoints() > 21)) {
        cout << "That was close..." << endl;
    } else {
        cout << "The House always win.\n" << endl;
    }
    cout << endl;
    system("PAUSE");
}
// Game
int main() {
    // Start
    system("cls");
    cout << "How should I call you? ";
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
                cout << player.GetName() << " pass his turn\n" << endl;
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
        // House
        house.SetPoints(CountPoints(house)); 
        if (NPCTurn(house) == 1) {
            house.SetHand(deck.GetRandCard());
            cout << house.GetName() <<" draws a card\n" << endl;
            system("PAUSE");

        } else {
            cout << house.GetName() << " pass his turn\n" << endl;
            system("PAUSE");
        }
        // NPC1
        system("cls");
        NPC1.SetPoints(CountPoints(NPC1)); 
        if (NPCTurn(NPC1) == 1) {
            NPC1.SetHand(deck.GetRandCard());
            cout << NPC1.GetName() <<" draws a card\n" << endl;
            system("PAUSE");

        } else {
            cout << NPC1.GetName() << " pass his turn\n" << endl;
            system("PAUSE");
        }
        // NPC2
        system("cls");
        NPC2.SetPoints(CountPoints(NPC2)); 
        if (NPCTurn(NPC2) == 1) {
            NPC2.SetHand(deck.GetRandCard());
            cout << NPC2.GetName() <<" draws a card\n" << endl;
            system("PAUSE");

        } else {
            cout << NPC2.GetName() << " pass his turn\n" << endl;
            system("PAUSE");
        }
        // NPC3
        system("cls");
        NPC3.SetPoints(CountPoints(NPC3)); 
        if (NPCTurn(NPC3) == 1) {
            NPC3.SetHand(deck.GetRandCard());
            cout << NPC3.GetName() <<" draws a card\n" << endl;
            system("PAUSE");

        } else {
            cout << NPC3.GetName() << " pass his turn\n" << endl;
            system("PAUSE");
        }

        ++roundNumber;
        --rounds;
    }
    // Points count
    player.SetPoints(CountPoints(player)); 
    house.SetPoints(CountPoints(house)); 
    NPC1.SetPoints(CountPoints(NPC1)); 
    NPC2.SetPoints(CountPoints(NPC2)); 
    NPC3.SetPoints(CountPoints(NPC3)); 
    // Game Resolution
    system("cls");
    Resolution(player, house);
    Resolution(NPC1, house);
    Resolution(NPC2, house);
    Resolution(NPC3, house);
}