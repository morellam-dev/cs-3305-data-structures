// main.cpp
#include <iostream>
#include <string>

using namespace std;

// Function 1
// Postcondition: Prints the prefix augmented by the section number for each
// section. Levels determines how deep the sections go (i.e. 2 levels
// gives 1.1., 1.2., and so on; 3 levels gives 1.1.1., 1.1.2., and so on.)
void numbers(ostream& outs, const string& prefix, unsigned int levels) {
  if (levels != 0) {
    for (int c = 1; c <= 9; c++) {
      string s = (prefix + to_string(c)) + '.';
      numbers(outs, s, levels - 1);
    }
  } else {
    outs << prefix << '\n';
  }
};

// Function 2
// Precondition:   n is a power of 2 greater than zero.
// Postcondition: A pattern has been printed to the ostream outs. The longest
// line of the pattern has n stars beginning in column i of the output.
void pattern(ostream& outs, unsigned int n, unsigned int i) {
  if (n != 0) {
    pattern(outs, n / 2, i);
    for (int k = 0; k < i; k++) outs << ' ';
    for (int k = 0; k < n; k++) outs << "* ";
    outs << '\n';
    pattern(outs, n / 2, i + n);
  }
};

int main(int argc, char** argv) {
  //   Testing function 1 (Try these)
  cout << "numbers(cout, \"THERBLIG\", 2):\n";
  numbers(cout, "THERBLIG", 2);
  cout << "numbers(cout, \"THERBLIG\", 3):\n";
  numbers(cout, "THERBLIG", 3);
  cout << "numbers(cout, \"THERBLIG\", 4):\n";
  numbers(cout, "THERBLIG", 4);

  // Testing function 2 (Try these)
  cout << "pattern(cout, 8, 0):\n";
  pattern(cout, 8, 0);
  cout << "pattern(cout, 16, 0):\n";
  pattern(cout, 16, 0);
  cout << "pattern(cout, 32, 0):\n";
  pattern(cout, 32, 0);
}
