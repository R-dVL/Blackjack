#include <iostream>
#include <string>
#include <map>

#include "player.hpp"
#include "deck.hpp"

using namespace std;

int CountPoints(multimap<string, string> hand) {
    int points = 0;
    int ases = 0;
    int conv = 0;
    for (auto iter = hand.begin(); iter != hand.end(); ++iter) {
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
            conv = stoi(iter->second);
            points += conv;
            cout << "Num" << endl;
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

    // Inicio
    system("cls");
    cout << "Como deberia llamarte: ";
    string playerName;
    cin >> playerName;
    Player player = Player(playerName);
    cout << "De acuerdo " << player.GetName() << ", comencemos..." << endl;
    system("PAUSE");
    system("cls");

    // Rondas
    cout << "Introduce el numero de rondas: ";
    int rounds;
    cin >> rounds;
    int roundNumber = 1;

    // Partida
    while (rounds != 0) {
        system("cls");
        cout << "Ronda " << roundNumber << endl;
        cout << "=========" << endl;
        ++roundNumber;
        --rounds;
        system("PAUSE");
    }
    // Resolución de la partida
    cout << player.GetName() << " enseña su mano: " << endl;
    player.SetPoints(CountPoints(player.GetHand()));
    cout << "Puntos: " << player.GetPoints();
}