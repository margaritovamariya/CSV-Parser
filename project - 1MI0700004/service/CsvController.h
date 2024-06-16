#ifndef CSVCONTROLLER_H
#define CSVCONTROLLER_H


#include "BasicService.h"
#include "ColumnService.h"
#include "RowService.h"
#include "TableService.h"
#include "../entities/Table.h"

class CsvController {
private:
    BasicService basicService;
    ColumnService columnService;
    RowService rowService;
    TableService tableService;

    Table previousState;
    Table currentOpenTable;
public:

    void printTable();
    void setCurrentOpenTable(Table currentOpenTable);
    Table& getCurrentOpenTable();

   //Basic service
    void openFile(std::string fileName);
    void saveFile();
    void saveFileAs(std::string fileName);
    void undo();
    void closeFile();

    // Column service
    void removeColumnByName(std::string name);
    void removeColumnByNumber(size_t number);
    void columnRearrange(std::vector<int> permutation);
    
    // Table service
    void sortByColumnNumber(size_t number);
    void sortByColumnName(std::string& name);
    void filterByColumnNumber(size_t number);
    void filterByColumnName(std::string& name);

    // Row service
    void copyRow(int rowNumber);
    void addMinimalRow();
    void addMaximumRow();
    void addMedianRow();
};


#endif 
