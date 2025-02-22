#ifndef Circle_H
#define Circle_H
#include <iostream>
using std::cout;
#include <fstream>
using std::ostream;

#include "Shape.h"

// Class Circle should be placed in Circle.h
class Circle : public Shape {
public:
    Circle  ( double x, double y, double r );
    Circle  (istream& strm);
    ~Circle();
  double  get_data ()  const;

// Virtual Methods
    virtual void    write   ( ostream& strm ) const;
    virtual double area() const;
    virtual double perimeter() const;
    virtual bool contains (double p_x, double p_y) const;
private:
    double radius;
};
     ostream& operator<<(ostream& strm, const Circle& c);

#endif