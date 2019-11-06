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

        time_t current_time;
        current_time = time(NULL);
        srand(current_time);
    }

    void Deck::shuffle(){   // shuffle the deck, all 52 cards present
        unsigned int sw1=1, sw2=1;
        Card temp;

        for (int i = 0, i < SIZE*2; i++) {

            while (sw1 < myIndex || sw2 < myIndex) {
                sw1 = rand() % 52;
                sw2 = rand() % 52;
            }
            temp = myCards[sw1];
            myCards[sw1] = myCards[sw2];
            myCards[sw2] = temp;

        }



    }

    Card Deck::dealCard(){   // get a card, after 52 are dealt, fail 
        if(myIndex<52) {
            myIndex++;
            return myCards[myIndex-1];
        }
        else
            cout<<"No More Cards!"<<endl;
    }

    int  Deck::size() const{ // # cards left in the deck
        return (SIZE-(myIndex+1));
    }
