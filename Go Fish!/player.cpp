#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "player.h"
#include "card.h"
using namespace std;

    void Player::addCard(Card c){
        myHand.push_back(c);
    }

  //adds a card to the hand
    void Player::bookCards(Card c1, Card c2){
        vector<Card>::iterator it = myHand.begin(); //iterator initialization found on cplusplus.com
        Card push = c1;

        for (int i = 0; i < 2; i++){

            switch(i) {
                case 0:
                    push = c1;
                    break;
                case 1:
                    push = c2;
                    break;
            }

            it = myHand.begin();

            while (it < myHand.end()) {             //iterator goes through hand to find card to book, then removes
                                                    //it from hand
                if (*it == push) {
                    myBook.push_back(push);
                    myHand.erase(it);
                }

                it++;
            }
        }

    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2){
        for(int i = 0; i < myHand.size();i++){              //essentially a select sort but instead it checks for
            Card Card1(myHand.at(i));                       //two cards of the same rank

            for (int j = i+1; j < myHand.size(); j++) {
                Card Card2(myHand.at(j));

                if (Card1.getRank() == Card2.getRank()) {
                    c1 = Card1;
                    c2 = Card2;
                    return true;
                }
            }
       }
       return false;
    }

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    bool Player::rankInHand(Card c) const{
        int currRank = 0;
        int cardRank = c.getRank();
        Card currCard;

        for (int i = 0; i < myHand.size(); i++){
            currCard = myHand.at(i);
            currRank = currCard.getRank();
            if (currRank == cardRank) return true;
        }
        return false;
    }
    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const{        //no real strategy, will just choose random card from Hand
        int i = rand() % myHand.size();
        Card pick = myHand.at(i);
        return pick;

    } 
    
    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const{
        for (int i = 0; i < myHand.size(); i++){
             if (c == myHand.at(i)) return true;
        }
        return false;
    }


    bool Player::cardsInBook(Card c) const{
        if (getBookSize() == 0) return false;
        for (int i = 0; i < myHand.size(); i++){
            if (c == myHand.at(i)) return true;
        }
        return false;
    }
    
    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){

        Card removeCard;
        vector<Card>::iterator it = myHand.begin();

        for(int i = 0; i < myHand.size(); i++){
            if(myHand.at(i).getRank() == c.getRank()){
                removeCard = myHand.at(i);
                while (*it != myHand.at(i)){
                    it++;
                }
                myHand.erase(it);
                myHand.shrink_to_fit();
            }
        }

        return removeCard;
    }

    string Player::showHand() const{
        string out = " ";
        Card c;
        for (int i = 0; i < myHand.size(); i++){
            c = myHand.at(i);
            out += c.toString();
            out += " ";
        }
        return out;
    }
 
    string Player::showBooks() const{
        string out = " ";
        Card c;
        for (int i = 0; i < myBook.size(); i++){
            c = myBook.at(i);
            out += c.toString();
            out += " ";
        }
        return out;
    }
    
    int Player::getHandSize() const{
        return myHand.size();
    }

    int Player::getBookSize() const{
        return (myBook.size()/2);
    }
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForPair(Card &c1, Card &c2) {
        for (int i = 0; i < myHand.size(); ++i) {
            Card Card1(myHand.at(i));
            for (int j = i + 1; j < myHand.size(); j++) {
                Card Card2(myHand.at(j));
                if (Card1.getRank() == Card2.getRank()) {
                    c1 = Card1;
                    c2 = Card2;
                    return true;
                }
            }
        }
        return false;
    }

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    
    bool Player::sameRankInHand(Card c) const{
        int cRank = c.getRank();
        Card currCard;
        for (int i = 0; i < myHand.size(); i++){
            currCard = myHand.at(i);
            if (cRank == currCard.getRank()) return true;
        }
        return false;
    } 
    