#ifndef BASICSERVICE_H
#define BASICSERVICE_H


#include "dao/CsvDao.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../entities/Table.h"

class BasicService {
private:
    CsvDao dao;

    bool isFileOpen = false;
    std::string openFileName = "";
public:
    
    void openFile(std::string fileName, Table& currentOpenTable);
    void saveFile(Table& currentOpenTable);
    void saveFileAs(Table& currentOpenTable, std::string newFile);   
    void closeFile();
    bool getIfIsFileOpen();
};


#endif 
