#include "NumberCell.h"
#include <iostream>

NumberCell::NumberCell(int number) 
{
	this->number = std::to_string(number);
}

std::string NumberCell::getValue() const
{
	return number;
}

Cell* NumberCell::clone() const
{
	return new NumberCell(*this);

}

NumberCell& NumberCell::operator=(const NumberCell& other)
{
	if (this != &other)
	{
		number = other.number;
	}
	return *this;
}