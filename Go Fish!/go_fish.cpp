/* ********** GO FISH ******** */

#include "player.h"
#include "deck.h"
#include "card.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// dealHand Function
// Taken from card_demo.cpp provided in online class source code
void dealHand(Deck &d, Player &p, int numCards);

void shuffleAnimation();

void delay (int n);


int main (){
    srand((unsigned)time(0));

    int player = 0;
    int numCards = 7;
    const int WINSIZE = 14;

    Player p1("Tuna");
    Player p2("Cod");

    cout << p1.getName() << " and " << p2.getName() << " are ready to play!" << endl;
    delay(5);

    Deck d;
    d.shuffle();
    shuffleAnimation();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    bool gameOn = true;
    while (gameOn) {
        player = rand() % 3;
        if (player == 0) player = 1;




        switch(player){
            case 1:
                cout << "It is " << p1.getName() << "'s turn." << endl;
                delay(2);
                cout << p1.getName() << "'s Hand is: " << p1.showHand() << endl;
                delay(2);
                Card p1Card = p1.chooseCardFromHand();
                cout << p1.getName() << ": Do you have any " << p1Card.rankString(p1Card.getRank()) << "'s?"<< endl;
                delay(2);

                cout << p2.getName() << "'s Hand: " << p2.showHand();
                delay(2);

                int p2CardCounter = 0;

                if(p2.cardInHand(p1Card)) {

                    cout << p2.getName() << ": Yes I do." << endl;
                    delay(2);

                    while (p2.cardInHand(p1Card)) {
                        Card p2Remove = p2.removeCardFromHand(p1Card);
                        p1.addCard(p2Remove);
                        cout << p2.getName() << " gives " << p1.getName() << " their " << p2Remove << endl
                        delay(2);
                        p2CardCounter++;
                    }

                    if (p2CardCounter > 1) {
                        p2.removeCardFromBook(p1Card);
                    }

                    p2CardCounter = 0;
                }

                else {
                    cout << p2.getName() << ": Go Fish!" << endl;
                    delay(2);
                    cout << p1.getName() << " fishes in the deck..." << endl;
                    delay(2);

                    if (d.size() != 0) {
                       Card p1Draw = p1.addCard(d.dealCard());
                       cout << p2.getName() << " draws a " << p1Draw << endl;
                       delay(2);
                    }
                    else {
                        cout << "No more cards to deal!" << endl;
                        delay(2);
                    }
                }

                cout << p1.getName() <<"'s Hand: " << p1.showHand() << endl;
                delay(2);

                Card book1, book2;
                if (p1.checkHandForBook(book1, book2)) {
                    while (p1.checkHandForBook(book1, book2){
                        p1.bookCards(book1, book2);
                        cout << "Book Found! " << p1.getName() << " books the " << book1 << " and " << book2 << endl;
                        delay(2);
                    }
                }

        }
    }

    cout << "finished" << endl;

    /*cout << p1.getName() << "'s Hand and Books" << endl;
    cout << p1.showHand() << endl;
    cout << p1.showBooks() << endl;

    cout << p2.getName() << "'s Hand and Books" << endl;
    cout << p2.showHand() << endl;
    cout << p2.showBooks() << endl;*/

    return EXIT_SUCCESS;
}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

void shuffleAnimation() {
    for (int i = 0; i < 5; i++) {
        cout << "Shuffling the deck" << endl;
        delay(1);
        system("clear");
        cout << "Shuffling the deck." << endl;
        delay(1);
        system("clear");
        cout << "Shuffling the deck.." << endl;
        delay(1);
        system("clear");
        cout << "Shuffling the deck..." << endl;
        delay(1);
        system("clear");
    }
}

void delay (int n){
    int dummy=0;
    const int DELAY = 100000000;

    for (int i = 0; i < n; i++) {
        while (dummy < DELAY){
            dummy++;
        }
        dummy = 0;
    }

}