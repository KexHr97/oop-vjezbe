#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card {
public:
    int number;
    string suit;

    Card(int num, string col) : number(num), suit(col) {};
};

class Deck {
public:
    vector<Card> cards;

    Deck() {
        for (int i = 1; i <= 10; i++) {
            cards.push_back(Card(i, "Spadi"));
            cards.push_back(Card(i, "Bastoni"));
            cards.push_back(Card(i, "Dinari"));
            cards.push_back(Card(i, "Kupe"));
        }
    }

    void shuffleDeck() {
        srand(static_cast<unsigned>(std::time(nullptr)));
        random_shuffle(cards.begin(), cards.end());
    }

    vector<vector<Card>> Deal(int num_players) {
        vector<vector<Card>> player_hands(num_players, vector<Card>());

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < num_players; j++) {
                player_hands[j].push_back(cards.back());
                cards.pop_back();
            }
        }
        return player_hands;
    }
};

class Player {
public:
    string name;
    int score;
    vector<Card> hand;

    Player(string player_name) : name(player_name), score(0) {};

    int checkAkuza(vector<Card>& hand) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int spadi = 0;
        int kupe = 0;
        int bastoni = 0;
        int dinari = 0;

        for (Card& card : hand) {
            if (card.number == 1)
                num1++;
            if (card.number == 2)
                num2++;
            if (card.number == 3)
                num3++;
            if ((card.number == 1 || card.number == 2 || card.number == 3) && card.suit == "Spadi")
                spadi++;
            if ((card.number == 1 || card.number == 2 || card.number == 3) && card.suit == "Bastoni")
                bastoni++;
            if ((card.number == 1 || card.number == 2 || card.number == 3) && card.suit == "Kupe")
                kupe++;
            if ((card.number == 1 || card.number == 2 || card.number == 3) && card.suit == "Dinari")
                dinari++;
        }

        int points = 0;
        if (num1 >= 3 || num2 >= 3)
            points += 3;
        if (num3 >= 3)
            points += 4;
        if (spadi >= 3 || kupe >= 3 || bastoni >= 3 || dinari >= 3)
            points += 3;
        return points;
    }

    void displayHand(vector<Card>& hand) {
        for (Card& card : hand) {
            std::cout << card.number << " " << card.suit << " ";
        }
    }
};

int main() {
    int num_players = 0;
    std::cout << "Enter number of players (2 or 4): ";
    while (num_players != 2 && num_players != 4) {
        std::cin >> num_players;
    }

    vector<Player> players;
    for (int i = 0; i < num_players; i++) {
        string name;
        std::cout << "Enter name of player " << i + 1 << ": ";
        std::cin >> name;
        players.push_back(Player(name));
    }

    Deck deck;
    deck.shuffleDeck();

    vector<vector<Card>> hands = deck.Deal(num_players);

    for (int i = 0; i < players.size(); i++) {
        players[i].hand = hands[i];
    }

    for (Player& player : players) {
        std::cout << "\nPlayer " << player.name << " has " << player.checkAkuza(player.hand) << " points for akuza" << endl;
        std::cout << "\nPlayer " << player.name << " has cards: " << endl;
        player.displayHand(player.hand);
    }
    return 0;
}