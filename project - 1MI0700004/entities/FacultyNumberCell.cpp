#include "FacultyNumberCell.h"
#include <iostream>

FacultyNumberCell::FacultyNumberCell(std::string fn) :fn(fn)
{
}

std::string FacultyNumberCell::getValue() const
{
	return fn;
}

Cell* FacultyNumberCell::clone() const {
	return new FacultyNumberCell(*this);
}

FacultyNumberCell& FacultyNumberCell::operator=(const FacultyNumberCell& other)
{
	if (this != &other)
	{
		fn = other.fn;
	}
	return *this;
}