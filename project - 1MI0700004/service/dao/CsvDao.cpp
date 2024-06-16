#include "CsvDao.h"

void CsvDao::readFromFile(Table& currentOpenTable, std::ifstream& file)
{
    char line[1024];

    std::vector<std::string> helpVector;

    file.getline(line, 1024);
    std::string temp = line;
    helpVector = split(temp);
    for (size_t i = 0; i < helpVector.size(); i++)
    {
        currentOpenTable.addColumn(Column(std::vector<Cell*>(), helpVector[i], i + 1));
    }

    while (file.getline(line, 1024)) {

        temp = line;
        helpVector = split(temp);

        for (size_t i = 0; i < helpVector.size(); i++)
        {
            currentOpenTable.getColumns()[i].addRowCell(new TextCell(helpVector[i]));
        }
    }
}

void CsvDao::writeInFile(Table& currentOpenTable, std::ofstream& file) 
{
    for (size_t i = 0; i < currentOpenTable.getColumns().size(); i++)
    {
        file << currentOpenTable.getColumns()[i].getValue() << ",";
    }
    file << std::endl;
    for (size_t i = 0; i < currentOpenTable.getColumns()[0].getColumn().size(); i++)
    {

        for (size_t j = 0; j < currentOpenTable.getColumns().size(); j++)
        {
            file << currentOpenTable.getColumns()[j].getColumn()[i]->getValue() << ",";
        }
        file << std::endl;
    }
}