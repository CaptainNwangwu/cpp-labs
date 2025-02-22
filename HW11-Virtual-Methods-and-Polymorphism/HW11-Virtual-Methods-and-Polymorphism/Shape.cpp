#include "Shape.h"

Shape::Shape( double x, double y ) : ref_x{x}, ref_y{y} {
    cout << "DEBUG: Executing Shape constructor...\n";
}

Shape::Shape (istream& strm) {
  strm >> ref_x >> ref_y;
}

Shape::~Shape() {
  cout << "DEBUG: Object Type [Shape] has been destroyed.\n\n";
}

void Shape::write(ostream& strm) const {
  strm << '(' << ref_x << ", " << ref_y << ')';
}

double Shape::get_ref_x() const {
  return ref_x;
}

double Shape::get_ref_y() const {
  return ref_y;
}

ostream& operator<<(ostream& strm, const Shape& s) {
  s.write(strm);
  return strm;
}

double Shape::getDistanceTo(double p_x, double p_y) const {
  double netX, netY, distance;
  netX = (p_x - ref_x);
  netY = (p_y - ref_y);
    netX = netX * netX, netY = netY * netY;
  distance = sqrt(netX + netY);
  return distance;
}