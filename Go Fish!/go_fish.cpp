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

// shuffleAnimation Function
// An animation for when the cards are shuffling, only for aesthetic purposes
void shuffleAnimation();

// delay Function
// Used in all animations and after each cout statement so that user can
// follow along with the game
void delay (int n);


int main (){
    srand((unsigned)time(0));
    int delayLen;
    int player = 0;
    int numCards = 7;
    const int WINSIZE = 14;     // amount of books needed to win

    bool gameOn = true;

    string winner;
   
    Player p1("Tuna");
    Player p2("Cod");

    Card p1Card, p2Card, book1, book2, p1Draw, p2Draw, p2Remove, p1Remove, book3, book4, newCard;   //will be needed in game impementation
    
    cout << "How much delay?\n0 - No Delay\n2 - Fast Game\n5 - Slow Game" << endl;      //allows user to control animation time
    cin >> delayLen;

    cout << p1.getName() << " and " << p2.getName() << " are ready to play!" << endl;
    if (delayLen != 0) delay(delayLen+3);

    Deck d;
    d.shuffle();
    if (delayLen != 0) shuffleAnimation();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    while (player == 0) {
        player = rand() % 3;
    }

    int nextPlayer = player;

    while (gameOn) {
        player = nextPlayer;

        switch(player){
            //Player 1 Turn
            case 1:
                system("clear");
                cout << "It is " << p1.getName() << "'s turn." << endl;
                delay(delayLen);

                //player will draw a card if their hand is empty

                if (p1.getHandSize() == 0) {

                    if (d.size() != 0) {
                        newCard = d.dealCard();
                        p1.addCard(newCard);
                    }
                }
                //Player 1 Chooses Card
                cout << p1.getName() << "'s Hand is: " << p1.showHand() << endl;
                delay(delayLen);
                p1Card = p1.chooseCardFromHand();
                cout << p1.getName() << ": Do you have any " << p1Card.rankString(p1Card.getRank()) << "'s?"<< endl;
                delay(delayLen);

                cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
                delay(delayLen);
                //Player 2 Response
                if(p2.getHandSize() != 0) {
                    //Player 2 has card
                    if (p2.sameRankInHand(p1Card)) {

                        cout << p2.getName() << ": Yes I do." << endl;
                        delay(delayLen);

                        while (p2.sameRankInHand(p1Card)) {
                            p2Remove = p2.removeCardFromHand(p1Card);
                            p1.addCard(p2Remove);
                            cout << p2.getName() << " gives " << p1.getName() << " their " << p2Remove << endl;
                            delay(delayLen);
                        }

                        nextPlayer = 1;     //Player 1 gets another turn
                    }
                    //Player 2 doesn't have card
                    else {
                        cout << p2.getName() << ": Go Fish!" << endl;
                        delay(delayLen);
                        cout << p1.getName() << " fishes in the deck..." << endl;
                        delay(delayLen);

                        if (d.size() != 0) {
                            p1Draw = d.dealCard();
                            p1.addCard(p1Draw);
                            cout << p1.getName() << " draws a " << p1Draw << endl;
                            delay(delayLen);
                        } else {
                            cout << "No more cards to deal!" << endl;
                            delay(delayLen);
                        }

                        nextPlayer = 2;     //Player 1's turn is over, Player 2 is next
                    }
                }
                //Player 2 has no cards
                else {
                    cout << p2.getName() << ": Go Fish!" << endl;
                    delay(delayLen);
                    cout << p1.getName() << " fishes in the deck..." << endl;
                    delay(delayLen);

                    if (d.size() != 0) {
                        p1Draw = d.dealCard();
                        p1.addCard(p1Draw);
                        cout << p1.getName() << " draws a " << p1Draw << endl;
                        delay(delayLen);
                    } else {
                        cout << "No more cards to deal!" << endl;
                        delay(delayLen);
                    }

                    nextPlayer = 2;         //Player 1's turn is over, Player 2 is next
                }
                cout << p1.getName() <<"'s Hand: " << p1.showHand() << endl;
                delay(delayLen);
                //Player 1 will check their hand for any books
                if (p1.checkHandForBook(book1, book2)) {

                        p1.bookCards(book1, book2);
                        cout << "Book Found! " << p1.getName() << " books the " << book1 << " and " << book2 << endl;
                        delay(delayLen);
                        cout << p1.getName() << " has " << p1.getBookSize() << " books." << endl;
                        delay(delayLen);

                }
                //checks to see if Player 1 has won
                if (p1.getBookSize() == WINSIZE) {

                    winner = p1.getName();
                    gameOn = false;

                }

                break;
            //Player 2 Turn
            case 2:
                system("clear");
                cout << "It is " << p2.getName() << "'s turn." << endl;
                delay(delayLen);
                //player will draw a card if their hand is empty
                if (p2.getHandSize() == 0) {
                    if (d.size() != 0) {
                        newCard = d.dealCard();
                        p2.addCard(newCard);
                    }
                }
                //Player 2 Chooses Card
                cout << p2.getName() << "'s Hand is: " << p2.showHand() << endl;
                delay(delayLen);
                p2Card = p2.chooseCardFromHand();
                cout << p2.getName() << ": Do you have any " << p2Card.rankString(p2Card.getRank()) << "'s?"<< endl;
                delay(delayLen);

                cout << p1.getName() << "'s Hand: " << p1.showHand() << endl;
                delay(delayLen);
                //Player 1's Response
                if(p1.getHandSize() !=0) {
                    //Player 1 has card
                    if (p1.sameRankInHand(p2Card)) {
                        cout << p1.getName() << ": Yes I do." << endl;
                        delay(delayLen);

                        while (p1.sameRankInHand(p2Card)) {
                            p1Remove = p1.removeCardFromHand(p2Card);
                            p2.addCard(p1Remove);
                            cout << p1.getName() << " gives " << p2.getName() << " their " << p1Remove << endl;
                            delay(delayLen);
                        }

                        nextPlayer = 2;     //Player 2 gets another turn
                    }
                    //Player 1 doesn't have card
                    else {
                        cout << p1.getName() << ": Go Fish!" << endl;
                        delay(delayLen);
                        cout << p2.getName() << " fishes in the deck..." << endl;
                        delay(delayLen);

                        if (d.size() != 0) {
                            p2Draw = d.dealCard();
                            p2.addCard(p2Draw);
                            cout << p2.getName() << " draws a " << p2Draw << endl;
                            delay(delayLen);
                        } else {
                            cout << "No more cards to deal!" << endl;
                            delay(delayLen);
                        }

                        nextPlayer = 1;     //Player 2's turn is over, Player 1 is next
                    }
                }
                //Player 1 has no cards
                else {
                    cout << p1.getName() << ": Go Fish!" << endl;
                    delay(delayLen);
                    cout << p2.getName() << " fishes in the deck..." << endl;
                    delay(delayLen);

                    if (d.size() != 0) {
                        p2Draw = d.dealCard();
                        p2.addCard(p2Draw);
                        cout << p2.getName() << " draws a " << p2Draw << endl;
                        delay(delayLen);
                    } else {
                        cout << "No more cards to deal!" << endl;
                        delay(delayLen);
                    }
                    nextPlayer = 1;         //Player 2's turn is over, Player 1 is next
                }

                cout << p2.getName() <<"'s Hand: " << p2.showHand() << endl;
                delay(delayLen);
                //Player 2 will check their hand for any books
                if (p2.checkHandForBook(book3, book4)) {
                    p2.bookCards(book3, book4);
                    cout << "Book Found! " << p2.getName() << " books the " << book3 << " and " << book4 << endl;
                    delay(delayLen);
                    cout << p2.getName() << " has " << p2.getBookSize() << " books." << endl;
                    delay(delayLen);
                }
                //Checks to see if Player 2 has won
                if (p2.getBookSize() == WINSIZE) {
                    winner = p2.getName();
                    gameOn = false;
                }
                break;
        }
    }

    cout << winner << " wins!" << endl;

    return 0;
}

// dealHand Function
// Taken from card_demo.cpp provided in online class source code
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

// shuffleAnimation Function
// An animation for when the cards are shuffling, only for aesthetic purposes
void shuffleAnimation() {
    for (int i = 0; i < 5; i++) {
        system("clear");
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

// delay Function
// Used in all animations and after each cout statement so that user can
// follow along with the game
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