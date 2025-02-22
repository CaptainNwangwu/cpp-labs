#ifndef Triangle_H
#define Triangle_H
#include "Shape.h"
#include <iostream>
using std::cout;
#include <fstream>
using std::ostream;

class Triangle : public Shape {
public:
    Triangle ( double x, double y, double b, double h );
    Triangle(istream& ss);
    ~Triangle();
    double  getB    () const;
    double  getH    () const;
// Virtual Functions
    virtual void    write   (ostream& strm) const;
    virtual double area() const;
    virtual  double perimeter() const;
    // virtual bool   contains (double p_x, double p_y) const {return false;}
private:
    double base;
    double height;
};

ostream& operator<<(ostream& strm, const Triangle& t);
#endif