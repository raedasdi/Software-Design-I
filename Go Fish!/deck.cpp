#include "deck.h"
#include "card.h"
#include <ctime>

using namespace std;   
    
    Deck::Deck(){           // pristine, sorted deck
        myIndex = 0;
        Card::Suit s;
        for (int i = 0; i < 4; i++){
            switch(i){
                case 0:
                    s = Card::spades;
                    break;
                case 1:
                    s = Card::hearts;
                    break;
                case 2:
                    s = Card::diamonds;
                    break;
                case 3:
                    s = Card::clubs;
                    break;
            }
            for (int j = 1; j < 14; j++){

                myCards[myIndex] = *(new Card(j, s));
                myIndex++;
            }
        }

        myIndex = 0;

        srand((unsigned)time(0));
    }

    void Deck::shuffle(){   // shuffle the deck, all 52 cards present
        unsigned int sw1=1, sw2=1;
        Card temp;

        for (int i = 0; i < SIZE*2; i++) {
                sw1 = (rand() % SIZE);
                sw2 = (rand() % SIZE);

                temp = myCards[sw1];
                myCards[sw1] = myCards[sw2];
                myCards[sw2] = temp;

        }



    }

    Card Deck::dealCard(){   // get a card, after 52 are dealt, fail
            myIndex++;
            return myCards[myIndex-1];
    }

    int  Deck::size() const{ // # cards left in the deck
        return (SIZE-myIndex);
    }
