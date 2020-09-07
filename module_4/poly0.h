// FILE: poly0.h
// CLASS PROVIDED:
// 
// The polynomial class has been redesigned with with two extra methods: 
// max_ex() and capacity(). These serve to replace the CAPACITY and MAX_EX
// constants. 
#ifndef POLY0_H
#define POLY0_H
#include <iostream>  // Provides ostream

// If your compiler does not support namespaces, then please delete the
// following line and the set of brackets that follow.
namespace main_savitch_3 {

class polynomial {
 public:
  // The default size of a polynomial's internal array.
  // DEPRECATED. Use capacity() + 1 instead.
  static const unsigned int CAPACITY = 30;
  // The default maximum exponent of a polynomial by default.
  // Deprecated. Use max_ex() instead.
  static const unsigned int MAX_EX = CAPACITY - 1;

  // PRECONDITION: exponent <= max_ex
  // POSTCONDITION: This polynomial has been create with all zero
  // coefficients, except for coefficient c for the specified exponent.
  // When used as a default constructor (using default values for both
  // arguments), the result is a polynomial with all zero coefficients.
  polynomial(double c = 0.0, unsigned int exponent = 0, unsigned int max_ex = MAX_EX);
  // POSTCONDITION: This polynomial has been created as a deep copy of the given
  // polynomial.
  polynomial(const polynomial& p2);

  // MODIFICATION MEMBER FUNCTIONS

  // PRECONDITION: exponent <= MAX_EX.
  // POSTCONDITION: Adds the given amount to the coefficient of the specified
  // exponent.
  void add_to_coef(double amount, unsigned int exponent);
  // PRECONDITION: exponent <= MAX_EX.
  // POSTCONDITION: Sets the coefficient for the specified exponent.
  void assign_coef(double coefficient, unsigned int exponent);
  // POSTCONDITION: All coefficients of this polynomial are set to zero.
  void clear();
  // POSTCONDITION: This polynomial is a deep copy of the given polynomial.
  // If the given polynomial has a different capacity, it will 
  void operator=(const polynomial& p2);
  // POSTCONDITION: the polynomial has been destructed and its allocated memory
  // cleared.
  ~polynomial();

  // CONSTANT MEMBER FUNCTIONS

  // POSTCONDITION: returns the maximum permitted exponent by this polynomial.
  inline
  unsigned int max_ex() const { return m_capacity - 1; }
  // POSTCONDITION: returns the capacity of this polynomial's array.
  inline
  unsigned int capacity() const { return m_capacity; }
  // POSTCONDITION: Returns coefficient at specified exponent of this
  // polynomial. NOTE: for exponents > max_ex(), the return value is always zero.
  double coefficient(unsigned int exponent) const;
  // POSTCONDITION: The function returns the value of the largest exponent
  // with a non-zero coefficient.
  // If all coefficients are zero, then the function returns zero.
  inline
  unsigned int degree() const { return current_degree; }
  // POSTCONDITION: The return value is the value of this polynomial with
  // the given value for the variable x.
  double eval(double x) const;
  // POSTCONDITION: The return value is the next exponent n which is LARGER
  // than e such that coefficient(n) != 0.
  // If there is no such term, then the return value is zero.
  unsigned int next_term(unsigned int e) const;
  // POSTCONDITION: The return value is the next exponent n which is SMALLER
  //  than e such that coefficient(n) != 0.
  // If there is no such term, then the return value is UINT_MAX from <climits>.
  unsigned int previous_term(unsigned int e) const;

  // CONSTANT OPERATORS

  // POSTCONDITION: The return value is the value of this polynomial with
  // the given value for the variable x.
  double operator()(double x) const { return eval(x); }

 private:
  double* m_coef;                 // a pointer to a dynamic array
  unsigned int m_capacity;        // the size of the dynamic array
  unsigned int current_degree;  // the current degree
  void compute_degree();        // calculates the degree and stores it in current_degree.
};

// NON-MEMBER BINARY OPERATORS

// POSTCONDITION: return-value is a polynomial with each coefficient
// equal to the difference of the coefficients of p1 & p2 for any given
// exponent.
polynomial operator+(const polynomial& p1, const polynomial& p2);
// POSTCONDITION: return-value is a polynomial with each coefficient
// equal to the sum of the coefficients of p1 & p2 for any given
// exponent.
polynomial operator-(const polynomial& p1, const polynomial& p2);

// NON-MEMBER OUTPUT FUNCTIONS

// POSTCONDITION: The polynomial has been printed to ostream out, which,
// in turn, has been returned to the calling function.
std::ostream& operator<<(std::ostream& out, const polynomial& p);
}  // namespace main_savitch_3
#endif
