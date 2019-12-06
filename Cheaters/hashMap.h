/*This file contains the hash map class
 * Created by Ra'ed Asdi and Syed Usmani
 * EE312 Fall 2019
 */
#ifndef HASHMAP_H
#define HASHMAP_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class HashMap{

private:
    struct HashNode {
        int index;
        HashNode *next;
    };
    vector<HashNode *> hashMap;



public:
    HashMap(){
        for (int i = 0; i < 10000000; i++){
            HashNode *temp = NULL;
            hashMap.push_back(temp);
        }
    }

    vector<HashNode *> getMap(){
        return hashMap;
    }

    void print(){
        for (int i = 0; i < 10000000; i++){
            if (hashMap.at(i) != NULL){
                // cout << "0" << endl;
                HashNode *temp = hashMap.at(i);
                while (temp != NULL){
                    cout << temp->index << endl;
                    temp = temp->next;
                }
            }
        }
    }
    void push(string const &s, int fileIndex){
        long key = 0;
        for (int i = 0; i < s.length(); i++){
            char character = s[s.length()-i-1];
            int ascii = int(character);
            // cout << ascii << endl;
            long add = (long) abs((ascii*pow(7, i))) % 10000000;

            key = (key+add)  % 10000000 ;
            // cout << key << endl;
        }
        if (hashMap.at(key) == NULL){
            HashNode *temp = new HashNode;
            temp->index = fileIndex;
            temp->next = NULL;
            hashMap.at(key) = temp;
            // hashMap.at(key)->index = fileIndex;
            // hashMap.at(key)->next = NULL;
        }
        else{
            HashNode *temp = new HashNode;
            temp->index = fileIndex;
            temp->next = hashMap.at(key);
            hashMap.at(key) = temp;
        }
    }

};
#endif