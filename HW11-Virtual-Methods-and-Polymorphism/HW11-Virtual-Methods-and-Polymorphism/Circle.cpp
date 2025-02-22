#include "Circle.h"


Circle::Circle( double x, double y, double r ) : Shape{x, y}, radius{r} {
    cout << "DEBUG: Executing Circle constructor...\n";
}

Circle::Circle(istream& strm) : Shape::Shape{strm} {
  strm >> radius;
}

Circle::~Circle() {
  cout << "DEBUG: Object Type [Circle] has been destroyed.\n";
}


double Circle::get_data() const {
  return radius;
}

void Circle::write(ostream& strm) const {
strm << '(' << Shape::ref_x << ", " << Shape::ref_y << ")" << "\tradius:" << setw(3) << right << get_data();
}

double Circle::area() const {
  return M_PI * (radius * radius);
}

double Circle::perimeter() const {
  return 2 * (M_PI * radius);
}

bool Circle::contains (double p_x, double p_y) const {
  if (this->getDistanceTo(p_x, p_y) < radius) {
    return true;
    }
    else {
      return false;
    }
  }


ostream& operator<<(ostream& strm, const Circle& c) {
  c.write(strm);
  return strm;
}