#include "Point2D.h"


/**
 * Overloaded stream insertion operator to allow a Point2D to
 * be displayed in a standard ostream.
 * @param strm      the stream to write the Point2D into
 * @param point     the Point2D object to output
 * @return          the modified `strm` is returned
 */
ostream& operator<<( ostream& strm, const Point2D& point ) {
    return strm << "(" << point.x << ", " << point.y << ")";
  }