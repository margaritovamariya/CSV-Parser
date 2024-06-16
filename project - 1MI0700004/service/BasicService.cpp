#include "BasicService.h"

void BasicService::openFile(std::string fileName, Table& currentOpenTable)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return;
    }
    dao.readFromFile(currentOpenTable, file);
    isFileOpen = true;
    openFileName = fileName;
    std::cout << "File opened successfuly!" << std::endl;
    file.close();
}

void BasicService::saveFile(Table& currentOpenTable)
{
    if (isFileOpen)
    {
        std::ofstream file(openFileName);
        if (!file.is_open())
        {
            std::cout << "File can't be opened!" << std::endl;
            return;
        }

        dao.writeInFile(currentOpenTable, file);



        file.close();
    }
}

void BasicService::saveFileAs(Table& currentOpenTable, std::string newFile)
{
    std::ofstream file(newFile);
    if (!file.is_open())
    {
        std::cout << "File can't be opened!" << std::endl;
        return;
    }

    dao.writeInFile(currentOpenTable, file);

    file.close();
   
}



void BasicService::closeFile()
{
    if (isFileOpen)
    {
        isFileOpen = false;
        openFileName = "";
    }
}

bool BasicService::getIfIsFileOpen()
{
    return isFileOpen;
}