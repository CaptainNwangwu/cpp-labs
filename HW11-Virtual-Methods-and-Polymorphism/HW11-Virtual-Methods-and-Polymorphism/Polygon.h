#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include "Point2D.h"

class Polygon : public Shape {
public:
    Polygon( const Point2D* vertices, int vertex_count );
    ~Polygon( );    
    Polygon( const Polygon& )            = delete; // disallow copies by ctor
    Polygon& operator=( const Polygon& ) = delete; // and/or by assignment
    bool lowlevelContains(double p_x, double p_y) const;
// Virtual Methods
    virtual void   write( ostream& strm ) const;
    virtual double area() const;
    virtual double perimeter () const;
    virtual bool   contains(double p_x, double p_y) const;


private:
    Point2D* vertices     = nullptr;
    int      vertex_count = 0;

};


std::ostream& operator<<( std::ostream& strm, const Polygon& p );
#endif