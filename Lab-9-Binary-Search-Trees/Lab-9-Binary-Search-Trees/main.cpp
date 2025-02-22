/*
CJ Nwangweu
CS 2124 
Professor Gilliand
HW 9 (Binary Search Tree)
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
#include <limits>

#include "CSZNode.h"
#include "BinarySearchTree.h"

CityStateZip read_CityStateZip(std::istream& fin) {
    std::string city, state;
    unsigned int zip = 0;
    getline(fin, city, ',');
    getline(fin, state, ',');
    fin >> zip;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return CityStateZip{ city, state,
        zip }; // creates a temporary CityStateZip object and returns it
}


int main() {

    std::ifstream fin{ "city_list.txt" };
    if (!fin) {
        cout << "Error opening city_list.txt!\n";
        exit(1);
    }
/*
    CSZNode Node1{ read_CityStateZip(fin) };
    CSZNode Node2{ read_CityStateZip(fin) };
    
    cout << "test CSZNodes:\n";
    cout << Node1 << endl 
    << Node2 << '\n' << endl;
*/
    cout << "Press <enter> to continue...\n";
cin.get();
BinarySearchTree city_tree;

fin.clear();   // restore stream state so I/O may proceed
fin.seekg(0);  // seek "get" to file start (byte #0)

while (fin.good()) {
    city_tree.add_iteratively(read_CityStateZip(fin));
  }

cout << "Iterative Tree Listing of Recursive Additions:\n" << endl;
city_tree.write_iteratively(cout);



cout << "Press <enter> to continue...\n";
cin.get();
city_tree.erase_recursively();
cout << "Iterative Tree Listing After Erase:\n";
city_tree.write_iteratively(cout);
cout << "<end of tree output>\n\n";

fin.clear();    // restore stream state so I/O may proceed
fin.seekg(0);   // seek "get" to file start (byte #0)

while (fin.good())
    city_tree.add_recursively(read_CityStateZip(fin));  // recursive add
cout << "\nIterative Listing of Recursive Additions\n";
city_tree.write_iteratively(cout);
fin.close();
}
