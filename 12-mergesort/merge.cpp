// FILE:    merge.cpp
// AUTHOR:  M Morella
// An interactive test program for the mergesort function

#include <algorithm>  // Provides swap
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include <iostream>   // Provides cout and cin
using namespace std;

// PROTOTYPE of mergesort function used in the main method.
// Precondition: data is an array with at least n elements.
// Postcondition: data[0] thru data[n-1] are sorted.
void mergesort(int data[], size_t n);

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

  mergesort(data, number_of_elements);
  cout << "In sorted order, your numbers are: " << endl;
  for (i = 0; i < number_of_elements; i++) cout << data[i] << BLANK << BLANK;
  cout << endl;

  return EXIT_SUCCESS;
}

// PROTOTYPES of helper functions used by mergesort.

void mergesort(int data[], size_t first, size_t last, int temp[]);
void merge(int data[], size_t first, size_t second, size_t last, int temp[]);

// IMPLEMENTATION of mergesort function

void mergesort(int data[], size_t n) {
  int *temp = new int[n];           // Allocate a dynamic temp array to the heap
  mergesort(data, 0, n - 1, temp);  // Call mergesort with parameters
  delete[] temp;
}
// Precondition: data[first_index] through data[last_index] are array
// elements in no particular order. The temp array has locations
// temp[first_index] through temp[last_index].
// Postcondition: The elements data[first_index] through data[last_index]
// have been rearranged so that they are ordered from smallest to largest.
// The array elements temp[first_index] through temp[last_index] have been
// used as temporary storage and now contain a copy of data[first_index]
// through data[last_index].
void mergesort(int data[], size_t first, size_t last, int temp[]) {
  if (first < last) {
    size_t mid;  // The first index of the second subarray.
    mid = first + (last + 1 - first) / 2;
    // Sort from data[first] through data[mid - 1]
    mergesort(data, first, mid - 1, temp);
    // Sort from data[mid] to data[last].
    mergesort(data, mid, last, temp);
    // Merge the sorted arrays.
    merge(data, first, mid, last, temp);
  }
}
// Precondition: The subarrays from data[first] to data[second-1], and from
// data[second] to data[last] are sorted.
// Postcondition: The subarray data[first] thru data[last] is now sorted.
// NOTE: temp[first] through temp[last] have been used as temporary storage and
// now contain a copy of data[first] through data[last].
void merge(int data[], size_t first, size_t second, size_t last, int temp[]) {
  size_t t = first;    // Index into temp array.
  size_t i1 = first;   // Index into first subarray
  size_t i2 = second;  // Index into second subarray

  // Merge the two subarrays
  while ((i1 < second) && (i2 <= last)) {
    if (data[i1] < data[i2]) {
      temp[t++] = data[i1++];  // Copy from first half
    } else {
      temp[t++] = data[i2++];  // Copy from second half
    }
  }
  // Add remaining elements from subarrays.
  while (i1 < second) temp[t++] = data[i1++];
  while (i2 <= last) temp[t++] = data[i2++];
  // Copy from temp back to the data array
  for (size_t i = first; i <= last; ++i) {
    data[i] = temp[i];
  }
}