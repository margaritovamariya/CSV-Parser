#include "DataCell.h"
#include <iostream>
DataCell::DataCell(std::string data) : data(data)
{
}

std::string DataCell::getValue() const
{
	return data;
}

Cell* DataCell::clone() const
{
	return new DataCell(*this);
}

DataCell& DataCell::operator=(const DataCell& other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}