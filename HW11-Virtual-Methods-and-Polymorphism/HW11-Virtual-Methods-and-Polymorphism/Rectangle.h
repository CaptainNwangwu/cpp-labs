#ifndef Rectangle_H
#define Rectangle_H

#include "Shape.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ostream;

  class Rectangle : public Shape {
public:  
  Rectangle(double x, double y, double w, double h);
  Rectangle(istream& strm);
  ~Rectangle();
  double  getW()  const;
  double  getH()  const;

// Virtual Functions 
  virtual void    write(ostream& strm) const;
  virtual double area() const;
  virtual double perimeter() const;
  // virtual bool   contains (double p_x, double p_y) const {return false;};
private:
  double width;
  double height;
};
ostream& operator<<(ostream& strm, const Rectangle& r);

#endif