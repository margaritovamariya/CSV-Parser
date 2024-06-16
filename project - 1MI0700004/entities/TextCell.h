#ifndef TEXTCELL_H
#define TEXTCELL_H

#include "Cell.h"
#include <string>
class TextCell : public Cell {
private:
	std::string text;
public:

	TextCell(std::string text);

	std::string getValue() const;

	virtual Cell* clone() const override;
	
	TextCell& operator=(const TextCell& other);
};

#endif 
