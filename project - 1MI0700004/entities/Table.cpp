#include "Table.h"


Table::Table()
{
    
}
Table::Table(std::vector<Column> columns)
{
    setColumns(columns);
}

void Table::addColumn(const Column& newColumn) {
    columns.push_back(newColumn);
}

void Table::addRow(std::vector<Cell*> data) {

    for (int i = 0; i < data.size(); i++) {
        columns[i].addRowCell(data[i]);
    }
    
}

std::vector<Cell*> Table::getRow(int number)
{
    std::vector<Cell*> temp;
    for (size_t i = 0; i < columns.size(); i++)
    {
        temp.push_back(columns[i].getColumn()[number-1]);
    }

    return temp;
}


std::vector<Column>& Table::getColumns() {
    return this->columns;
}

void Table::setColumns(const std::vector<Column>& columns) {
    Table::columns = columns;
}

Table& Table::operator=(const Table& other)
{
    columns.resize(other.columns.size());

    if (this != &other)
    {
        for (size_t i = 0; i < columns.size(); i++)
        {
            columns[i] = other.columns[i];
        }
    }
    return *this;
}