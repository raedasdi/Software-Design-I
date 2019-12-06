#include <stdio.h>
#include "table.h"
#include <iostream>


using namespace std;

Table::Table() {
    this->fileNum = 5;

    table = new int* [fileNum];

    for (int it = 0; it < this->fileNum; it++){
        table[it] = new int [fileNum];
    }

    for (int i = 0; i < this->fileNum; i++){
        for(int j = 0; j < this->fileNum; j++){
            table[i][j] = 0;
        }
    }
}

Table::Table(int size) {
    this->fileNum = size;

    table = new int* [fileNum];

    for (int it = 0; it < this->fileNum; it++){
        table[it] = new int [fileNum];
    }

    for (int i = 0; i < this->fileNum; i++){
        for(int j = 0; j < this->fileNum; j++){
            table[i][j] = 0;
        }
    }
}

void Table::addToTable(int row, int column) {
    table [row][column]++;
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

void Table::showTable() {
    for (int i = 0; i < fileNum; i++){
        for (int j = 0; j < fileNum; j++){
            if (j <= i) cout << ' ';
            else {
                cout << this->getValueAt(i, j) << ' ';
                if (j == fileNum - 1) cout << endl;
            }
        }
    }
}