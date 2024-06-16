#include "RowService.h"

void RowService::copyRow(Table& table, int rowNumber)
{

    std::vector<Cell*> curr;

    for (size_t i = 0; i < table.getColumns().size(); i++)
    {
        if (rowNumber > table.getColumns()[i].getColumn().size())
        {
            std::cout << "No such row exists!" << std::endl;
            return;
        }
        curr.push_back(table.getColumns()[i].getColumn()[rowNumber - 1]);
    }
    table.addRow(curr);

}

void RowService::addMinimalRow(Table& table)
{
    std::vector<Cell*> curr;

    Cell* currCellMin;

    for (size_t i = 0; i < table.getColumns().size(); i++)
    {
        std::string minValue = table.getColumns()[i].getColumn()[0]->getValue();
        currCellMin = table.getColumns()[i].getColumn()[0];

        for (size_t j = 0; j < table.getColumns()[i].getColumn().size() - 1; j++)
        {
            if (table.getColumns()[i].getColumn()[j + 1]->getValue() < minValue)
            {
                minValue = table.getColumns()[i].getColumn()[j + 1]->getValue();
                currCellMin = table.getColumns()[i].getColumn()[j + 1];
            }

        }
        curr.push_back(currCellMin);
    }
    table.addRow(curr);
}
void RowService::addMaximumRow(Table& table)
{
    std::vector<Cell*> curr;

    Cell* currCellMin;

    for (size_t i = 0; i < table.getColumns().size(); i++)
    {
        std::string maxValue = table.getColumns()[i].getColumn()[0]->getValue();
        currCellMin = table.getColumns()[i].getColumn()[0];

        for (size_t j = 0; j < table.getColumns()[i].getColumn().size() - 1; j++)
        {
            if (table.getColumns()[i].getColumn()[j + 1]->getValue() > maxValue)
            {
                maxValue = table.getColumns()[i].getColumn()[j + 1]->getValue();
                currCellMin = table.getColumns()[i].getColumn()[j + 1];
            }

        }
        curr.push_back(currCellMin);
    }
    table.addRow(curr);
}

void RowService::incrementCounter(Table& table, std::vector<int>& frequencies, int index)
{
    for (size_t i = 0; i < table.getColumns()[index].getColumn().size(); i++) {
        for (size_t j = 0; j < table.getColumns()[index].getColumn().size(); j++) {
            if (table.getColumns()[index].getColumn()[i]->getValue() == table.getColumns()[index].getColumn()[j]->getValue() && (j != 0)) {
                frequencies[i]++;
            }
        }
    }
}



void RowService::addMedianRow(Table& table)
{
    std::vector<Cell*> curr;
    Cell* currCellMin;


    for (size_t i = 0; i < table.getColumns().size(); i++)
    {
        std::vector<int> frequencies(table.getColumns()[i].getColumn().size(), 0);

        incrementCounter(table, frequencies, i);

        std::string mostFrequentValue = table.getColumns()[i].getColumn()[0]->getValue(); // Ќачална стойност за най-често срещаната стойност
        currCellMin = table.getColumns()[i].getColumn()[0];
        int maxFrequency = frequencies[0];



        for (size_t j = 0; j < table.getColumns()[i].getColumn().size(); j++)
        {
            /* if (frequencies[index] > maxFrequency || (frequencies[index] == maxFrequency && table.getColumns()[i].getColumn()[j]->getValue() < mostFrequentValue))
             {
                 mostFrequentValue = table.getColumns()[i].getColumn()[j]->getValue();
                 maxFrequency = frequencies[index++];
                 currCellMin = table.getColumns()[i].getColumn()[j];
             }*/

            if (frequencies[j] > maxFrequency)
            {
                mostFrequentValue = table.getColumns()[i].getColumn()[j]->getValue();
                maxFrequency = frequencies[j];
                currCellMin = table.getColumns()[i].getColumn()[j];
            }

        }

        curr.push_back(currCellMin);
    }
    table.addRow(curr);
}