#include "player.hpp"
#include "deck.hpp"

using namespace std;

Deck deck = Deck();
Player player = Player("Player");
Player house = Player("House");

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

int main() {
    // Start
    system("cls");
    cout << "Como deberia llamarte: ";
    string playerName;
    cin >> playerName;
    player.SetName(playerName);
    cout << "De acuerdo " << player.GetName() << ", comencemos..." << endl;
    cout << endl;
    system("PAUSE");
    system("cls");

    // Rounds
    cout << "Introduce el numero de rondas: ";
    int rounds;
    cin >> rounds;
    int roundNumber = 1;

    // Game
    while (rounds != 0) {
        system("cls");
        cout << "Ronda " << roundNumber << endl;
        cout << "=========" << endl;

        //Player Turn
        while (true) {
            cout << "Tu turno, Que eliges hacer?\n" << "1. Robar carta.\n" << "2. Pasar turno.\n" << endl;
            int election;
            cin >> election;
            system("cls");

            if (election == 1) {
                player.SetHand(deck.GetRandCard());
                cout << player.GetName() <<" roba una carta" << endl;
                player.ShowHand();
                cout << endl;
                system("PAUSE");
                system("cls");
                break;

            } else if (election == 2) {
                cout << "Pasas el turno\n" << endl;
                system("PAUSE");
                system("cls");
                break;

            } else {
                cout << "Introduce un valor valido\n" << endl;
                system("PAUSE");
                continue;
            }
        }
        //NPC Turn
        house.SetPoints(CountPoints(house)); 

        if (NPCTurn(house) == 1) {
            house.SetHand(deck.GetRandCard());
            cout << house.GetName() <<" roba una carta\n" << endl;
            system("PAUSE");

        } else {
            cout << house.GetName() << " pasa el turno\n" << endl;
            system("PAUSE");
        }
        
        ++roundNumber;
        --rounds;
    }
    // Game Resolution
    system("cls");
    cout << player.GetName() << " shows his hand: \n" << endl;
    player.ShowHand();
    cout << endl;
    player.SetPoints(CountPoints(player)); 
    cout << player.GetName() << "'s points: " << player.GetPoints() << endl;
    cout << endl;
    system("PAUSE");

    system("cls");
    cout << house.GetName() << " shows his hand: \n" << endl;
    house.ShowHand();
    cout << endl;
    house.SetPoints(CountPoints(house)); 
    cout << house.GetName() << "'s points: " << house.GetPoints() << endl;
    cout << endl;
    system("PAUSE");
}