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
    string winner;

    Player p1("Tuna");
    Player p2("Cod");

    cout << p1.getName() << " and " << p2.getName() << " are ready to play!" << endl;
    delay(5);

    Deck d;
    d.shuffle();
    shuffleAnimation();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    player = rand() % 3;
    if (player == 0) player = 1;

    bool gameOn = true;
    while (gameOn) {

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
                    player = 1;
                }

                else {

                    cout << p2.getName() << ": Go Fish!" << endl;
                    delay(2);
                    cout << p1.getName() << " fishes in the deck..." << endl;
                    delay(2);

                    if (d.size() != 0) {
                       Card p1Draw = p1.addCard(d.dealCard());
                       cout << p1.getName() << " draws a " << p1Draw << endl;
                       delay(2);
                    }

                    else {

                        cout << "No more cards to deal!" << endl;
                        delay(2);

                    }

                    player = 2;

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

                if (p1.getBookSize() == WINSIZE) {

                    winner = p1.getName();
                    gameOn = false

                }
                break;

            case 2:

                cout << "It is " << p2.getName() << "'s turn." << endl;
                delay(2);
                cout << p2.getName() << "'s Hand is: " << p2.showHand() << endl;
                delay(2);
                Card p2Card = p2.chooseCardFromHand();
                cout << p2.getName() << ": Do you have any " << p1Card.rankString(p2Card.getRank()) << "'s?"<< endl;
                delay(2);

                cout << p1.getName() << "'s Hand: " << p1.showHand();
                delay(2);

                int p1CardCounter = 0;

                if(p1.cardInHand(p2Card)) {

                    cout << p1.getName() << ": Yes I do." << endl;
                    delay(2);

                    while (p1.cardInHand(p2Card)) {

                        Card p1Remove = p1.removeCardFromHand(p2Card);
                        p2.addCard(p1Remove);
                        cout << p1.getName() << " gives " << p2.getName() << " their " << p1Remove << endl
                        delay(2);
                        p1CardCounter++;
                    }

                    if (p1CardCounter > 1) {
                        p1.removeCardFromBook(p2Card);
                    }

                    p1CardCounter = 0;
                    player = 2;

                }

                else {

                    cout << p1.getName() << ": Go Fish!" << endl;
                    delay(2);
                    cout << p2.getName() << " fishes in the deck..." << endl;
                    delay(2);

                    if (d.size() != 0) {
                        Card p2Draw = p2.addCard(d.dealCard());
                        cout << p2.getName() << " draws a " << p2Draw << endl;
                        delay(2);
                    }
                    else {
                        cout << "No more cards to deal!" << endl;
                        delay(2);
                    }
                    player = 1;

                }

                cout << p2.getName() <<"'s Hand: " << p2.showHand() << endl;
                delay(2);

                Card book3, book4;

                if (p2.checkHandForBook(book3, book4))

                    while (p2.checkHandForBook(book3, book4){

                        p2.bookCards(book3, book4);
                        cout << "Book Found! " << p2.getName() << " books the " << book3 << " and " << book4 << endl;
                        delay(2);

                    }

                }

                if (p2.getBookSize() == WINSIZE) {
                    winner = p2.getName();
                    gameOn = false;
                }
                break;
        }
    }

    cout << "finished" << endl;

    cout << winner << " wins!";

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