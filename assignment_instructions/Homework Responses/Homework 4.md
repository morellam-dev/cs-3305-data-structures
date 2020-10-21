# CS 3305 Data Structures

## Homework Assignment 4

M Morella

## `poly0.h`

```cpp
// FILE:    poly0.h
// AUTHOR:  M Morella
// A header for the polynomial class.
// Adds copy constructor, assignment operator, and destructor.
// Uses a dynamic array which is automatically resized.
// Probably not very memory efficient.
#pragma once

#include <iostream>  // Provides ostream
namespace main_savitch_3 {
class polynomial {
 public:
  // The maximum size of a polynomial's internal array.
  static const size_t CAPACITY = 2048;
  // The maximum exponent which can be safely stored.
  static const unsigned int MAX_EX = CAPACITY - 1;
  // Constructs a new polynomial. If specified, the given exponent will have the
  // given exponent.
  // PRECONDITION: exponent <= CAPACITY
  polynomial(double c = 0.0, unsigned int exponent = 0);
  // Constructs a deep copy of another polynomial
  polynomial(const polynomial& p2);

  // MODIFICATION MEMBER FUNCTIONS

  // Adds the given amount to the coefficient of the specified exponent.
  // PRECONDITION: exponent <= CAPACITY
  void add_to_coef(double amount, unsigned int exponent);
  // Sets the coefficient for the specified exponent.
  // PRECONDITION: exponent <= CAPACITY
  void assign_coef(double coefficient, unsigned int exponent);
  // Sets all coefficients of this polynomial to zero.
  void clear();
  // POSTCONDITION: This polynomial is a deep copy of the given polynomial.
  void operator=(const polynomial& p2);
  // frees up allocated memory when this polynomial is deleted
  ~polynomial();

  // CONSTANT MEMBER FUNCTIONS

  // @returns the coefficient of the term with the specified exponent
  double coefficient(unsigned int exponent) const;
  // @returns the largest exponent with a non-zero coefficient, otherwise 0
  inline unsigned int degree() const { return current_degree; }
  // @returns the calculated value of this polynomial with the given value for
  // the variable x.
  double eval(double x) const;
  // @returns the next exponent n which is LARGER than e such that
  // coefficient(n) != 0. If there is no such term, the return value is zero.
  unsigned int next_term(unsigned int e) const;
  // @returns the next exponent n which is SMALLER than e such that
  // coefficient(n) != 0. If there is no such term, the return value is UINT_MAX
  // from <climits>.
  unsigned int previous_term(unsigned int e) const;

  // CONSTANT OPERATORS

  // same as eval(x)
  // @returns the calculated value of this polynomial with the given value for
  // the variable x.
  inline double operator()(double x) const { return eval(x); }

 private:
  double* m_coef;               // a pointer to a dynamic array
  size_t m_capacity;            // the current size of the dynamic array
  unsigned int current_degree;  // the current degree
  // recalculates current_degree
  void compute_degree();
  // resizes the coefficient array to be at least as large as min_size.
  void reallocate(unsigned int min_size);
};

// NON-MEMBER OPERATOR FUNCTIONS

// @returns a polynomial which is the difference between p1 and p2
polynomial operator+(const polynomial& p1, const polynomial& p2);
// @returns a polynomial which is the sum of p1 and p2
polynomial operator-(const polynomial& p1, const polynomial& p2);
// Prints a textual representation of the polynomial
// @returns the given stream
std::ostream& operator<<(std::ostream& out, const polynomial& p);
}  // namespace main_savitch_3
```

## `poly0.cpp`

```cpp
// FILE:    poly0.cpp
// AUTHOR:  M Morella
//
// Implementation of the polynomial class, using an dynamically sized array.
// The array of coefficients is automatically resized, so it can theoretically
// store theoretically arbitrarily large coefficients. In practice, values
// beyond several thousand requires allocating absurd amounts of memory
// (8 bytes per coefficient), so it is limited by the CAPACITY constant in
// the header.
// Storing the largest exponent (x^2047) theoretically allocates 16 KiB of
// memory.
#include "poly0.h"

#include <cassert>   // Provides assert
#include <climits>   // provides UINT_MAX
#include <cmath>     // Provides pow and max
#include <iostream>  // Provides ostream

namespace main_savitch_3 {
// polynomial member method implementations

polynomial::polynomial(double coefficient, unsigned int exponent) {
  assert(exponent <= CAPACITY);
  m_capacity = (exponent / 32 + 1) * 32;
  m_coef = new double[m_capacity];
  current_degree = 0;
  clear();
  assign_coef(coefficient, exponent);
}
polynomial::polynomial(const polynomial& p2) {
  m_capacity = p2.m_capacity;
  m_coef = new double[m_capacity];
  for (unsigned int e = 0; e <= p2.degree(); e++) {
    m_coef[e] = p2.coefficient(e);
  }
  current_degree = p2.current_degree;
}
void polynomial::operator=(const polynomial& p2) {
  if (m_capacity != p2.m_capacity) {
    m_capacity = p2.m_capacity;
    delete[] m_coef;
    m_coef = new double[m_capacity];
  }
  for (unsigned int i = 0; i <= p2.m_capacity; i++) {
    m_coef[i] = p2.m_coef[i];
  }
}
void polynomial::reallocate(unsigned int minimum_size) {
  if (m_capacity < minimum_size) {
    int power = (int)std::ceil(std::log2(minimum_size));
    m_capacity = std::pow(2, power);
  }
  double* new_array = new double[m_capacity];
  for (unsigned int i = 0; i <= current_degree; i++) {
    new_array[i] = m_coef[i];
  }
  delete[] m_coef;
  m_coef = new_array;
}
polynomial::~polynomial() { delete m_coef; }
double polynomial::coefficient(unsigned int exponent) const {
  if (degree() < exponent) {
    return 0;
  }
  return m_coef[exponent];
}
void polynomial::assign_coef(double c, unsigned int exponent) {
  assert(exponent <= MAX_EX);
  if (exponent >= m_capacity) {
    reallocate(exponent + 1);
  }
  m_coef[exponent] = c;
  // determine if this operation raises or lowers the degree
  if (exponent > current_degree && m_coef[exponent] != 0) {
    current_degree = exponent;
  } else if (exponent == current_degree && m_coef[exponent] == 0) {
    unsigned int prev = previous_term(exponent);
    current_degree = (prev < exponent) ? prev : 0;
  }
}
void polynomial::add_to_coef(double amount, unsigned int exponent) {
  assign_coef(coefficient(exponent) + amount, exponent);
}
void polynomial::clear() {
  for (unsigned int i = 0; i < m_capacity; i++) {
    m_coef[i] = 0;
  }
  current_degree = 0;
}
double polynomial::eval(double x) const {
  double result = 0;
  for (unsigned int n = 0; n <= degree(); n++) {
    if (coefficient(n) != 0) {
      result += coefficient(n) * std::pow(x, n);
    }
  }
  return result;
}
unsigned int polynomial::next_term(unsigned int e) const {
  for (unsigned int n = e + 1; n < m_capacity; n++) {
    if (coefficient(n) != 0) {
      return n;
    }
  }
  return 0;
}
unsigned int polynomial::previous_term(unsigned int e) const {
  for (int n = e - 1; n >= 0; --n) {
    if (coefficient(n) != 0) {
      return n;
    }
  }
  return UINT_MAX;
}
void polynomial::compute_degree() {
  // search the coef array for the last non-zero element
  // this is rather wasteful so we avoid calling it when possible
  current_degree = m_capacity - 1;
  while (current_degree > 0 && coefficient(current_degree) == 0) {
    current_degree -= 1;
  }
}
polynomial operator+(const polynomial& p1, const polynomial& p2) {
  polynomial result;
  unsigned int degree = std::max(p1.degree(), p2.degree());
  for (unsigned int i = 0; i <= degree; i++) {
    result.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
  }
  return result;
}
polynomial operator-(const polynomial& p1, const polynomial& p2) {
  polynomial result;
  for (unsigned int i = 0; i <= std::max(p1.degree(), p2.degree()); i++) {
    result.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
  }
  return result;
}
std::ostream& operator<<(std::ostream& out, const polynomial& p) {
  for (int n = (int)p.degree(); n >= 0; n--) {
    if (p.coefficient(n) != 0 || p.degree() == 0) {
      if (n != (int)p.degree()) {
        out << ((p.coefficient(n) >= 0) ? " + " : " - ");
      }
      if (n == 0 || std::abs(p.coefficient(n)) != 1) {
        out << std::abs(p.coefficient(n));
      }
      if (n > 0) {
        out << "x";
      }
      if (n > 1) {
        out << "^" << n;
      }
    }
  }
  return out;
}
}  // namespace main_savitch_3

```

### Output from `polyexam0.cpp`

```text
$ g++ poly0.cpp polyexam0.cpp -o exam && ./exam
Running tests for polynomial class

START OF TEST 1:
Testing basic functions (25 points).
I will now test the default constructor. After initializing
with the default constructor, a the coefficient member
function should always return zero (even beyond MAX_EX).
Test passed.

I will now test the constructor with arguments.
Test passed.

I will now test constructor like this: polynomial p(0.0, 3).
After initializing this way, a polynomial
should have all zero coefficients (even beyond MAX_EX).
Test passed.

I will now test assign_coef.
Test passed.

I will now test add_to_coef.
Test passed.

Checking that add_to_coef correctly adjusts degree downward.
Test passed.

Checking that assign_coef correctly adjusts degree downward.
Test passed.

I will now test the clear function.
Test passed.

Inserting 2048 random coefficients
   and then checking the basic functions.
Test passed.

Test 1 got 25 points out of a possible 25.
END OF TEST 1.


START OF TEST 3:
Testing eval and operator ( ) (5 points).
Testing eval and operator ( ).
Test 3 got 5 points out of a possible 5.
END OF TEST 3.


START OF TEST 4:
Testing next_term and previous_term function (5 points).
Testing next_term function.
Next Term Function is okay.
Testing previous_term function.
First for
0 term skipped
Second for
run off bottom
Testing previous_term(0)
Test 4 got 5 points out of a possible 5.
END OF TEST 4.


START OF TEST 5:
Testing operator + (5 points).
Testing operator +
Test passed.

Test 5 got 5 points out of a possible 5.
END OF TEST 5.


START OF TEST 6:
Testing operator - (5 points).
Testing operator -
Test passed.

Test 6 got 5 points out of a possible 5.
END OF TEST 6.


START OF TEST 8:
Testing operator << (5 points).
Printing a polynomial for visual inspection by the TA:
5.5x^5 + 3.3x^3 - 2.2x^2 + 1.1x + 10
Test 8 got 5 points out of a possible 5.
END OF TEST 8.

If you submit this to HAL now, you will have
50 points out of the 50 points from this test program.
```
