// FILE:    merge.cpp
// AUTHOR:  M Morella
// An interactive test program for the mergesort function

#include <algorithm>  // Provides swap
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <iostream>   // Provides cout and cin
using namespace std;

// PROTOTYPE of mergesort, defined on page 681 of the Main-Savitch book
void mergesort(int data[], size_t n);
// Precondition: data[first_index] through data[last_index] are array
// elements in no particular order. The temp array has locations
// temp[first_index] through temp[last_index].

// Postcondition: The elements data[first_index] through data[last_index]
// have been rearranged so that they are ordered from smallest to largest.
// The array elements temp[first_index] through temp[last_index] have been
// used as temporary storage and now contain a copy of data[first_index]
// through data[last_index].

int main() {
  const char BLANK = ' ';
  const size_t ARRAY_SIZE = 10;  // Number of elements in the array to be sorted
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

  mergesort(data, number_of_elements);
  cout << "In sorted order, your numbers are: " << endl;
  for (i = 0; i < number_of_elements; i++) cout << data[i] << BLANK << BLANK;
  cout << endl;

  return EXIT_SUCCESS;
}

// Precondition: data is an array (or subarray) with at least n1 + n2 elements.
// The first n1 elements (from data[0] to data[n1 - 1]) are sorted from smallest
// to largest, and the last n2 (from data[n1] to data[n1 + n2 - 1]) also are
// sorted from smallest to largest.
// Postcondition: The first n1 + n2 elements of data have been rearranged to be
// sorted from smallest to largest.
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
void merge(int data[], size_t n1, size_t n2) {
  size_t copied = 0;   // Number of elements copied from data to temp
  size_t copied1 = 0;  // Number of elements copied from first half of data
  size_t copied2 = 0;  // Number of elemnets copied from second half of data

  // Allocate a dynamic array which stores the sorted elements.
  int *temp = new int[n1 + n2];
  // Merge elements, copying from two halves of data to the temporary array.
  while ((copied1 < n1) && (copied2 < n2)) {
    if (data[copied1] < (data + n1)[copied2]) {
      temp[copied++] = data[copied1++];  // Copy from first half
    } else {
      temp[copied++] = (data + n1)[copied2++];  // Copy from second half
    }
  }
  // Copy any remaining entries in the left and right subarrays.
  while (copied1 < n1) {
    temp[copied++] = data[copied1++];
  }
  while (copied2 < n2) {
    temp[copied++] = (data + n1)[copied2++];
  }
  // Copy from temp back to the data array, and release temp’s memory.
  for (size_t i = 0; i < n1 + n2; ++i) {
    data[i] = temp[i];
  }
  delete[] temp;
}

void mergesort(int data[], size_t n) {
  size_t n1;  // Size of the 1st subarray
  size_t n2;  // Size of the 2nd subarray
  if (n > 1) {
    // Compute sizes of subarrays
    n1 = n / 2;
    n2 = n - n1;
    mergesort(data, n1);          // Sort from data[0] through data[n1 - 1]
    mergesort((data + n1), n2);   // Sort from data[n1] to the end.
    merge(data, n1, n2);          // Merge the two sorted halves
  }
}
