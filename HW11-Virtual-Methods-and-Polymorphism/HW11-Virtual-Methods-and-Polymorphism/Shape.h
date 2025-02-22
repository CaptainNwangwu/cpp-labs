#ifndef Shape_h
#define Shape_h

#define _USE_MATH_DEFINES
// For M_PI (Constant of PI)

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
#include <fstream>
using std::ofstream;
#include <iomanip>
using std::left;
using std::right;
using std::setw;
#include <cmath>
using std::sqrt;
#include <sstream>
using std::stringstream;
// Class Shape should be placed in Shape.h
class Shape {
public:
    Shape                 ( double x, double y );
    Shape                 (istream& ss);
    virtual ~Shape();
    double getDistanceTo  ( double p_x, double p_y) const;
    double get_ref_x() const;
    double get_ref_y() const;
// Virtual Methods
    virtual void   write(ostream& strm) const ;
    // Pure Virtual Methods
    virtual double area()       const = 0;
    virtual double perimeter()  const = 0;
    virtual bool   contains (double p_x, double p_y) const = 0;
protected:
    double ref_x;
    double ref_y;


};
ostream& operator<<(ostream& strm, const Shape& s);
#endif