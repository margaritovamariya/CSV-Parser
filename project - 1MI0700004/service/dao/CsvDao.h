#ifndef CSVDAO_H
#define CSVDAO_H

#include "../../entities/Cell.h"
#include "../../entities/Table.h"
#include "../../entities/TextCell.h"
#include "../Utils/StringUtils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CsvDao {

public:
    void readFromFile(Table& currentOpenTable, std::ifstream& file);

	void writeInFile(Table& currentOpenTable, std::ofstream& file);

};

#endif 
