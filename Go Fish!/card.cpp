#include "card.h"
#include <stdlib>
#include <iostream>
#include <string>
using namespace std;

    Card::Card(){          // default, ace of spades
        myRank = 1;
        mySuit = spades;
    }

    Card::Card(int rank, Suit s){
        myRank = rank;
        mySuit = s;
    }

    Card::Card(const Card& c){
        this->myRank = c.myRank;
        this->mySuit = c.mySuit;
    }

    string Card::toString() const{               // return string version e.g. Ac 4h Js
        string rank = rankString(myRank);
        string suit = suitString(mySuit);

        return rank+suit;

    }
    
    bool Card::sameSuitAs(const Card& c) const{  // true if suit same as c
        if (this->mySuit == c.mySuit) {return true;}
        else {return false;}
    }    

    int  Card::getRank() const{                	 // return rank, 1..13
        return myRank;
    }   

    string Card::suitString(Suit s) const{	 // return "s", "h",...
        string suit;
        switch (s){
            case spades:
                suit = 's';
                break;
            case hearts:
                suit = 'h';
                break;
            case diamonds:
                suit = 'd';
                break;
            case clubs:
                suit = 'c';
                break;
        }
        return suit;
    }   

    string Card::rankString(int r) const{	 // return "A", "2", ...
        string rank;

        switch (r) {
            case 1:
                rank = 'A';
                break;
            case 11:
                rank = 'J';
                break;
            case 12:
                rank = 'Q';
                break;
            case 13:
                rank = 'K';
                break;
            default:
                rank = to_string(getRank());
        }

        return rank;
    }

    bool Card::operator == (const Card& rhs) const{
        if (this->myRank == rhs.myRank && this->mySuit == rhs.mySuit) {return true;}
        else {return false;}

    }

    bool Card::operator != (const Card& rhs) const{
        if (this->myRank != rhs.myRank || this->mySuit != rhs.mySuit) {return true;}
        else {return false;}

    }

    Card& Card::operator =(const Card c){
        this->myRank = c.myRank;
        this->mySuit = c.mySuit;

        return *this;
    }

    ostream& operator << (ostream& out, const Card &c){
    out << c.toString();
    return out;
    }
