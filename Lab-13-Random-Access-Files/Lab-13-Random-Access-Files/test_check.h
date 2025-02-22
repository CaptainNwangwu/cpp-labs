#include <iostream>
using std::cout;
#include "CampsiteRecord.h"
#include "Campsite.h"
#include "CampsiteDB.h"


void record_ctor_Test() {
// Test default c-tor
CampsiteRecord site_rec1;   
cout << "Empty record: " << site_rec1 << "\n";

// Non-default c-tor
CampsiteRecord site_rec2{42, "Lakefront Cabin", true, 300.00};
cout << "Non-empty record: " << site_rec2 << "\n";
}





void DB_ios_Test() {
  CampsiteDB db{"campsites.db"};
// Read a record from a file
std::ifstream fin{"sites.txt"};
fin.close();

Campsite site1 {3, "Riverfront Condo", true, 450.00};
cout << site1 << '\n';

fin.open("sites.txt");
while(fin.good()) {
    Campsite site;
    if(site.from_ascii_file(fin)){
        cout << "Adding " << site << "\n";
        db.write_next_sequential(site);
    }
}
cout << "\n\n";
fin.close(); 
  
db.list_records();
cout << "\n";

cout << "TESTING GET AND WRITE @ Index Methods\n\n";
db.write_at_index(2, Campsite{18, "Pavillion", true, 200.00});
db.write_at_index(3, Campsite{12, "Treehouse", false, 250.00});

db.list_records(cout);
cout << "\n\n";

Campsite result = db.get_at_index(2); // should be "Pavillion"
cout << result << "\n";
result = db.get_at_index(3); // should be "Treehouse"
cout << result << "\n";
  
}









void old_main() {
  // Seeding Random
  srand(time(0));
// Test default c-tor
CampsiteRecord site_rec1;   
cout << "Empty record: " << site_rec1 << "\n";

// Non-default c-tor
CampsiteRecord site_rec2{42, "Lakefront Cabin", true, 300.00};
cout << "Non-empty record: " << site_rec2 << "\n";

// Read a record from a file
std::ifstream fin{"sites.txt"};
from_ascii_file(fin, site_rec1);
fin.close();
cout << "First site from file: " << site_rec1 << "\n";

  Campsite site1 {3, "Riverfront Condo", true, 450.00};
cout << site1 << '\n';

  CampsiteDB db {"campsites.db"};


cout << "File currently contains " << db.get_record_count() << " records.\n\n";

fin.open("sites.txt");
while(fin.good()) {
    Campsite site;
    if(site.from_ascii_file(fin)){
        cout << "Adding " << site << "\n";
        db.write_next_sequential(site);
    }
}
cout << "\n\n";
fin.close();    

cout << "Read index is "  << db.get_current_index() << "\n";
cout << "Write index is " << db.get_current_index(true) << "\n";
cout << "File now contains " << db.get_record_count() << " records.\n\n";

db.list_records();
cout << "\n";

  // Now query a few directly:
Campsite result;
result = db.get_at_index(9); // should be "cabin, riverfront"
cout << result << "\n";
result = db.get_at_index(3); // should be "RV site, covered table"
cout << result << "\n";
result = db.get_at_index(6); // should be "tent site, large, riverfront"
cout << result << "\n\n";


cout << "Write_at_index & Get_at_index test\n" << endl;
// Write different records in two places:
db.write_at_index(8, Campsite{18, "Pavillion", true, 200.00});
db.write_at_index(2, Campsite{12, "Treehouse", false, 250.00});

// See if it worked:
result = db.get_at_index(8); // should be "Pavillion"
cout << result << "\n";
result = db.get_at_index(2); // should be "Treehouse"
cout << result << "\n";


// Print Record At index
db.print_record(8);

// Swap Records
db.swap_records(2, 8);
cout << "\n Records at index 8 and 2 have been swapped. \n" << endl;
db.print_record(8);
  cout << '\n';
db.print_record(2);
  cout << "\n\n";
// Get Range 

for (const auto& site: db.get_range(0,5)) {
  site.write(cout);
  cout << '\n';
  }



cout << "\n\n\nReturning random values (3):\n";
  for (int count = 0; count < 3; ++count) {
    db.get_random().write(cout);
    cout << '\n';
  }
}
