#include "deck.h"
#include "card.h"
#include <ctime>

using namespace std;   
    
    Deck::Deck(){           // pristine, sorted deck
        myIndex = 0;
        for (int i = 0; i < 4; i++){
            for (int j = 1; j < 14; j++){
                myCards[myIndex] = Card c(j, i);
                myIndex++;
            }
        }
        myIndex = 0;
    }

    void Deck::shuffle(){   // shuffle the deck, all 52 cards present
        srand((unsigned)time(0));

        int sw1, sw2;


        sw1 = rand() % 52;
        sw2 = rand() % 52;

        while (sw1 == sw2) {
            sw1 = rand() % 52;
        }
        


    }

    Card Deck::dealCard(){   // get a card, after 52 are dealt, fail 

    }

    int  Deck::size() const{ // # cards left in the deck

    }
