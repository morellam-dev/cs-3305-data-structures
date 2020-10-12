/** @file    sequence1.cpp
 * @author  M Morella
 * @brief   Implementation for sequence class, for Assignment 3
 *
 * Note: This implementation aggressively asserts the preconditions described
 * in the sequence1.h documentation (i.e. "the current element is existent").
 * Because the test program does not check that the preconditions are met
 * before calling the class's methods, it may crash more often than it
 * otherwise would. This ensures that the methods behave as expected.
 */
#include "sequence1.h"

#include <cassert>

using namespace main_savitch_3;

sequence::sequence() { used = 0; }
void sequence::start() { current_index = 0; }
void sequence::advance() {
  assert(is_item());
  current_index += 1;
}
void sequence::insert(const value_type &entry) {
  assert(size() < CAPACITY);
  if (!is_item()) {
    current_index = 0;
  }
  for (int i = used++; i > current_index; i--) {
    data[i] = data[i - 1];
  }
  data[current_index] = entry;
}
void sequence::attach(const value_type &entry) {
  assert(size() < CAPACITY);
  if (!is_item()) {
    current_index = used;
  } else {
    current_index += 1;
  }
  for (int i = used++; i > current_index; i--) {
    data[i] = data[i - 1];
  }
  data[current_index] = entry;
}
void sequence::remove_current() {
  assert(is_item());
  used -= 1;
  for (int i = current_index; i < used; i++) {
    data[i] = data[i + 1];
  }
}
sequence::size_type sequence::size() const { return used; }
bool sequence::is_item() const { return (current_index < used); }
sequence::value_type sequence::current() const {
  assert(is_item());
  return data[current_index];
}