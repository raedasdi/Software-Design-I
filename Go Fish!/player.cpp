#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"
using namespace std;


    Player::Player();

    Player::Player(string name) {
       myName = name;
    }

    string Player::getName() const {
       return myName;
    }
    
    void Player::addCard(Card c){
        myHand.push_back(c);
    }

  //adds a card to the hand
    void Player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2){
       Card Card1,Card2;
        for(int i = 0; i < myHand.size();i++){
            Card1 = myHand.at(i);
            for (int j = i+1; j < myHand.size(); j++) {
                Card2 = myHand.at(j);
                if (Card1.getRank() == Card2.getRank()) {
                    c1 = Card1;
                    c2 = Card2;
                    return true;
                }
            }
       }
        else return false;
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
    Card Player::chooseCardFromHand() const{
        Card c1, c2;
        if(this->checkHandForBook(c1, c2)) {
            return c1;
        }
        else {
            return myHand.at(0);
        }
    } 
    
    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const{
        for (int i = 0; i < myHand.size(); i++){
             if (c == myHand.at(i)) return true;
        }
        return false;
    }
    
    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){
        for (int i = 0; i < myHand.size(); i++){
            if (c == myHand.at(i)) myHand.erase(myHand.begin()+i);
        }
    } 
    
    string Player::showHand() const{
        string out;
        for (int i = 0; i < myHand.size(); i++){
            out << myHand.at(i) << " ";
        }
        return out;
    }
 
    string Player::showBooks() const{
        string out;
        for (int i = 0; i < myBook.size(); i++){
            out << myBook.at(i)<< " ";
        }
        return out;
    }
    
    int Player::getHandSize() const{
        return myHand.size();
    }

    int Player::getBookSize() const{
        return myBook.size();
    }
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool Player::checkHandForPair(Card &c1, Card &c2) {
        Card Card1, Card2;
        for (int i = 0; i < myHand.size(); i++) {
            Card1 = myHand.at(i);
            for (int j = i + 1; j < myHand.size(); j++) {
                Card2 = myHand.at(j);
                if (Card1.getRank() == Card2.getRank()) {
                    c1 = Card1;
                    c2 = Card2;
                    return true;
                }
            }
        }
        else return false;
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
    