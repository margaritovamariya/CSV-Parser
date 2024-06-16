#include "TextCell.h"
#include <iostream>

TextCell::TextCell(std::string text)
{
	this->text = text;
}

std::string TextCell::getValue() const
{
	return text;
}

Cell* TextCell::clone() const
{
	return new TextCell(*this);
}

TextCell& TextCell::operator=(const TextCell& other)
{
	if (this != &other)
	{
		text = other.text;
	}
	return *this;
}