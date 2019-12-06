/*This file contains the Folder class
 * Created by Ra'ed Asdi and Syed Usmani
 * EE312 Fall 2019
 */
#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include <string>
#include <iostream>
#include <ifstream>
#include "chunks.h"

using namespace std;

class Folder{
private:
    string path;
    vector<string> files;

public:
    Folder();

    Folder(string path);
    /* loadFiles - used provided code on website for getting list of files into vector
     * 
     */
    int loadFiles();

    string getFileName(int index);

};
#endif