/*This file contains the table (2D array) class
 * Created by Ra'ed Asdi and Syed Usmani
 * EE312 Fall 2019
 */
#ifndef TABLE_H
#define TABLE_H


using namespace std;

class Table{
private:
    int fileNum;
    int table [fileNum];

public:
    Table();

    Table(int size);

    void addToTable(int row, int column);

    int getValueAt(int row, int col);

    int getFileNum();
};

#endif