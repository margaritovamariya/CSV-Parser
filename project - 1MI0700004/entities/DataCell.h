#ifndef DATACELL_H
#define DATACELL_H

#include "Cell.h"
#include <string>
class DataCell : public Cell {
private:
	std::string data;
public:

	DataCell(std::string data);

	std::string getValue() const;

	virtual Cell* clone() const override;

	DataCell& operator=(const DataCell& other);

};

#endif 
