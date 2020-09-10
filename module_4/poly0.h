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
  // given coefficient.
  // PRECONDITION: exponent <= CAPACITY
  polynomial(double coefficient = 0.0, unsigned int exponent = 0);
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
