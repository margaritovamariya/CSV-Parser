
#include <iostream>
#include "entities/Table.h"
#include "entities/TextCell.h"
#include "entities/FacultyNumberCell.h"
#include "entities/NumberCell.h"
#include "entities/DataCell.h"
#include "service/CsvController.h"
#include "service/Commands.h"


int main()
{
    Commands commands;
    commands.run();

    return 0;
}

