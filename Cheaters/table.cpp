#include <stdio.h>
#include "table.h"


using namespace std;

Table::Table() {
    this->fileNum = 5;
    for (int i = 0; j < this->fileNum; i++){
        for(int j = 0; j < this->fileNum; j++){
            table[i][j] = 0;
        }
    }
}

Table::Table(int size) {
    this->fileNum = size;
    for (int i = 0; j < this->fileNum; i++){
        for(int j = 0; j < this->fileNum; j++){
            table[i][j] = 0;
        }
    }
}

void Table::addToTable(int row, int column) {
    this->table [row][column]++;
}

/*void Table::getCheaters() {
    string cheaters;

    for(int i = 0; i < fileNum; i++){
        for(int j = 0; j < fileNum; j++){
            if (table[i][j] > this->cheatingThreshold){

            }
        }
    }
}*/

int Table::getValueAt(int row, int col) {
    return table[row][col];
}

int Table::getFileNum() {
    return this->fileNum;
}