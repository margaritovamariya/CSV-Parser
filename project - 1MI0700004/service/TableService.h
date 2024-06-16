#ifndef TABLESERVICE_H
#define TABLESERVICE_H


#include "../entities/Table.h"

class TableService {
public:
    void sortByColumnNumber(Table& table, size_t number);

    void sortByColumnName(Table& table, std::string& name);

    void filterByColumnNumber(Table& table, size_t number);

    void filterByColumnName(Table& table, std::string& name);
};


#endif 
