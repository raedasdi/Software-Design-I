/*This file contains the chunk class
 * Created by Ra'ed Asdi and Syed Usmani
 * EE312 Fall 2019
 */


#ifndef CHUNKS_H
#define CHUNKS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chunk{
private:
    int chunkSize;
    vector<string> chunkString;

public:

    Chunk::Chunk() {
        chunkSize = 6;
    }

    Chunk::Chunk(int n){
        chunkSize = n;
    }

    int getChunkSize(){
        return chunkSize;
    }

    void fillChunk()

};
#endif