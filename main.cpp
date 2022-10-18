#include "player.hpp"
#include "deck.hpp"

using namespace std;

Deck deck = Deck();
Player player = Player("Player");
Player house = Player("House");

map<string, string> StealCard(Player jugador) {
    map<string, string> randCard = deck.GetRandCard();
    for (auto iter = randCard.begin(); iter != randCard.end(); ++iter) {
        cout << iter->first << "\n" << iter->second;
    }
    cout << jugador.GetName() << "gets a card." << endl;
    return randCard;
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

        player.SetHand(StealCard(player));
        //StealCard(NPC1);
        //StealCard(NPC2);
        //StealCard(NPC3);
        house.SetHand(StealCard(house));

        ++roundNumber;
        --rounds;
        system("PAUSE");
    }
    // Game Resolution
    cout << player.GetName() << " shows his hand: " << endl;
    player.ShowHand();
    player.SetPoints(CountPoints(player)); 
    cout << player.GetPoints();
}