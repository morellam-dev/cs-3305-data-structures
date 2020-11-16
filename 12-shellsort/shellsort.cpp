// FILE:    insert.cpp
// AUTHOR:  M Morella
// An interactive test program for the shellsort function,
// implemented using Donald Shell

#include <algorithm>  // Provides swap
#include <cmath>      // Provides round
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <iostream>   // Provides cout and cin
using namespace std;

// PROTOTYPE: shellsort function
void shellsort(int data[], size_t size);
// Precondition: 'data' is an array with 'size' elements.
// Postcondition: 'data' is sorted in ascending order.

int main() {
  const char BLANK = ' ';
  const size_t ARRAY_SIZE = 30;  // Number of elements in the array to be sorted
  int data[ARRAY_SIZE];          // Array of integers to be sorted
  int user_input;                // Number typed by the user
  size_t number_of_elements;     // How much of the array is used
  size_t i;                      // Array index

  // Provide some instructions.
  cout << "Please type up to " << ARRAY_SIZE << " positive integers. ";
  cout << "Indicate the list's end with a zero." << endl;

  // Read the input numbers.
  number_of_elements = 0;
  cin >> user_input;
  while ((user_input != 0) && (number_of_elements < ARRAY_SIZE)) {
    data[number_of_elements] = user_input;
    number_of_elements++;
    cin >> user_input;
  }

  shellsort(data, number_of_elements);
  cout << "In sorted order, your numbers are: " << endl;
  for (i = 0; i < number_of_elements; i++) cout << data[i] << BLANK << BLANK;
  cout << endl;

  return EXIT_SUCCESS;
}

// IMPLEMENTATION: shellsort
// An optimization of insertionsort, that exchanges elements which are far
// apart.

void shellsort(int data[], size_t size) {
  int ss = size / 2;
  while (ss > 0) {
    for (int offset = 0; offset < ss; offset++) {
      for (int i = ss + offset; i < size; i += ss) {
        int temp = data[i];
        int j = i - ss;
        while (j >= 0 && data[j] > temp) {
          data[j + ss] = data[j];
          j -= ss;
        }
        data[j + ss] = temp;
      }
    }
    ss = std::round(ss / 2.2);
  }
}
