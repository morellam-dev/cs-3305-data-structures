# CS 3305 Data Structures

## Homework Assignment 8

M Morella

### Screenshot

![Screenshot of `numbers(cout, "THERBLIG", 4);`](https://i.imgur.com/MH3N1MT.png)

![Screenshot of `pattern(cout, 8, 0);`](https://i.imgur.com/CJcdVDt.png)

### Code

#### **main.cpp**

```cpp
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

```

### Test Outputs

Output of `numbers(cout, "THERBLIG", 2);`

```text
THERBLIG1.1.
THERBLIG1.2.
THERBLIG1.3.
THERBLIG1.4.
THERBLIG1.5.
// ...
THERBLIG9.5.
THERBLIG9.6.
THERBLIG9.7.
THERBLIG9.8.
THERBLIG9.9.
```

Output of `numbers(cout, \"THERBLIG\", 3);`

```text
THERBLIG1.1.1.
THERBLIG1.1.2.
THERBLIG1.1.3.
THERBLIG1.1.4.
// ...
THERBLIG9.9.6.
THERBLIG9.9.7.
THERBLIG9.9.8.
THERBLIG9.9.9.
```

Output of `numbers(cout, \"THERBLIG\", 4);`

```text
THERBLIG1.1.1.1.
THERBLIG1.1.1.2.
THERBLIG1.1.1.3.
THERBLIG1.1.1.4.
THERBLIG1.1.1.5.
THERBLIG1.1.1.6.
// ...
THERBLIG9.9.9.5.
THERBLIG9.9.9.6.
THERBLIG9.9.9.7.
THERBLIG9.9.9.8.
THERBLIG9.9.9.9.
```

Output of `pattern(cout, 8, 0);`

```text
*
* *
  *
* * * *
    *
    * *
      *
* * * * * * * *
        *
        * *
          *
        * * * *
            *
            * *
              *
```

Output of `pattern(cout, 16, 0);`

```text
*
* *
  *
* * * *
    *
    * *
      *
* * * * * * * *
        *
        * *
          *
        * * * *
            *
            * *
              *
* * * * * * * * * * * * * * * *
                *
                * *
                  *
                * * * *
                    *
                    * *
                      *
                * * * * * * * *
                        *
                        * *
                          *
                        * * * *
                            *
                            * *
                              *
```

Output of `pattern(cout, 32, 0);`

```text
*
* *
  *
* * * *
    *
    * *
      *
* * * * * * * *
        *
        * *
          *
        * * * *
            *
            * *
              *
* * * * * * * * * * * * * * * *
                *
                * *
                  *
                * * * *
                    *
                    * *
                      *
                * * * * * * * *
                        *
                        * *
                          *
                        * * * *
                            *
                            * *
                              *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                                *
                                * *
                                  *
                                * * * *
                                    *
                                    * *
                                      *
                                * * * * * * * *
                                        *
                                        * *
                                          *
                                        * * * *
                                            *
                                            * *
                                              *
                                * * * * * * * * * * * * * * * *
                                                *
                                                * *
                                                  *
                                                * * * *
                                                    *
                                                    * *
                                                      *
                                                * * * * * * * *
                                                        *
                                                        * *
                                                          *
                                                        * * * *
                                                            *
                                                            * *
                                                              *
```