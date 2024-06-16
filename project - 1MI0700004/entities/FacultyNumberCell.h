#ifndef FACULTYNUMBERCELL_H
#define FACULTYNUMBERCELL_H

#include "Cell.h"
#include <string>
class FacultyNumberCell : public Cell {
private:
	std::string fn;
public:

	FacultyNumberCell(std::string fn);

	std::string getValue() const;

	virtual Cell* clone() const override;

	FacultyNumberCell& operator=(const FacultyNumberCell& other);
};

#endif 
