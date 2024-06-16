#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Column.h"

class Table {
private:
    std::vector<Column> columns;

public:

    Table();

    Table(std::vector<Column> columns);

    void addColumn(const Column& newColumn);

    void addRow(std::vector<Cell*> data);

    std::vector<Cell*> getRow(int number);

    std::vector<Column>& getColumns();
    
    void setColumns(const std::vector<Column>& columns);

    Table& operator=(const Table& other);

};


#endif 
