#include "Rectangle.h"


Rectangle::Rectangle(double x, double y, double w, double h) : Shape{x, y}, width{w}, height{h} {
  cout << "DEBUG: Executing Rectangle constructor...\n";
}

Rectangle::Rectangle(istream& strm) : Shape::Shape{strm} {
  strm >> width >> height;
}

double Rectangle::area() const {
  return width * height;
}

double Rectangle::perimeter() const {
  return 2 * (height + width);
}

Rectangle::~Rectangle() {
  cout << "DEBUG: Object Type [Rectangle] has been destroyed.\n";
}


double Rectangle::getW() const {
  return width;
}

double Rectangle::getH() const {
  return height;
}

void Rectangle::write(ostream& strm) const {
  strm <<'(' << Shape::ref_x << ", " << Shape::ref_y << ")" << 
    "  width:  " << getW() <<  "  height:  " << getH();
}
ostream& operator<<(ostream& strm, const Rectangle& r) {
  r.write(strm);
  return strm;
}