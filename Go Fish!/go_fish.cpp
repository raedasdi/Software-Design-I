/* ********** GO FISH ******** */

#include "player.h"
#include "deck.h"
#include "card.h"

#include <iostream>
#include <cstdlib>

using namespace std;

// dealHand Function
// Taken from card_demo.cpp provided in online class source code
void dealHand(Deck &d, Player &p, int numCards);



int main (){
    numCards = 7;

    Player p1("Tuna");
    Player p2("Cod");

    cout << p1.getName() << " and " << p2.getName() < " are ready to play Go Fish!" << endl;

    Deck d;
    d.shuffle();

    int dummy;

    for (int i = 0; i < 30; i++) {
        cout << "Shuffling the deck." << endl;
        while (dummy < 15) dummy++;
        dummy = 0;
        system("clear");
        cout << "Shuffling the deck.." << endl;
        while (dummy < 15) dummy++;
        dummy = 0;
        system("clear");
        cout << "Shuffling the deck..." << endl;
        while (dummy < 15) dummy++;
        dummy = 0;
        system("clear");
    }

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


    cout << p1.getName() << "'s Hand and Books" << endl;
    cout << p1.showHand() << endl;
    cout << p1.showBooks() << endl;

    cout << p2.getName() << "'s Hand and Books" << endl;
    cout << p2.showHand() << endl;
    cout << p2.showBooks() << endl;

    return EXIT_SUCCESS
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}