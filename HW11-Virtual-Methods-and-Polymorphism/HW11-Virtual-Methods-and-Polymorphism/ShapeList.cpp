#include "ShapeList.h"

void ShapeList::add(Shape *newShape) {
  this->push_back(newShape);
}

void ShapeList::erase() {
  cout << "\nDEBUG: Executing erase. Emptying all shape objects in ShapeList...\n";
  for (const auto& shapeItem: *this) {
    delete shapeItem;
  }
}

void ShapeList::write(ostream& strm_out ) const {
  for ( const auto& item : *this) {
    item->write ( strm_out );
    strm_out << '\n';
  }
}

Shape* ShapeList::findClosestTo (double p_x, double p_y) const {
  Shape* min; 
  double currDistance;
  min = this->front();
  currDistance = this->front()->getDistanceTo(p_x, p_y);
  for ( const auto& item: *this) {
    if ( item->getDistanceTo(p_x, p_y) < currDistance) {
      min = item;
      currDistance = item->getDistanceTo(p_x, p_y);
    }
  }
  return min;
}

void ShapeList::area_print() const {
  for (const auto& shape: *this) {
    cout << "Area:  " << shape->area() << '\n';
  }
}

void ShapeList::perimeter_print() const {
  for (const auto& shape: *this) {
    cout << "Perimeter:  " << shape->perimeter() << '\n';
  }
}

void ShapeList::print_shapes_containing( double p_x, double p_y ) const {
    for ( const auto& shape : *this ) {       // for each `Shape*` in the list,
        if ( shape->contains( p_x, p_y ) ) {  // if (p_x, p_y) is contained within the
            shape->write( cout );             // Shape, write it to `cout`,
            cout << "\n";                     // one listing per line.
        }
    }
}

ShapeList::~ShapeList(){
this->erase();
  cout << "Executing ShapeList Destructor" << endl;
}