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
   void push(string const &s, int fileIndex){
      int key = 0;
      for (int i = 0; i < s.length(); i++){
         char character = s[s.length()-i-1];
         int ascii = int(character);
         key += ascii*pow(27, i);
      }
      hashMap.at(key)->index = fileIndex;
   }

};
#endif
