#include <vector>
#include <string>
#include <iostream>
#include "folder.h"

using namespace std;

Folder::Folder() {
    this->path = "/"
}

Folder::Folder(string path) {
    this->path = path;
    if (path.back() != '/'){
        this->path += '/';
    }
}

void Folder::loadFiles() {

}

string Folder::getFileName(int index) {
    return files[index];
}