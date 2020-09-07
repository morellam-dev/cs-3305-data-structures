// FILE:    poly0.cpp
// AUTHOR:  M Morella
//
// Implementation of the polynomial class, using an dynamically sized array
// The array of coefficients is automatically resized, so it can theoretically
// store theoretically arbitrarily large coefficients. In practice, values
// beyond several million requires allocating absurd amounts of memory, so this
// is not recommended.
#include "poly0.h"

#include <cassert>   // Provides assert
#include <climits>   // provides UINT_MAX
#include <cmath>     // Provides pow and max
#include <iostream>  // Provides ostream

namespace main_savitch_3 {
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
polynomial::~polynomial() { delete m_coef; }
double polynomial::coefficient(unsigned int exponent) const {
  if (degree() < exponent) {
    return 0;
  }
  return m_coef[exponent];
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
