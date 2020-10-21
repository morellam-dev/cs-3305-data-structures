
# CS 3305 Data Structures

## Homework Assignment 3

M Morella

## implementation of `sequence1.h`

### `sequence1.cpp`

```c++
/**
 * @file    sequence1.cpp
 * @author  M Morella
 * @brief   Implementation for sequence class, for Assignment 3
 *
 * Note: This implementation aggressively asserts the preconditions described
 * in the sequence1.h documentation (i.e. "the current element is existent").
 * Because the test program does not check that the preconditions are met
 * before calling the class's methods, it may crash more often than it
 * otherwise would. This ensures that the methods behave as expected.
 */
#include "sequence1.h"
#include <cassert>

using namespace main_savitch_3;

sequence::sequence() {
    used = 0;
}
void sequence::start() {
    current_index = 0;
}
void sequence::advance() {
    assert (is_item());
    current_index += 1;
}
void sequence::insert(const value_type &entry) {
    assert (size() < CAPACITY);
    if (!is_item()) {
        current_index = 0;
    }
    for (int i = used++; i > current_index; i--) {
        data[i] = data[i - 1];
    }
    data[current_index] = entry;
}
void sequence::attach(const value_type &entry) {
    assert(size() < CAPACITY);
    if (!is_item()) {
        current_index = used;
    } else {
        current_index += 1;
    }
    for (int i = used++; i > current_index; i--) {
        data[i] = data[i - 1];
    }
    data[current_index] = entry;
}
void sequence::remove_current() {
    assert (is_item());
    used -= 1;
    for (int i = current_index; i < used; i++) {
        data[i] = data[i + 1];
    }
}
sequence::size_type sequence::size() const {
    return used;
}
bool sequence::is_item() const {
    return (current_index < used);
}
sequence::value_type sequence::current() const {
    assert (is_item());
    return data[current_index];
}
```

## Output of sequence_test.cpp

Note: this text has been intentionally abridged. The symbol `//` indicates an omitted instance of the command menu prompt.

```text
$ g++ sequence1.cpp sequence_test.cpp && ./a.out
I have initialized an empty sequence of real numbers.
//
Enter choice: A
Please enter a real number for the sequence: 3
3 has been read.
//
Enter choice: I
Please enter a real number for the sequence: 1
1 has been read.
//
Enter choice: A
Please enter a real number for the sequence: 2
2 has been read.
//
Enter choice: P
1 2 3
//
Enter choice: I
Please enter a real number for the sequence: 4
4 has been read.
//
Enter choice: P
1 4 2 3
//
Enter choice: R
The current item has been removed.
//
Enter choice: C
Current item is: 2
//
Enter choice: +
//
Enter choice: C
Current item is: 3
//
Enter choice: A
Please enter a real number for the sequence: 4
4 has been read.
//
Enter choice: A
Please enter a real number for the sequence: 5
5 has been read.
//
Enter choice: P
1 2 3 4 5
//
Enter choice: S
Size is 5.
//
Enter choice: !
//
Enter choice: C
Current item is: 1
//
Enter choice: I
Please enter a real number for the sequence: 0
0 has been read.
//
Enter choice: P
0 1 2 3 4 5
//
Enter choice: Q
Ridicule is the best test of truth.
```

### Actual Screenshot of Execution

![screenshot of last page of test program output](https://i.imgur.com/b89W4oI.png)
