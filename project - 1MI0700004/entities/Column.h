#ifndef COLUMN_H
#define COLUMN_H
#include <vector>
#include "Cell.h"
#include <string>

class Column {
private:
    std::vector<Cell*> column;
    std::string name;
    size_t number;

public:
    Column() {}
    Column(std::vector<Cell*> column,std::string name, size_t number);
    
    void addRowCell(Cell* newCell);

    const std::vector<Cell*>& getColumn() const;

    void setColumn(const std::vector<Cell*>& column);

    std::string getValue() const;

    size_t getNumber() const;

    Column& operator=(const Column& other);

};

#endif 
