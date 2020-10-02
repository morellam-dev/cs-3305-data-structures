# CS 3305 Data Structures

## Homework Assignment 6

M Morella

### Screenshot

![Screenshot of main_morella.cpp executing in terminal](https://i.imgur.com/Jdbuo4r.png)

### Code

#### 1. Print a range

Note: implementations exists in the context of otherwise unedited `bag5.h`.

```cpp

// FILE: bag5.h
// ... omitted: surrounding lines of bag5.h

template <class Item>
void bag<Item>::print_value_range(const Item& x, const Item& y) {
  bool found_x = false;
  for (iterator it = begin(); it != end(); it++) {
    if (!found_x && *it == x) {
      found_x = true;
    } else if (*it == y) {
      break; // if x and y are the same, don't break on first instance of y.
    }
    if (found_x) {
      std::cout << *it << ' ';
    }
  }
  if (found_x) {
    std::cout << std::endl;  // only print newline if some output occured.
  }
}

// ... omitted: surrounding lines of bag5.h
```

#### 2. Remove repetitions

```cpp

// FILE: bag5.h
// ... omitted: surrounding lines of bag5.h

template <class Item>
void bag<Item>::remove_repetitions() {
  for (node<Item>* p = head_ptr; p != NULL; p = p->link()) {
    Item p_data = p->data();
    for (node<Item>* j = p; j != NULL; j = j->link()) {
      while (j->link() != NULL && j->link()->data() == p_data) {
        list_remove(j);
      }
    }
  }
}

// ... omitted: surrounding lines of bag5.h
```

#### 3. Main program: `main_morella.cpp`

```cpp
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
```

### Output

```sh
$ make
g++ -Wall -o main_savitch.out main_savitch.cpp
g++ -Wall -o main_morella.out main_morella.cpp

$ ./main_savitch.out

count of goodbye: 3
count of guten morgen: 0
count of 3: 0
goodbye hello goodbye auf wiedersehen goodbye hello
5 1 1 2 3 5 4 5 6 7
5 1 2 3 4 6 7

$ ./main_morella.out
--- jenny.print_value_range(8, -1) ---
8 6 7 5 3 0 9 8 6 7 5 3 0 9

--- jenny.print_value_range(8, 8) ---
8 6 7 5 3 0 9

--- jenny.print_value_range(8, 5) ---
8 6 7

--- jenny.remove_repetitions() ---
removed repetitions ok.

--- jenny.print_value_range(8, -1) ---
8 6 7 5 3 0 9


--- stomping.print_value_range ---

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep.
And miles to go before I sleep.

--- stomping.remove_repetitions() ---
removed repetitions ok.

--- stomping.print_value_range ---

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep.
```
