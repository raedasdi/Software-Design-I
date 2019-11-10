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

        time_t current_time;
        current_time = time(NULL);
        srand(current_time);
    }

    void Deck::shuffle(){   // shuffle the deck, all 52 cards present
        unsigned int sw1=1, sw2=1;

        for (int i = 0; i < SIZE*2; i++) {

            while (sw1 < myIndex || sw2 < myIndex) {
                sw1 = rand() % 52;
                sw2 = rand() % 52;
            }

            Card temp(myCards[sw1]);
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
