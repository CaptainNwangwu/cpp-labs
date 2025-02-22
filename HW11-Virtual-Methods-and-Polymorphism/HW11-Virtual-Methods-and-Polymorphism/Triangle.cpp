#include "Triangle.h"


Triangle::Triangle(double x, double y, double b, double h) : Shape{x, y}, base{b}, height{h} {
  cout << "DEBUG: Executing Triangle constructor...\n";
}

Triangle::Triangle(istream& strm) : Shape::Shape{strm} {
  strm >> base >> height;
}

Triangle::~Triangle() {
  cout << "DEBUG: Object Type [Triangle] has been destroyed.\n";
}


double Triangle::getB() const {
  return base;
}

double Triangle::getH() const {
  return height;
}

void Triangle::write(ostream& strm) const {
  strm << '(' << Shape::ref_x << ", " << Shape::ref_y << ")" << 
    "  base:  " << getB() << right << "  height:  " << getH();
}

double Triangle::area() const {
  return base * height * 0.5;
}

double Triangle::perimeter() const {
  cout << "\nError: Perimeter of a triangle cannot be determined using only base + height.\n\n";
  return 0.0;
}

ostream& operator<<(ostream& strm, const Triangle& t) {
  t.write(strm);
  return strm;
}