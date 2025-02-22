#ifndef Tests_H
#define Tests_H

#include <iostream>
using std::endl;
using std::cin;

#include <string>
using std::string;
using std::stod;

#include <fstream>
using std::ifstream;

#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Point2D.h"
#include "Polygon.h"
#include "ShapeList.h"


void test1() {
cout << "\nBeginning Test 1..." << endl;
  
Circle c1{0, 0, 1};
Square s1{1, 0.5, 2.3};
cout << "c1: " << c1 << endl;
cout << "s1: " << s1 << endl;

cout << "\nConcluding Test 1..." << endl;
}





void test2() {
  cout << "\nBeginning Test 2..." << endl;
  cout << "Press <enter> to continue...";
  cin.get( );  // waits on another <enter> key
  ShapeList shapes;
  shapes.add( new Circle{1, 2.3, 3} );
  shapes.add( new Square{5, 5, 10.2} );
  cout << "List via stream insertion operator:\n";
  cout << shapes << endl;
  cout << "\nList via write method:\n";
  shapes.write( cout );
  cout << endl;
  
  cout << "\nConcluding Test 2..." << endl;
}




/**/
void test3 () {
  cout << "\nBeginning Test 3..." << endl;

  cout << "Press <enter> to continue...";
cin.get( );  // waits on another <enter> key

ifstream fin( "oop9in.txt" );
if ( !fin ) {
    cout << "Input file could not be opened!  Exiting!\n";
    exit( 1 );
}

ShapeList shapes2;
while ( fin.good( ) ) {
    string object_type;
    fin >> object_type;
    if ( object_type == "Square" ) {
      string x, y, s;
      fin >> x >> y >> s;
      shapes2.add( new Square{ stod(x), stod(y), stod(s) } ); 
    } else if ( object_type == "Circle" ) {
      string x,y,r;
      fin >> x >> y >> r;
      shapes2.add( new Circle{ stod(x), stod(y), stod(r)}  );
    } /* else if ( object_type == "Rectangle" ) {
      string x,y,w,h;
      fin >> x >> y >> w >> h;
      shapes2.add( new Rectangle{ stod(x), stod(y), stod(w), stod(h) } );
    } else if ( object_type == "Triangle" ) {
      string x,y,b,h;
      fin >> x >> y >> b >> h;
      shapes2.add( new Triangle{ stod(x), stod(y), stod(b), stod(h) } );
      } */ else if ( object_type == "Polygon" ) {    // Polygon Objects
      string polystring;
      getline(fin, polystring);
      std::istringstream polyStream{polystring};
      int size = 0;
      double refx, refy; 
      Point2D vert_arr[20];

      while (!(polyStream.eof())) {
        polyStream >> refx >> refy;
            //cout << "Vertex Data Inputted...\n";
         Point2D Vertex{refx, refy};
            //cout << "Creating Vertex...\n";
        vert_arr[size] = Vertex;
        cout << "Vertex " << size + 1 << " = " << Vertex << endl;
        ++size;
    }
  
      shapes2.add(new Polygon(vert_arr, size));
    }
    else {
        cout << "Unexpected object type: " << object_type << endl;
        exit( 2 );
    }
}

cout << "Object locations:\n" << shapes2 << endl;

cout << "\nConcluding Test 3..." << endl;



  cout << "\nBeginning Test 4..." << endl;
cout << "test \"closest\" methods...\n";
double x;
double y;
cout << "Enter coordinates for search of closest object reference: ";
cin  >> x >> y;
Shape* closestObj = shapes2.findClosestTo( x, y );
if ( closestObj != nullptr )
    cout << "The object closest to the point provided is located at "
         << *closestObj << endl;
else
    cout << "No objects were entered!\n";
  
cout << "\nConcluding Test 4..." << endl;

cout << "\nBeginning Test 5..." << endl;
// shapes2.erase();
cout << "\nConcluding Test 5..." << endl;


cout << "Beginning Test 6 [Virtual Functions (Area & Perimeter)]..." << endl;
  cout << "\nOutputting each shape's area..." << endl;
  shapes2.area_print();
  cout << "\n\nOutputting each shape's perimeter..." << endl;
  shapes2.perimeter_print();
  cout << "\nConcluding Test 6" << endl;


  

  cout << "\nBeginning Test 7 [Contain Function]" << endl;
  
  cout << "Enter the coordinates of a point to check "
     << "for being inside of objects\n";

double p_x, p_y;
cin >> p_x >> p_y;

cout << "\nThe following shapes contain the point "
     << "(" << p_x << ", " << p_y << "):\n";
shapes2.print_shapes_containing( p_x, p_y );

  cout <<"\n\nAll Tests Completed Sucessfully!" << endl;
}



#endif