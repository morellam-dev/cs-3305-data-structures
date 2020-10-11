// FILE: n_queens_problem.cpp
// A naive, stack-based solution to the N queens problem.
// i.e. find one legal way to place N queens on an NxN chess board.

#define N 9

#include <cmath>
#include <deque>
#include <iostream>
#include <cassert>

using std::deque;
using std::min;
using std::ostream;

struct Point {
  int x;
  int y;
};
ostream& operator<<(ostream &out, Point p) {
  out << '(' << p.x << ", " << p.y << ')';
  return out;
}

template <class C>
void print_for_each(C const &c) {
  bool first = true;
  for (auto const &x : c) {
    if (!first)
      std::cout << ", ";
    first = false;
    std::cout << x;
  }
  std::cout << "\n";
}

bool queen_conflict(const Point &p1, const Point &p2) {
  if (p1.x == p2.x || p1.y == p2.y)  // row/col collision?
    return true;
  if (p1.x - p2.x == p1.y - p2.y)  // diagonal collision?
    return true;
  return false;
}

bool find_queen_conflict(const deque<Point> &queens, const Point &p) {
  for (auto const &p2 : queens) {
    if (queen_conflict(p, p2)) {
      return true;
    }
  }
  return false;
}

int main() {
  std::cout << "Attempting to place " << N << " queens in an " << N << "x" << N << " board...\n";
  deque<Point> queens;
  while (queens.size() < N) {
    Point *current = new Point{(int)queens.size(), 0};
    while (find_queen_conflict(queens, *current)) {
      while (current->y >= N - 1) {
        current = &queens.back();
        queens.pop_back();
        std::cout << "Popped " << *current << "\n";
      }
      current->y += 1;
    }
    std::cout << "Pushed " << *current << "\n";
    queens.push_back(*current);
  }
  std::cout << "Found positions for all " << N << " queens!\n";
  print_for_each(queens);

  for (auto const &p : queens) {
    assert(find_queen_conflict(queens, p));
  }
}