#ifndef NUMBERCELL_H
#define NUMBERCELL_H

#include "Cell.h"
#include <string>
class NumberCell : public Cell {
private:
	std::string number;
public:

	NumberCell(int number);

	std::string getValue() const;

	virtual Cell* clone() const override;

	NumberCell& operator=(const NumberCell& other);

};

#endif 
