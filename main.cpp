#include "player.hpp"
#include "deck.hpp"
#include <string>

using namespace std;

Deck deck = Deck();

map<string, string> StealCard(void) {
    map<string, string> result;
    string type;
    string card;
    result = deck.GetRandCard();
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
        type = iter->first;
        card = iter->second;
    }
    return result;
}

void StealCard(Player player) {
    player.SetHand(deck.GetRandCard());
        cout << player.GetName() << "gets a card." << endl;
}

int CountPoints(Player player) {
    int points = 0;
    int ases = 0;
    int conv = 0;
    cout << player.GetName() << " shows his hand: " << endl;
    for (auto iter = player.GetHand().begin(); iter != player.GetHand().end(); ++iter) {
        if (iter->second == "J") {
            points += 10;
            cout << "J" << endl;
        } else if (iter->second == "Q") {
            points += 10;
            cout << "Q" << endl;
        } else if (iter->second == "K") {
            points += 10;
            cout << "K" << endl;
        } else if (iter->second == "A") {
            ases += 1;
            cout << "A" << endl;
        } else {
            cout << iter->second;
            //conv = stoi(iter->second);
            points += conv;
            cout << "Num" << endl;
        }
    }
    if ((points <= 10) && (ases == 1)) {
        points += 11;
    } else if ((points > 10) && (ases >= 1)){
        points += ases;
    }
    player.SetPoints(points);
    return player.GetPoints();
}

int main() {
    // Init
    Player NPC1 = Player("Cheka");
    Player NPC2 = Player("Fran");
    Player NPC3 = Player("Jota");
    Player House = Player("The House");

    // Start
    system("cls");
    cout << "Como deberia llamarte: ";
    string playerName;
    cin >> playerName;
    Player player = Player(playerName);
    cout << "De acuerdo " << player.GetName() << ", comencemos..." << endl;
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

        StealCard(player);
        //StealCard(NPC1);
        //StealCard(NPC2);
        //StealCard(NPC3);
        //StealCard(House);

        ++roundNumber;
        --rounds;
        system("PAUSE");
    }
    // Game Resolution
    cout << CountPoints(player); 
}