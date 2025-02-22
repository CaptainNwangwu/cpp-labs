#include "Polygon.h"
#include <cmath>
Polygon::Polygon (const Point2D* vertices, int vertex_count) : Shape {vertices[0].x, vertices[0].y} { // set initial point2Ds as anchor points and sink them into Shape
    cout << "\nDEBUG: Executing Polygon constructor...";
    Polygon::vertex_count = vertex_count;
  Polygon::vertices = new Point2D [vertex_count];
  for (int i = 0; i < vertex_count; ++i) {
    Polygon::vertices[i] = vertices[i];
  }
}

void Polygon::write(std::ostream& strm) const {
      cout << "Number of Vertices:\t" << vertex_count << std::endl;
  for (int curr_V = 0; curr_V < vertex_count; ++curr_V){
  strm << '{' << vertices[curr_V].x << ", " << vertices[curr_V].y << ", " << Polygon::vertex_count << "} " << std::endl;
  }
}

std::ostream& operator<<( std::ostream& strm, const Polygon& p ) {
  p.write(strm);
  return strm;
}

Polygon::~Polygon() {
  cout << "DEBUG: Object Type [Polygon] has been destroyed.\n";
  delete[] vertices;  
}

 double Polygon::area () const {
  double avg_height, curr_area, curr_width, total_area = 0;
   for (int i = 0; i < vertex_count - 2; ++i) {
     curr_width = vertices[i + 1].x - vertices[i].x;
     avg_height = (vertices[i + 1].y + vertices[i].y) / 2;
     curr_area  = curr_width * avg_height;
     total_area += curr_area;
   }
    curr_width = vertices[vertex_count - 1].x - vertices[0].x;
    avg_height = (vertices[vertex_count - 1].y + vertices[0].y) / 2;
    curr_area  = curr_width * avg_height;
    total_area += curr_area;

return std::abs(total_area);
}

double Polygon::perimeter() const {
  double perimeter = 0, curr_distance, netX, netY;
  for (int i = 0; i < vertex_count - 1; ++i) {
    netX = vertices[i + 1].x - vertices[i].x;
    netY = vertices[i + 1].y - vertices[i].y;
    curr_distance = sqrt( (netX * netX) + (netY * netY) );
    perimeter += curr_distance;
  }
    netX = vertices[vertex_count - 1].x - vertices[0].x;
    netY = vertices[vertex_count - 1].y - vertices[0].y;
    curr_distance = sqrt( (netX * netX) + (netY * netY) );
    perimeter += curr_distance;

  return std::abs(perimeter);
}

bool Polygon::lowlevelContains(double p_x, double p_y) const {
  double  x_max = vertices[0].x, 
          y_max = vertices[0].y,
          x_min, y_min;
  // Get y_max and x_max
  for (int i = 0; i < vertex_count; ++i) {
    if (vertices[i].x > x_max) {
      x_max = vertices[i].x;
    }
    if (vertices[i].y > y_max) {
      y_max = vertices[i].y;
    }
  }
  x_min = vertices[0].x;
  y_min = vertices[0].y;
  for (int i = 0; i < vertex_count; ++i) {
    if (vertices[i].x < x_min) {
      x_min = vertices[i].x;
    }
    if (vertices[i].y < y_min) {
      y_min = vertices[i].y;
    }
  }
  if (p_x > x_max || p_x < x_min || p_y > y_max || p_y < y_min) {
      cout << "Min: " << x_min << ", " << y_min << "  " << x_max << ", " << y_max << endl;
    return false;
  } 
return true;
}

bool Polygon::contains(double p_x, double p_y) const {
  bool contains = lowlevelContains(p_x, p_y);
  if (contains == false) {
    return false;
  }
  for (int i = 0, j = vertex_count - 1; i < vertex_count; j = ++i) {
    if ((vertices[i].y > p_y) != (vertices[j].y > p_y) 
      && 
      p_x < (vertices[j].x - vertices[i].x) * (
      p_y - vertices[i].y) / (vertices[j].y - vertices[i].y)
      + vertices[i].x ) 
    {
      contains = !contains;
    }
  }
  return contains;
}