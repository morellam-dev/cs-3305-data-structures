# CS 3305 Data Structures

M Morella

## Homework Assignment 11

### Part 1 - Implement using Double Hashing

The vast majority of the code is identical; the changes made are explained below.

The `hash` function was renamed to `hash1`.

```cpp
template <class RecordType>
inline size_t Table<RecordType>::hash1(int key) const {
  return (key % CAPACITY);
}
```

Added a new function, `hash2`.

```cpp
template <class RecordType>
inline size_t Table<RecordType>::hash2(int key) const {
  return (key % (CAPACITY - 2)) + 1;
}
```

Modified `next_index` to employ double-hashing:

```cpp
template <class RecordType>
inline size_t Table<RecordType>::next_index(size_t index, int key) const
// Library facilities used: cstdlib
{
  return (index + hash2(key)) % CAPACITY;
}
```

The `find_index` and `insert` functions were changed to call `next_index` with the new key parameter.

```cpp
template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry) {
// ...
    while (!is_vacant(index)) index = next_index(index, entry.key);
// ...
}
```

```cpp
template <class RecordType>
void Table<RecordType>::find_index(int key, bool& found, size_t& i) const {
// ...
    i = next_index(i, key);
// ...
}
```

#### Part 2 - Implement using Quadratic Probing

Modified `next_index` to use a `count` parameter:

```cpp
template <class RecordType>
inline size_t Table<RecordType>::next_index(size_t index, int count) const
// Library facilities used: cstdlib
{
  return (index + count + 1) % CAPACITY;
}
```

Modified `find_index` to include the count parameter.

```cpp
template <class RecordType>
void Table<RecordType>::find_index(int key, bool& found, size_t& i) const {
// ...
    i = next_index(i, count);
// ...
}
```

Modified `insert` to add an incrementing count parameter:

```cpp
template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry) {
// ...
    while (!is_vacant(index)) {
      index = next_index(index, ++count);
    }
// ...
}
```

### Sample Output

Both implementations execute as expected with no anomalous behavior.

```text
$ make && echo && ./main.out
g++ -Wall -std=c++17 -o main.out *.cpp

I have initialized an empty Table. Each record in the Table
has an integer key and a real number as data.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
Enter choice: I
Please enter a real number for a record's data: 812
812 has been read.
Please enter a non-negative integer for a key: 812
812 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
Enter choice: I
Please enter a real number for a record's data: 1
1 has been read.
Please enter a non-negative integer for a key: 1
1 has been read.
The record has been inserted.

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
Enter choice: F
Please enter a non-negative integer for a key: 1
1 has been read.
The key's data is: 1

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
Enter choice: F
Please enter a non-negative integer for a key: 812
812 has been read.
The key's data is: 812

The following choices are available:
 S   Print the result from the size( ) function
 I   Insert a new record with the insert(...) function
 R   Remove a record with the remove(...) function
 ?   Check whether a particular key is present
 F   Find the data associated with a specified key
 Q   Quit this test program
Enter choice:
```