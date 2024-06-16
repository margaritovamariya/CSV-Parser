
#ifndef ROWSERVICE_H
#define ROWSERVICE_H


#include "../entities/Table.h"
#include <iostream>

class RowService {
public:

    void copyRow(Table& table, int rowNumber);
    void addMinimalRow(Table& table);
    void addMaximumRow(Table& table);
    void incrementCounter(Table& table, std::vector<int>& frequencies, int index);
    void addMedianRow(Table& table);
};


#endif 