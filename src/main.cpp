#include "../include/player.hpp"
#include "../include/deck.hpp"

Deck deck = Deck();
Player player = Player("Player");
Player house = Player("The House");
Player NPC1 = Player("Krin");
Player NPC2 = Player("La Mekarda");
Player NPC3 = Player("Jotita Suaj");

// Automatic selection in NPC turns
int NPCTurn(Player NPC) {
    enum Action {Drawcard, PassTurn};

    if (NPC.GetPoints() <= 10) {
        return Drawcard;

    } else if (NPC.GetPoints() > 10) {
        srand (time(NULL));
        int randomNumber = 1 + (rand() % 6);

        if ((NPC.GetPoints() >= 18) && (randomNumber == 6)) {
            return Drawcard;

        } else if ((NPC.GetPoints() < 17) && (NPC.GetPoints() >= 15) && (randomNumber >= 4)) {
            return Drawcard;

        } else if ((NPC.GetPoints() < 15) && (randomNumber >= 2)){
            return Drawcard;

        } else {
            return PassTurn;
        }
    }
}
// Count player points
int CountPoints(Player jugador) {
    int points = 0;
    int ases = 0;
    int conv = 0;
    std::multimap<std::string, std::string> hand = jugador.GetHand();
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
    std::cout << foo.GetName() << " shows his hand: \n" << std::endl;
    foo.ShowHand();
    std::cout << foo.GetName() << "'s points: " << foo.GetPoints() << std::endl;
    std::cout << std::endl;
    system("PAUSE");
    // The House Hand
    system("cls");
    std::cout << casino.GetName() << " shows his hand: \n" << std::endl;
    casino.ShowHand();
    std::cout << casino.GetName() << "'s points: " << casino.GetPoints() << std::endl;
    std::cout << std::endl;
    system("PAUSE");
    //Resolution
    system("cls");
    std::cout << foo.GetName() << " have " << foo.GetPoints() << " points.\n" << std::endl;
    std::cout << casino.GetName() << " have " << casino.GetPoints() << " points.\n" << std::endl;
    if ((foo.GetPoints() == 21) && (casino.GetPoints() != 21)) {
        std::cout << "BlackJack!" << std::endl;
    } else if ((foo.GetPoints() > casino.GetPoints()) && (foo.GetPoints() < 21)) {
        std::cout << "You won!" << std::endl;
    } else if ((foo.GetPoints() < 21) && (casino.GetPoints() > 21)) {
        std::cout << "That was close..." << std::endl;
    } else {
        std::cout << "The House always win.\n" << std::endl;
    }
    std::cout << std::endl;
    system("PAUSE");
}
// Game
int main() {
    // Start
    system("cls");
    std::cout << "How should I call you? ";
    std::string playerName;
    std::cin >> playerName;
    player.SetName(playerName);
    system("cls");
    std::cout << "Ok " << player.GetName() << ", Let's start..." << std::endl;
    std::cout << std::endl;
    system("PAUSE");
    system("cls");

    // Set Rounds
    std::cout << "Enter the number of rounds: ";
    int rounds;
    std::cin >> rounds;
    int roundNumber = 1;

    // Game loop
    while (rounds != 0) {
        system("cls");
        std::cout << "Round " << roundNumber << std::endl;
        std::cout << "=========" << std::endl;

        // Player Turn
        while (true) {
            std::cout << "Your turn, what do you want to do?\n" << "1. Draw card.\n" << "2. Pass your turn.\n" << std::endl;
            int election;
            std::cin >> election;
            system("cls");

            if (election == 1) {
                player.SetHand(deck.GetRandCard());
                std::cout << player.GetName() <<" draws a card" << std::endl;
                player.ShowHand();
                std::cout << std::endl;
                system("PAUSE");
                system("cls");
                break;

            } else if (election == 2) {
                std::cout << player.GetName() << " pass his turn\n" << std::endl;
                system("PAUSE");
                system("cls");
                break;

            } else {
                std::cout << "Enter a valid option\n" << std::endl;
                system("PAUSE");
                continue;
            }
        }
        // NPC Turns
        // House
        house.SetPoints(CountPoints(house)); 
        if (NPCTurn(house) == 1) {
            house.SetHand(deck.GetRandCard());
            std::cout << house.GetName() <<" draws a card\n" << std::endl;
            system("PAUSE");

        } else {
            std::cout << house.GetName() << " pass his turn\n" << std::endl;
            system("PAUSE");
        }
        // NPC1
        system("cls");
        NPC1.SetPoints(CountPoints(NPC1)); 
        if (NPCTurn(NPC1) == 1) {
            NPC1.SetHand(deck.GetRandCard());
            std::cout << NPC1.GetName() <<" draws a card\n" << std::endl;
            system("PAUSE");

        } else {
            std::cout << NPC1.GetName() << " pass his turn\n" << std::endl;
            system("PAUSE");
        }
        // NPC2
        system("cls");
        NPC2.SetPoints(CountPoints(NPC2)); 
        if (NPCTurn(NPC2) == 1) {
            NPC2.SetHand(deck.GetRandCard());
            std::cout << NPC2.GetName() <<" draws a card\n" << std::endl;
            system("PAUSE");

        } else {
            std::cout << NPC2.GetName() << " pass his turn\n" << std::endl;
            system("PAUSE");
        }
        // NPC3
        system("cls");
        NPC3.SetPoints(CountPoints(NPC3)); 
        if (NPCTurn(NPC3) == 1) {
            NPC3.SetHand(deck.GetRandCard());
            std::cout << NPC3.GetName() <<" draws a card\n" << std::endl;
            system("PAUSE");

        } else {
            std::cout << NPC3.GetName() << " pass his turn\n" << std::endl;
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