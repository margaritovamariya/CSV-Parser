#include "Column.h"
#include <iostream>

Column::Column(std::vector<Cell*> column, std::string name, size_t number) : name(name), number(number)
{
    setColumn(column);
}

void Column::addRowCell(Cell* newCell) {

    column.push_back(newCell);
  }

const std::vector<Cell*>& Column::getColumn() const {
    return column;
}

void Column::setColumn(const std::vector<Cell*>& column) {
    Column::column = column;
}

std::string Column::getValue() const {
    return name;
}

size_t Column::getNumber() const {
    return number;
}


Column& Column::operator=(const Column& other)
{
    if (this != &other)
    {
        name = other.name;
        number = other.number;
        column.resize(other.column.size());

        for (size_t i = 0; i < other.column.size(); i++)
        {
            column[i] = other.column[i]->clone();
        }
    }return *this;
}