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
                cheaters = files.getFileName(i) + " " + files.getFileName(j) + " " + to_string(matrix.getValueAt(i, j));
                cheaterList.push_back(cheaters);
                cheaters = "";
            }
        }
    }
}



int main(int argc, char*argv[]){
    string filePath = argv[1];
    int chunkSize = stoi(argv[2]);
    int cheatingThreshold = stoi(argv[3]);



    cout << "Opening directory at " << filePath << endl;

    Folder files(filePath);

    files.loadFiles(files.getPath());


    int fileNum = files.getFileNum();

    cout << "Number of files " << fileNum << endl;

    HashMap hash;
    Table matrix(fileNum);

    cout << "Parsing with chunk size " << to_string(chunkSize) << endl;

    Chunk chunks(chunkSize);
    string random;
    for (int i = 0; i < fileNum; i++){
      random = '/'+filePath+files.getFileName(i);
      //cout << random << endl;
       chunks.fillDocString(random);
        chunks.makeChunkList();

        cout << "Hashing for file " << files.getFileName(i) << endl;
        int chunkListSize = chunks.getChunkVectorSize();
        cout << chunkListSize << endl;
        for (int j = 0; j < chunkListSize; j++){
         hash.push(chunks.getChunk(), i);
        }

        cout << "Hashing Complete" << endl;
    }
   hash.print();
    for (int i = 0; i < 1000003; i++){
      vector<int> temp;
      if (hash.hashMap[i] != NULL){
         cout<<"At list2vector" <<endl;
         hash.list2vector(i, temp);
         cout << "done" <<endl;
      }
      // cout << temp.at(0);
      // cout << temp.size() << endl;
      if (temp.size() > 1){
      for (int column = 0; column < temp.size(); column++){
         for (int row = column+1; row < temp.size(); row++){
            matrix.addToTable(temp[row],temp[column]);
            cout << matrix.getValueAt(temp[row],temp[column]) << endl;
         }
      }
    }
}

        matrix.showTable();




    return 0;
}
