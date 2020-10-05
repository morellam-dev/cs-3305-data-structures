// FILE: deque.h
#pragma once

#include <cstdlib>
#include <iostream>

#include "node3.h"

using namespace main_savitch_6B;

template <class T>
class deque {
 public:
  typedef std::size_t size_type;

  // postcondition: empty deque has been created
  deque();

  // postcondition: all resouroces allocated to the deque
  //                have been deallocated
  ~deque();

  // postcondition: newly created deque is a copy of dq
  deque(const deque<T>& dq);

  // postcondition: current deque is a copy of dq
  void operator=(const deque<T>& dq);

  // precondition: deque is not empty
  // postcondition: reference to element at front of deque
  //                            has been returned
  T& front();

  // precondition: deque is not empty
  // postcondition: copy of element at front of deque
  //                            has been returned
  T front() const;

  // precondition: deque is not empty
  // postcondition: reference to element at front of deque has been returned
  T& back();

  // precondition: deque is not empty
  // postcondition: copy of element at back of deque has been returned
  T back() const;

  // precondition: deque is not full
  // postcondition: entry has been inserted at the front of the deque
  void push_front(const T& entry);

  // Precondition: deque is not full
  // Postcondition: entry has been inserted at the back of the deque
  void push_back(const T& entry);

  // Precondition: deque is not empty
  // Postcondition: element at front of deque has been removed
  void pop_front();

  // Precondition: deque is not empty
  // Postcondition: element at back of deque has been removed
  void pop_back();

  // @returns the number of elements in the deque.
  size_type size() const;

  // @returns whether deque is empty
  bool empty() const;

  // @returns whether 2 deques are equal. i.e. they contain the same
  // values in the same order.
  template <class U>
  friend bool operator==(const deque<U>& dq1, const deque<U>& dq2);

  // Postcondition: All elements from the deque have been printed to out.
  template <class U>
  friend std::ostream& operator<<(std::ostream& out, const deque<U>& dq);

 private:
  size_type count;  // Total number of items in the queue
  node<T>* first;
  node<T>* last;
};

#include "deque.template"