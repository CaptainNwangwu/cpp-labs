#ifndef ShapeList_h
#define ShapeList_h
#include "Shape.h"
#include <list>
using std::list;

class ShapeList : protected list<Shape*> {
  public:
    ShapeList   ( ) = default;
    ~ShapeList();
    void add    ( Shape* newShape );
    void write  ( ostream& strm_out ) const;
    void area_print() const;
    void perimeter_print() const;
    void erase();
    void print_shapes_containing( double p_x, double p_y ) const;

  friend ostream& operator<<(ostream& strm_out, const ShapeList& shapes ) {
    shapes.write(strm_out);
    return strm_out;
  }
Shape* findClosestTo (double p_x, double p_y) const;
};

#endif