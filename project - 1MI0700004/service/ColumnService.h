#ifndef COLUMNSERVICE_H
#define COLUMNSERVICE_H


#include <string>
#include "../entities/Table.h"

class ColumnService {
public:

    void removeColumnByName(Table& table, std::string& name);
    void removeColumnByNumber(Table& table, size_t number);
    void columnRearrange(Table& table, std::vector<int> permutation);
};


#endif 
