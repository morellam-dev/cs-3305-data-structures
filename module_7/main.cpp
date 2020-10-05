#include <cassert>
#include <iostream>

#include "deque.h"

template <class T>

bool test_push_front(deque<T> &d, T entry) {
  int old_size = d.size();
  std::cout << "Pushing '" << entry << "' to front... ";
  d.push_front(entry);
  std::cout << "got " << d << ". ";
  assert(d.front() == entry);        // assert that new element is at front.
  assert(d.size() == old_size + 1);  // assert that size increased by one.
  std::cout << "Pass.\n";
  return true;
}
template <class T>
bool test_push_back(deque<T> &d, T entry) {
  int old_size = d.size();
  std::cout << "Pushing '" << entry << "' to back... ";
  d.push_back(entry);
  std::cout << "got " << d << ". ";
  assert(d.back() == entry);         // assert that new element is at front.
  assert(d.size() == old_size + 1);  // assert that size increased by one.
  std::cout << "Pass.\n";
  return true;
}
template <class T>
bool test_pop_front(deque<T> &d) {
  int old_size = d.size();
  std::cout << "Popping first item (" << d.front() << ")... ";
  d.pop_front();
  std::cout << "got " << d << ". ";
  assert(d.size() == old_size - 1);  // assert that size decreased by one.
  std::cout << "Pass.\n";
  return true;
}
template <class T>
bool test_pop_back(deque<T> &d) {
  int old_size = d.size();
  std::cout << "Popping last item (" << d.back() << ")...  ";
  d.pop_back();
  std::cout << "got " << d << ". ";
  assert(d.size() == old_size - 1);  // assert that size decreased by one.
  std::cout << "Pass.\n";
  return true;
}
template <class T>
void test_equality_comparison(deque<T> &d1, deque<T> &d2) {
  bool result = d1 == d2;
  std::cout << d1 << " and " << d2 << " are "
            << (result ? "equal" : "not equal") << ".\n";
}

int main() {
  std::cout << "Creating a new deque called d1.\n";
  deque<int> d1;
  std::cout << "d1.empty() : " << (d1.empty() ? "true" : "false") << "\n";
  std::cout << "d1 has contents: " << d1 << "\n";
  test_push_front(d1, 3);
  test_push_front(d1, 2);
  test_push_front(d1, 1);
  test_push_back(d1, 4);
  test_push_back(d1, 5);
  test_push_back(d1, 6);
  std::cout << "\n";

  std::cout
      << "Creating d2, via copy constructor of d1 (`deque<int> d2(d1);`)...\n";
  deque<int> d2(d1);
  std::cout << "d2.empty() : " << (d2.empty() ? "true" : "false") << "\n";
  std::cout << "d2 has contents: " << d2 << "\n";
  test_pop_front(d2);
  test_pop_front(d2);
  test_pop_back(d2);
  test_pop_back(d2);
  test_push_back(d2, 0);
  test_push_back(d2, 0);
  test_push_back(d2, 0);
  test_push_back(d2, 0);
  std::cout << "\n";

  std::cout << "Comparing d1 and d2 using != operator...\n";
  assert(!(d1 == d2));
  test_equality_comparison(d1, d2);
  std::cout << "\n";

  std::cout << "Reassigning d2 using = operator (`d2 = d1;`)...\n";
  d2 = d1;
  std::cout << "d2 has contents: " << d2 << "\n";

  std::cout << "Comparing d1 and d2 using == operator...\n";
  assert(d1 == d2);
  test_equality_comparison(d1, d2);
  std::cout << "\n";
}