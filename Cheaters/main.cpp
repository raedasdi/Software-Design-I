#include "chunk.h"
#include "folder.h"
#include "hashMap.h"
#include "table.h"

void getCheaters(Table &matrix, Folder &files, int cheatingThreshold) {
    string cheaters;
    vector<string> cheaterList;

    for(int i = 0; i < matrix.getFileNum(); i++){
        for(int j = i+1; j < matrix.getFileNum(); j++){
            if (matrix.getValueAt(i, j) > cheatingThreshold){
                cheaters << files.getFileName(i) << " " << files.getFileName(j) << " " << matrix.getValueAt(i, j);
                cheaterList.push_back(cheaters);
                cheaters = NULL;
            }
        }
    }
}

int main(int argc, char*argv[]){


    return 0;
}