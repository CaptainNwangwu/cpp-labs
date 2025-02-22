#include "CampsiteDB.h"

CampsiteDB::CampsiteDB( std::string filename ) {
  _filename = filename;
  if (_open_file() == false) {
    _create_file();
    if (_open_file() == false) {
      throw std::runtime_error("Unable to create the database.");
      }
    }
  }

bool CampsiteDB::_open_file() {
  _file.open(_filename, std::ios::in | std::ios::out | std::ios::binary);
  std::cout << "DEBUG: Attempting to open file :  " << _filename << std::endl;
  _file.seekp(0, std::ios_base::end);
  std::cout << "DEBUG:: Successfully opened file: " << _filename << std::endl;
  if (!(_file.is_open() )) {
    std::cout << "DEBUG: File was unable to be opened." << std::endl;
    return false;
  }
  else {
    return true;
  }
}

void CampsiteDB::_create_file( ) {
  std::cout << "DEBUG: Creating new instance of file " << _filename << std::endl;
  _file.open(_filename, std::ios::out);
  _file.close();
}

  void CampsiteDB::write_next_sequential( const Campsite& site ){
    int curr_index = get_current_index();
    int file_byteSize = get_record_count() * sizeof(CampsiteRecord);
    if (_file.tellp() > file_byteSize) {
      throw std::out_of_range ("Error: Write marker (Put) is beyond the end of file.\n");
    }
    move_to_index(curr_index);
    // cout << "\n\nDEBUG (Sequential_Write): Put marker is currently at " << get_current_index() << "\n";
    CampsiteRecord record = site.get_record(); 
    _file.write(reinterpret_cast<char*>(&record), sizeof(CampsiteRecord));
  }

  /**
  Sequential Read Operation

  Reads from file and instantiates a new record uses the information gathered.
  */

  Campsite CampsiteDB::get_next_sequential() {
    if (_file.tellg() == std::ios::end) {
      throw std::out_of_range ("Error: Read marker (get) is at the end of file. Read will be invalid.\n");
    }
  CampsiteRecord new_record;  
    // cout << "\n\nDEBUG(Sequential Read): Get marker is currently at " << get_current_index() << '\n';
    _file.read(reinterpret_cast<char*>(&new_record), sizeof(CampsiteRecord));
  Campsite new_site(new_record);
  return new_site;
}

int CampsiteDB::get_record_count( ) {
  _file.seekg(0, std::ios::end);
  int file_size = _file.tellg() / sizeof(CampsiteRecord);
  return file_size;
}

int CampsiteDB::get_current_index( bool write ) {
  int index;
  if (!write) {
  int file_pos = _file.tellg();
  index = file_pos / sizeof(CampsiteRecord);
    }
  if (write) {
  int file_pos = _file.tellp();
  index = file_pos / sizeof(CampsiteRecord);
  }
  return index;
}

void CampsiteDB::list_records(std::ostream& strm) {
  _file.clear(); // Clear state flags for fstream;
move_to_index(0);

  while (_file.good()) {
    Campsite currSite = get_next_sequential();
    if (_file.good()) {
      strm << currSite.get_record();
      strm << "\n";
    }
  }
  _file.clear();
  _file.seekg(0, std::ios::beg);
}

Campsite CampsiteDB::get_at_index(int index) {
  if (index > get_record_count() || index < 0) {
    throw std::length_error("Index out of bounds");
  }
  _file.clear();
  move_to_index(index);
  // cout << "\n\nDEBUG: Get marker is currently at " << get_current_index() << "\n";
  return get_next_sequential(); 
}

void CampsiteDB::write_at_index( int index, const Campsite& site ) {
  if (index > get_record_count() || index < 0) {
    throw std::length_error("Index out of bounds");
  }
  move_to_index(index);
  // cout << "\n\nDEBUG: Put marker is currently at " << get_current_index() << "\n";
  write_next_sequential(site);
}

void CampsiteDB::print_record( int index, std::ostream& strm )  {
  if (index > get_record_count() || index < 0) {
    throw std::length_error("Index out of bounds");
  }
  get_at_index(index).write(strm);
}

void CampsiteDB::move_to_index( int index ) {
  if (index > get_record_count() || index < 0) {
    throw std::length_error("Index out of bounds");
  }
  int offset = index * sizeof(CampsiteRecord);
  _file.seekp(offset, std::ios::beg); // Move Put
  _file.seekg(offset, std::ios::beg); // Move Get
}

void CampsiteDB::swap_records( int index_1, int index_2 ) {
  if (index_1 > get_record_count() || index_1 < 0 || index_2 > get_record_count() || index_2 < 0) {
    throw std::length_error("Index out of bounds");
  }
  move_to_index(index_1);
  Campsite record_1 = get_next_sequential();
  move_to_index(index_2);
  Campsite record_2 = get_next_sequential();

  write_at_index(index_1, record_2);
  write_at_index(index_2, record_1);
  
}

vector<Campsite> CampsiteDB::get_range( int first_index, int last_index ) {
  if (first_index > get_record_count() || first_index < 0 || last_index > get_record_count() || last_index < 0) {
    throw std::length_error("Index out of bounds");
  }
  vector<Campsite> sites;
  for (int index = first_index; index < last_index; ++index) {
    sites.push_back(get_at_index(index));
    }
  return sites;
}

Campsite CampsiteDB::get_random() {
  return get_at_index ( std::rand() % get_record_count() );
}