#ifndef TABLE1_H
#define TABLE1_H

// FILE: table1.h (part of the namespace main_savitch_12A)
// TEMPLATE CLASS PROVIDED: Table<RecordType> (a Table of records with keys).
//    This class is a container template class for a Table of records.
//    The template parameter, RecordType, is the data type of the records in the
//    Table. It may be any of the bulit-in C++ types (int, char, etc.), or a
//    class with a default constructor, an assignment operator, and an integer
//    member variable called key.
//
// MEMBER CONSTANT for the Table<RecordType> class:
//   static const size_type CAPACITY = ________
//     Table<RecordType>::CAPACITY is the maximum number of records held by a
//     Table.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the Table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the Table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the Table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//    size_type size( ) const
//      Postcondition: Return value is the total number of records in the
//      Table.
//
//  VALUE SEMANTICS for the Table<RecordType> template class:
//    Assignments and the copy constructor may be used with Table objects.

#include <cstdlib>  // Provides size_t

namespace main_savitch_12A {
template <class RecordType>
class Table {
 public:
  // MEMBER CONSTANT -- See Appendix E if this fails to compile.
  static const std::size_t CAPACITY = 811;
  // CONSTRUCTOR
  Table();
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const RecordType& entry);
  void remove(int key);
  // CONSTANT MEMBER FUNCTIONS
  bool is_present(int key) const;
  void find(int key, bool& found, RecordType& result) const;
  std::size_t size() const { return used; }

 private:
  // MEMBER CONSTANTS -- These are used in the key field of special records.
  static const int NEVER_USED = -1;
  static const int PREVIOUSLY_USED = -2;
  // MEMBER VARIABLES
  RecordType data[CAPACITY];
  std::size_t used;
  // HELPER FUNCTIONS
  std::size_t hash(int key) const;
  std::size_t next_index(std::size_t index) const;
  void find_index(int key, bool& found, std::size_t& index) const;
  bool never_used(std::size_t index) const;
  bool is_vacant(std::size_t index) const;
};
}  // namespace main_savitch_12A

#include "table1.template"  // Include the implementation.

#endif  // TABLE1_H
