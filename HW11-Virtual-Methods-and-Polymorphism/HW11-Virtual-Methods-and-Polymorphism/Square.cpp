#include "Square.h"

Square::Square( double x, double y, double s ) : Shape{x, y}, side{s} {
    cout << "DEBUG: Executing Square constructor...\n";
}

Square::Square(istream& strm) : Shape::Shape{strm} {
  strm >> side;
}

Square::~Square() {
  cout << "DEBUG: Object Type [Square] has been destroyed.\n";
}


double Square::get_data() const {
  return side;
}
void Square::write(ostream& strm) const {
  strm << '(' << Shape::ref_x << ", " << Shape::ref_y << ")" <<
    "  side length:  " << get_data();
}

double Square::area() const {
  return side*side;
}

double Square::perimeter() const {
  return 4 * side;
}

bool Square::contains (double p_x, double p_y) const {
  double netX = p_x - this->get_ref_x();
  double netY = p_y - this->get_ref_y();

  if ( (netX > 0 && netX < side) && (netY > 0 && netY < side) ) {
    return true;
    
  }
  else {
    return false;
  }
}

ostream& operator<<(ostream& strm, const Square& s) {
  s.write(strm);
  return strm;
}