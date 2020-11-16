// FILE: merge2.cpp
// AUTHOR: Main, Savitch, Morella
// An interactive test program for the mergesort function
// Reimplemented to reduce re-allocation of dynamic memory.

#include <cstdlib>   // Provides EXIT_SUCCESS, size_t
#include <iostream>  // Provides cout and cin
using namespace std;

// PROTOTYPES of the functions used in this test program:
void mergesort(int data[], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, then new_handler is called.

void merge(int data[], size_t n1, size_t n2, int temp[]);
// Precondition: data is an array (or subarray) with at least n1+n2 elements.
// The first n1 elements (from data[0] to data[n1-1]) are sorted from smallest
// to largest, and the last n2 (from data[n1] to data[n1+n2-1]) are also
// sorted from smallest to largest.
// Postcondition: The first n1+n2 elements of data have been
// rearranged to be sorted from smallest to largest.
void mergesort(int data[], size_t first_index, size_t last_index, int temp[]);
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

  // Provide some instructions
  cout << "Please type up to " << ARRAY_SIZE << " positive integers.";
  cout << "Indicate the list's end with a zero." << endl;

  // Read the input numbers
  number_of_elements = 0;
  cin >> user_input;
  while ((user_input != 0) && (number_of_elements < ARRAY_SIZE)) {
    data[number_of_elements] = user_input;
    number_of_elements++;
    cin >> user_input;
  }

  // Sort the numbers and print the result with two blanks after each number
  mergesort(data, number_of_elements);
  cout << "In sorted order, your numbers are: " << endl;
  for (i = 0; i < number_of_elements; i++) cout << data[i] << BLANK << BLANK;
  cout << endl;

  return EXIT_SUCCESS;
}

void mergesort(int data[], size_t n)
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, thenbad_alloc is thrown.
// Library facilities used: cstdlib
{
  int *temp = new int[n];           // Allocate a dynamic temp array to the heap
  mergesort(data, 0, n - 1, temp);  // Call mergesort with parameters
  delete[] temp;
}

void mergesort(int data[], size_t first, size_t last, int temp[]) {
  size_t n = last - first + 1; // Size of the subarray from data[first] to [last]
  if (n > 1) {
    size_t n1 = (n / 2);  // Size of 1st subarray
    size_t n2 = n - n1;   // Size of 2nd subarray

    // Sort the two subarrays
    mergesort(data, first, first + n1 - 1, temp);
    mergesort(data, first + n1, last, temp);

    // Merge the two sorted halves.
    merge((data + first), n1, n2, (temp + first));
  }
}

void merge(int data[], size_t n1, size_t n2, int temp[]) {
  size_t copied = 0;   // Number of elements copied from data to temp
  size_t copied1 = 0;  // Number copied from the first half of data
  size_t copied2 = 0;  // Number copied from the second half of data
  size_t i;            // Array index to copy from temp back into data

  // Allocate memory for the temporary dynamic array.
  temp = new int[n1 + n2];

  // Merge elements, copying from two halves of data to the temporary array.
  while ((copied1 < n1) && (copied2 < n2)) {
    if (data[copied1] < (data + n1)[copied2])
      temp[copied++] = data[copied1++];  // Copy from first half
    else
      temp[copied++] = (data + n1)[copied2++];  // Copy from second half
  }

  // Copy any remaining entries in the left and right subarrays.
  while (copied1 < n1) temp[copied++] = data[copied1++];
  while (copied2 < n2) temp[copied++] = (data + n1)[copied2++];

  // Copy from temp back to the data array, and release temp's memory.
  for (i = 0; i < n1 + n2; i++) data[i] = temp[i];
}