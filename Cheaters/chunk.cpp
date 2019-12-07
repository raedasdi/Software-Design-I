#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "chunk.h"
#include <cctype>

using namespace std;

Chunk::Chunk() {
    chunkSize = 6;
    index = 0;
}

Chunk::Chunk(int n){
    chunkSize = n;
    index = 0;
}

int Chunk::getChunkSize(){
    return chunkSize;
}

void Chunk::fillDocString(string path) {
    fstream file;
    index = 0;
    // cout << path << endl;
    file.open(path.c_str());
    string temp;
    string push;
    while (file >> temp)
    {
         int j = 0;
         for (int i = 0; i < temp.length(); i++){

            if ((temp[i] <= 90 && temp[i] >= 65) || (temp[i] <= 122 && temp[i] >= 97)){
               push[j] = temp[i];
               j++;
            }
         }
         for (int i = 0; i < push.length(); i++)
         {
            if (push[i] <= 90 && push[i] >= 65){
               push[i] += 32;
            }
         }
         docstring.push_back(push);

    }

    //cout << docstring.size();
    // file.close();
}

void Chunk::makeChunkList() {
    string chunk, temp;
    int j;


    while (docstring.size() > this->chunkSize) {
        j = 0;
        while(j < this->chunkSize){
            temp = docstring.at(j);
            // for (string::iterator i = temp.begin(); i < temp.end(); i++){
            //     if(!isalnum(*i)) temp.erase(i);
            // }

            chunk+=temp;
            j++;
        }
        docstring.erase(docstring.begin());
        chunkList.push_back(chunk);
    }
}

string Chunk::getChunk() {
    string chunk = chunkList[index];
    index++;

    return chunk;
}
