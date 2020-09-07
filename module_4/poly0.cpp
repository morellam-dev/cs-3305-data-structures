#include "poly0.h"

#include <cassert>   // Provides assert
#include <climits>   // provides UINT_MAX
#include <cmath>     // Provides pow
#include <iostream>  // Provides ostream

using namespace main_savitch_3;

polynomial::polynomial(double c, unsigned int exponent, unsigned int max_ex) {
  assert(exponent <= max_ex);
  m_capacity = max_ex + 1;
  m_coef = new double[m_capacity];
  clear();
  assign_coef(c, exponent);
}
polynomial::polynomial(const polynomial& p2) {
  m_capacity = p2.capacity();
  m_coef = new double[m_capacity];
  current_degree = p2.degree();
  for (unsigned int e = 0; e <= p2.degree(); e++) {
    m_coef[e] = p2.coefficient(e);
  }
}
void polynomial::operator=(const polynomial& p2) {
  if (capacity() != p2.capacity()) {
    delete[] m_coef;
    m_capacity = p2.capacity();
    m_coef = new double[m_capacity];
  } else {
    clear();
  }
  for (unsigned int e = 0; e <= p2.degree(); e++) {
    assign_coef(p2.coefficient(e), e);
  }
}
void polynomial::assign_coef(double c, unsigned int exponent) {
  assert(exponent <= max_ex());
  m_coef[exponent] = c;
  // determine if this operation raises or lowers the degree
  if (exponent > current_degree && m_coef[exponent] != 0) {
    current_degree = exponent;
  } else if (exponent == current_degree && m_coef[exponent] == 0) {
    compute_degree();
  }
}
void polynomial::add_to_coef(double amount, unsigned int exponent) {
  assign_coef(coefficient(exponent) + amount, exponent);
}
void polynomial::clear() {
  for (unsigned int i = 0; i <= max_ex(); i++) {
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
  for (int n = 0; n <= degree(); n++) {
    if (coefficient(n) != 0) {
      result += coefficient(n) * std::pow(x, n);
    }
  }
  return result;
}
unsigned int polynomial::next_term(unsigned int e) const {
  for (int n = e + 1; n <= max_ex(); n++) {
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
  // search the coef array for the last non-zero element, and assign to to
  // current_degree this is very wasteful so we avoid calling it when possible
  current_degree = max_ex();
  while (current_degree > 0 && coefficient(current_degree) == 0) {
    current_degree -= 1;
  }
}
polynomial main_savitch_3::operator+(const polynomial& p1,
                                     const polynomial& p2) {
  polynomial result;
  unsigned int degree = std::max(p1.degree(), p2.degree());
  for (unsigned int i = 0; i <= degree; i++) {
    result.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
  }
  return result;
}
polynomial main_savitch_3::operator-(const polynomial& p1,
                                     const polynomial& p2) {
  polynomial result;
  for (unsigned int i = 0; i <= std::max(p1.degree(), p2.degree()); i++) {
    result.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
  }
  return result;
}
std::ostream& main_savitch_3::operator<<(std::ostream& out,
                                         const polynomial& p) {
  for (int n = p.degree(); n >= 0; n--) {
    if (p.coefficient(n) != 0 || p.degree() == 0) {
      if (n != p.degree()) {
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
