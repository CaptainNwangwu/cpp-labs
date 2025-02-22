#ifndef CampsiteRecord_h
#define CampsiteRecord_h

#include <cstring>
#include <string.h>
#include <fstream>
#include <iomanip>
/**
 * A fixed-size record representing a campsite in a 
 * recreational area.
 */
struct CampsiteRecord {
    CampsiteRecord();
    CampsiteRecord(int number, const char description[], bool has_electric, double rate);
    static const int desc_size = 128;         /// max storage size of description
    int              number;                  /// site number
    char             description[desc_size];  /// a short description
    bool             has_electric;            /// is power available?
    double           rate;                    /// per-night rate
};


std::istream& from_ascii_file( std::istream& strm, CampsiteRecord& site );
std::ostream& operator<<( std::ostream& strm, const CampsiteRecord& site );
#endif