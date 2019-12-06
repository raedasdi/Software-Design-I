#include "chunk.h"
#include "folder.h"
#include "hashMap.h"
#include "table.h"
#include <string>

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
    string filePath = argv[1];
    int chunkSize = argv[2];
    int cheatingThreshold = argv[3];



    cout << "Opening directory at " << filePath << endl;

    Folder files(filePath);
    files.loadFiles(files.getPath());
    int fileNum = files.getFileNum();

    HashMap hash;
    Table matrix(fileNum);

    cout << "Parsing with chunk size " << to_string(chunkSize) << endl;

    Chunk chunks(chunkSize);

    for (int i = 0; i < fileNum; i++){
        chunks.fillDocString(filePath+files.getFileName(i));
        chunks.makeChunkList();

        cout << "Hashing for file " << files.getFileName(i) << endl;

        for (int j = 0; j < fileNum; j++){
            hash.push(chunks.getChunk(), i);
        }

        cout << "Hashing Complete" << endl;
    }


    return 0;
}