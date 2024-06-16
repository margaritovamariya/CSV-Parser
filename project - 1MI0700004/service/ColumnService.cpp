#include "ColumnService.h"

void ColumnService::removeColumnByName(Table& table, std::string& name) {
    for (int i = 0; i < table.getColumns().size(); ++i) {
        if (table.getColumns()[i].getValue() == name) {
            table.getColumns().erase(table.getColumns().begin() + i);
        }
    }
}

void ColumnService::removeColumnByNumber(Table& table, size_t number) {
    for (int i = 0; i < table.getColumns().size(); ++i) {
        if (table.getColumns()[i].getNumber() == number) {
            table.getColumns().erase(table.getColumns().begin() + i);
        }
    }
}

void ColumnService::columnRearrange(Table& table, std::vector<int> permutation) {
    
    Table tableTemp;
    for (size_t i = 0; i < permutation.size(); i++)
    {
        tableTemp.addColumn(table.getColumns()[permutation[i] - 1]);
    }
   
    table = tableTemp;

}