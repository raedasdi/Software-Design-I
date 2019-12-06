#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "chunk.h"
#include <cctype>

using namespace std;

Chunk::Chunk() {
    chunkSize = 6;
}

Chunk::Chunk(int n){
    chunkSize = n;
}

int Chunk::getChunkSize(){
    return chunkSize;
}

void Chunk::fillDocString(string path) {
    ifstream file;
    file.open(path);
    string temp;

    while (!file.eof()){
        file >> temp;
        chunkList.push_back(temp);
    }
}

void Chunk::makeChunkList() {
    string chunk, temp;
    int j;


    while (docstring.size() > 0) {
        j = 0;
        while(j < this->chunkSize){
            temp = docstring.at(j);
            for (string::iterator i = temp.begin(); i < temp.end(); i++){
                if(!isalnum(*i)) temp.erase(i);
            }

            chunk+=temp;
            j++;
        }
        docstring.erase(docstring.begin());
        chunkList.push_back(chunk);
    }
}

string Chunk::getChunk() {
    string chunk = chunkList.at(0);
    chunkList.erase(chunkList.begin());
    return chunk;
}
