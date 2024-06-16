#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    virtual Cell* clone() const = 0 ;
    virtual ~Cell();
    virtual std::string getValue() const = 0;

};


#endif
