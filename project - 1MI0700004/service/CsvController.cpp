#include "CsvController.h"

void CsvController::openFile(std::string fileName)
{
    basicService.openFile(fileName, currentOpenTable);
}

void CsvController::saveFile()
{
    basicService.saveFile(currentOpenTable);
}

void CsvController::saveFileAs(std::string fileName)
{
    basicService.saveFileAs(currentOpenTable, fileName);
}

void  CsvController::closeFile()
{
    basicService.closeFile();
}

void CsvController::undo()
{
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    currentOpenTable = previousState;
    std::cout << "Undo done!" << std::endl;
}

void CsvController::printTable()
{
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    for (size_t i = 0; i < currentOpenTable.getColumns()[0].getColumn().size(); i++)
    {

        for (size_t j = 0; j < currentOpenTable.getColumns().size(); j++)
        {
            std::cout << currentOpenTable.getColumns()[j].getColumn()[i]->getValue() << " ";
        }
        std::cout << std::endl;
    }
}

void CsvController::setCurrentOpenTable(Table currentOpenTable)
{
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    this->currentOpenTable = currentOpenTable;
    previousState = currentOpenTable;
}

Table& CsvController::getCurrentOpenTable()
{

    return currentOpenTable;
}

void CsvController::removeColumnByName(std::string name) {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    columnService.removeColumnByName(currentOpenTable, name);
}

void CsvController::removeColumnByNumber(size_t number) {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    columnService.removeColumnByNumber(currentOpenTable, number);
}

void CsvController::columnRearrange(std::vector<int> permutation)
{
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    columnService.columnRearrange(currentOpenTable, permutation);
}


//    Table service
void CsvController::sortByColumnNumber(size_t number) {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    tableService.sortByColumnNumber(currentOpenTable, number);

    //��������� ������
    //���: column 1, column 2, column 3, 3 ����
    //��������� 1 � 3 ���

    // ��������� �� ����� �� ������ � ��������� �� ����� �� ���
    //��� 1: column 1[0], column 2[0], column 3[0]
    //��� 3: column 1[2], column 2[2], column 3[2]
    //������ �� ������������ � ������ ��� ����� �� �������, �������� ������ ������
}

void CsvController::sortByColumnName(std::string& name) {

}

void CsvController::filterByColumnNumber(size_t number) {

}

void CsvController::filterByColumnName(std::string& name) {

}

//Row service
void CsvController::copyRow(int rowNumber) {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    rowService.copyRow(currentOpenTable, rowNumber);
}

void CsvController::addMinimalRow() {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    rowService.addMinimalRow(currentOpenTable);
}

void CsvController::addMaximumRow() {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    rowService.addMaximumRow(currentOpenTable);
}

void CsvController::addMedianRow() {
    if (!basicService.getIfIsFileOpen())
    {
        std::cout << "You should open file!" << std::endl;
        return;
    }
    previousState = currentOpenTable;
    rowService.addMedianRow(currentOpenTable);
}