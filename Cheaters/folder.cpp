#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include "folder.h"

using namespace std;

Folder::Folder() {
    this->path = "/";
}

Folder::Folder(string path) {
    this->path = path;
    if (path.back() != '/'){
        this->path += '/';
    }
}

int Folder::loadFiles(string dir) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        this->files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    files.erase(files.begin());
    files.erase(files.begin());
    return 0;
}

string Folder::getFileName(int index) {
    return files[index];
}

string Folder::getPath() {
    return this->path;
}

vector<string> Folder::getFiles() {
    return this->files;
}

int Folder::getFileNum() {
    return this->files.size();
}