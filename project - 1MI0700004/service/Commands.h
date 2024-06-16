#ifndef COMMANDS_H
#define COMMANDS_H

#include "CsvController.h"
#include <iostream>

class Commands
{
private:
	CsvController object;
	std::string filePath;

	void commands();
public:
	void run();
};

#endif 
