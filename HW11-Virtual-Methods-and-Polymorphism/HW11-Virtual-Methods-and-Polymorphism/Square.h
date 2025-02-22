#ifndef Square_H
#define Square_H
#include "Shape.h"
#include <iostream>
using std::cout;
#include <fstream>
using std::ostream;

// Class Square should be placed in Square.h
class Square : public Shape {
public:
    Square  ( double x, double y, double s );
    Square (istream& strm);
    ~Square();
  double  get_data   () const;

//Virtual Functions
    virtual void   write   (ostream& strm) const;
    virtual double area() const;
    virtual double perimeter() const;
    virtual bool   contains(double p_x, double p_y) const;
    

private:
    double side;
};

ostream& operator<<(ostream& strm, const Square& s);
#endif