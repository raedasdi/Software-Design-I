#include <card.h>
#include <iostream>
#include <string>
using namespace std;

    Card::Card(){          // default, ace of spades

    }

    Card::Card(int rank, Suit s){

    }

    string Card::toString() const{               // return string version e.g. Ac 4h Js

    }
    
    bool Card::sameSuitAs(const Card& c) const{  // true if suit same as c

    }    

    int  Card::getRank() const{                	 // return rank, 1..13
 
    }   

    string Card::suitString(Suit s) const{	 // return "s", "h",...
 
    }   

    string Card::rankString(int r) const{	 // return "A", "2", ...

    }

    /*bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;*/
