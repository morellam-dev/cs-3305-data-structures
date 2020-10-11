// FILE: n_queens_problem.cpp
// A stack-based solution to the N queens problem.
// i.e. find a legal way to place N queens on an NxN chess board.

#define N 9

#include <cmath>
#include <deque>
#include <iostream>
#include <cassert>

using std::deque;
using std::min;
using std::ostream;

struct point {
  int x;
  int y;
  point(int init_x, int init_y) {
    x = init_x;
    y = init_y;
  }
};
ostream& operator<<(ostream &out, point p) {
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

bool queen_conflict(const point &p1, const point &p2) {
  if (p1.x == p2.x || p1.y == p2.y)  // row/col collision?
    return true;
  if (p1.x - p2.x == p1.y - p2.y)  // diagonal collision?
    return true;
  return false;
}

bool find_queen_conflict(const deque<point> &queenLocations, const point &p) {
  for (std::deque<point>::const_iterator it = queenLocations.begin();
       it != queenLocations.end(); it++) {
    if (queen_conflict(p, *it)) {
      return true;
    }
  }
  return false;
}

int main() {
  std::cout << "Attempting to place " << N << " queens in an " << N << "x" << N << " board...\n";
  deque<point> queens;
  point *current = new point(0, 0);
  int loops = 0;
  while (queens.size() < N) {
    loops++;
    if (!find_queen_conflict(queens, *current)) {
      queens.push_back(*current);
      current = new point(0, queens.size());
    } else {
      while (current->x >= N - 1) {
        current = &queens.back();
        queens.pop_back();
      }
      current->x += 1;
    }
  }
  std::cout << "Found positions for all " << N << " queens!\n";
  print_for_each(queens);

  for (auto const &p : queens) {
    assert(find_queen_conflict(queens, p));
  }
}