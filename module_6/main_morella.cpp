// FILE:    main_morella.cpp
// AUTHOR:  M Morella

#include <iostream> // provides cout
#include <string>   // provides string

#include "bag5.h"
#include "node2.h"

using std::string;

int main() {
  bag<int> jenny;
  jenny.insert(9);
  jenny.insert(0);
  jenny.insert(3);
  jenny.insert(5);
  jenny.insert(7);
  jenny.insert(6);
  jenny.insert(8);
  jenny.insert(9);
  jenny.insert(0);
  jenny.insert(3);
  jenny.insert(5);
  jenny.insert(7);
  jenny.insert(6);
  jenny.insert(8);

  std::cout << "--- jenny.print_value_range(8, -1) ---" << std::endl;
  jenny.print_value_range(8, -1);
  std::cout << std::endl;
  std::cout << "--- jenny.print_value_range(8, 8) ---" << std::endl;
  jenny.print_value_range(8, 8);
  std::cout << std::endl;
  // undefined behavior when the same Item is given twice.
  // current implementation begins at first 8, ends on second 8.

  std::cout << "--- jenny.print_value_range(8, 5) ---" << std::endl;
  jenny.print_value_range(8, 5);
  std::cout << std::endl;

  std::cout << "--- jenny.remove_repetitions() ---" << std::endl;
  jenny.remove_repetitions();
  std::cout << "removed repetitions ok." << std::endl;
  std::cout << std::endl;
  std::cout << "--- jenny.print_value_range(8, -1) ---" << std::endl;
  jenny.print_value_range(8, -1);
  std::cout << std::endl;
  std::cout << std::endl;

  bag<string> stomping;
  // Fifth stanza of "Stopping by Woods on a Snowy Evening" by Robert Frost
  stomping.insert("\nAnd miles to go before I sleep.");
  stomping.insert("\nAnd miles to go before I sleep.");
  stomping.insert("\nBut I have promises to keep,");
  stomping.insert("\nThe woods are lovely, dark and deep,");

  std::cout << std::endl;
  std::cout << "--- stomping.print_value_range ---" << std::endl;
  stomping.print_value_range(*stomping.begin(), "");
  std::cout << std::endl;

  std::cout << "--- stomping.remove_repetitions() ---" << std::endl;
  stomping.remove_repetitions();
  std::cout << "removed repetitions ok." << std::endl;
  std::cout << std::endl;

  std::cout << "--- stomping.print_value_range ---" << std::endl;
  stomping.print_value_range(*stomping.begin(), "NULL STRING");
  std::cout << std::endl;

  return 0;
}