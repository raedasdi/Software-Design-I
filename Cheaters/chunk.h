/*This file contains the chunk class
 * Created by Ra'ed Asdi and Syed Usmani
 * EE312 Fall 2019
 */


#ifndef CHUNK_H
#define CHUNK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chunk{
private:
    int chunkSize;
    vector<string> docstring;
    vector<string> chunkList;
public:
    /* Chunk - default chunk constructor
     * Initializes chunkSize to 6
     */
    Chunk();

    /* Chunk (with parameter) - constructor
     * Initializes chunkSize to n
     */
    Chunk(int n);

    /* getChunkSize - returns the same
     * Preconditions - none
     * Output - integer size
     */
    int getChunkSize();

    /* fillDocString - loads all words in document into vector
     * Precondition - chunkString must be empty
     * Output - docString contains all words in document
     */
    void fillDocString(string path);

    /* makeChunkList - Adds chunk to chunkList
     * Precondition - none
     * Output - Updated list with chunk in it
     */
    void makeChunkList(string chunk);

    /* emptyChunk - clears a chunk so that the next one can be put in
     * Precondition - None
     * Output - chunk is empty
     */
    string getChunk();

};
#endif