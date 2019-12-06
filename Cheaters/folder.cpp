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

int Folder::loadFiles(string dir, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

string Folder::getFileName(int index) {
    return files[index];
}
