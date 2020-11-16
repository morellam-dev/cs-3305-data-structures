# CS 3305 Data Structures

M Morella

## Homework Assignment 12

![Screenshot of code executing](https://i.imgur.com/xt0RqAK.png)

### Part 1 - Reimplemented Mergesort

#### `mergesort` wrapper function

```cpp
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
```

#### `mergesort` helper function

```cpp
void mergesort(int data[], size_t first, size_t last, int temp[])
// Precondition: data[first_index] through data[last_index] are array
// elements in no particular order. The temp array has locations
// temp[first_index] through temp[last_index].
// Postcondition: The elements data[first_index] through data[last_index]
// have been rearranged so that they are ordered from smallest to largest.
// The array elements temp[first_index] through temp[last_index] have been
// used as temporary storage and now contain a copy of data[first_index]
// through data[last_index].
{
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
```

#### `merge` function

This function is unchanged from the Main & Savitch implementation in merge.cxx, except the function no longer allocates its own `temp` array, but accepts it as a parameter:

```cpp
void merge(int data[], size_t n1, size_t n2, int temp[]);
```

### Part 2: Shellsort

#### `shellsort` function.

```cpp
void shellsort(int data[], size_t n)
// Precondition: data is an array with at least n elements.
// Postcondition: the elements data[0] thru data[n - 1] are sorted in ascending
// order.
{
  int ss = n / 2;
  while (ss > 0) {
    for (int offset = 0; offset < ss; offset++) {
      for (int i = ss + offset; i < n; i += ss) {
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

```

### Sample Output

merge.cpp and shellsort.cpp execute as expected, without issue.

```text
$ make && ./main.out
g++ -Wall -std=c++17 -o main.out *.cpp
Please type up to 10 positive integers.Indicate the list's end with a zero.
9 8 7 6 5 5 4 3 2 0
In sorted order, your numbers are:
2  3  4  5  5  6  7  8  9
```