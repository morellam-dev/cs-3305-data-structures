# CS 3305 Data Structures

## Homework Assignment 7

M Morella

### Screenshot

![Screenshot of main.cpp executing in terminal](https://i.imgur.com/IciqxCz.png)

### Code

#### **deque.template**

```cpp
// FILE: deque.template
// Implementation for deque.h header

template <class T>
deque<T>::deque() {
  first = NULL;
  last = NULL;
  count = 0;
}

template <class T>
deque<T>::~deque() {
  list_clear(first);
}

template <class T>
deque<T>::deque(const deque<T>& dq) {
  node<T>* source_ptr = dq.first;
  count = list_length(source_ptr);
  list_copy(source_ptr, first, last);
}

template <class T>
deque<T>& deque<T>::operator=(const deque<T>& dq) {
  list_clear(first);
  node<T>* source_ptr = dq.first;
  count = list_length(source_ptr);
  list_copy(source_ptr, first, last);
  return *this;
}

template <class T>
T& deque<T>::front() {
  return first->data();
}

template <class T>
T deque<T>::front() const {
  return first->data();
}

template <class T>
T& deque<T>::back() {
  return last->data();
}

template <class T>
T deque<T>::back() const {
  return last->data();
}

template <class T>
void deque<T>::push_front(const T& entry) {
  list_head_insert(first, entry);
  if (last == NULL) {
    last = first;
  }
  count++;
}

template <class T>
void deque<T>::push_back(const T& entry) {
  list_tail_insert(last, entry);
  if (first == NULL) {
    first = last;
  }
  count++;
}

template <class T>
void deque<T>::pop_front() {
  list_head_remove(first);
  count--;
}

template <class T>
void deque<T>::pop_back() {
  list_tail_remove(last);
  count--;
}

template <class T>
typename deque<T>::size_type deque<T>::size() const {
  return count;
}

template <class T>
bool deque<T>::empty() const {
  return count == 0;
}

template <class U>
bool operator==(const deque<U>& dq1, const deque<U>& dq2) {
  const_node_iterator<U> it1(dq1.first);
  const_node_iterator<U> it2(dq2.first);
  const_node_iterator<U> end;
  while (it1 != end || it2 != end) {
    if (*it1 != *it2) {
      return false;
    }
    it1++;
    it2++;
  }
  return true;
}

// For convenience. Simply returns the opposite of operator==.
// Not a friend function, so not declared in header.
template <class U>
bool operator!=(const deque<U>& dq1, const deque<U>& dq2) {
  return !(dq1 == dq2);
}

template <class U>
std::ostream& operator<<(std::ostream& out, const deque<U>& dq) {
  out << "{ ";
  const_node_iterator<U> end;

  for (const_node_iterator<U> it(dq.first); it != end; it++) {
    out << *it << ' ';
  }
  out << '}';
  return out;
}
```

### **main.cpp**

```cpp
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
```

#### **node3.h**

```cpp
// FILE:    node3.h
// AUTHOR:  M Morella
// Based on node2.h, written by M. Main & W. Savitch.
//
// Template class for nodes in *doubly linked* lists.
// Class was renamed to node3.h to signify that this implementation introduces
// the following breaking changes:
//
// * `link()` is deprecated in favor of `next()` and `prev()`
// * `set_link()` is deprecated in favor of `set_next()` and `set_prev()`
// * The constructor `node(entry, link)` is replaced by `node(prev_link, entry,
// next_link)`.
//   * For instantiating an unlinked node, `node()` and `node(entry)` are
//   supported.
//   * Otherwise, all parameters must be explicitly declared: `node(NULL,
//   Item(), NULL)`
//
// Also includes new methods list_tail_insert, list_tail_remove, to simplify
// deque implementation.

#pragma once

#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

namespace main_savitch_6B {
template <class Item>
class node {
 public:
  // TYPEDEF for the node<Item> template class:
  typedef Item value_type;

  // Postcondition: The node is initialized with null references, and the given
  // Item. If no value is given, the default Item constructor is used.
  node(const Item& init_data = Item()) { data_field = init_data; }
  // Postcondition: The node is initialized with the given value, and linked to
  // the given nodes.
  node(node* init_prev, const Item& init_data, node* init_next) {
    prev_field = init_prev;
    data_field = init_data;
    next_field = init_next;
  }
  // @returns a reference the stored Item of this node.
  Item& data() { return data_field; }
  // @returns a node pointer to the next linked node.
  node* link() { return next_field; }
  // @returns a node pointer to the next linked node.
  node* next() { return next_field; }
  // @returns a node pointer to the previously linked node.
  node* prev() { return prev_field; }

  // CONST GETTER METHODS

  // @returns a reference to the stored Item of this node.
  const Item& data() const { return data_field; }
  // @returns a node pointer to the next linked node.
  const node* link() const { return next_field; }
  // @returns a node pointer to the next linked node.
  const node* next() const { return next_field; }
  // @returns a node pointer to the previously linked node.
  const node* prev() const { return prev_field; }

  // MODIFIER METHODS

  // Postcondition: This node now stores the given Item.
  void set_data(const Item& new_data) { data_field = new_data; }
  // Postcondition: The node now links to the specified next node.
  void set_link(node* new_next) { next_field = new_next; }
  // Postcondition: The node now links to the specified next node.
  void set_next(node* new_next) { next_field = new_next; }
  // Postcondition: The node now links to the specified prevous node.
  void set_prev(node* new_prev) { prev_field = new_prev; }

 private:
  Item data_field;   // the stored Item
  node* next_field;  // the next node
  node* prev_field;  // the previous node
};

// FUNCTIONS to manipulate a linked list:

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: All nodes of the list have been returned to the heap,
// and the head_ptr is now NULL.
template <class Item>
void list_clear(node<Item>*& head_ptr);
// Precondition: source_ptr is the head pointer of a linked list.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers for
// a new list that contains the same items as the list pointed to by
// source_ptr. The original list is unaltered.
template <class Item>
void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr,
               node<Item>*& tail_ptr);
// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: A new node containing the given entry has been added at
// the head of the linked list; head_ptr now points to the head of the new,
// longer linked list.
template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry);
// Precondition: tail_ptr is the tail pointer of a linked list.
// Postcondition: A new node containing the given entry has been added at
// the tail of the linked list; tail_ptr now points to the tail of the new,
// longer linked list.
template <class Item>
void list_tail_insert(node<Item>*& tail_ptr, const Item& entry);
// Precondition: head_ptr is the head pointer of a linked list, with at
// least one node.
// Postcondition: The head node has been removed and returned to the heap;
// head_ptr is now the head pointer of the new, shorter linked list.
template <class Item>
void list_head_remove(node<Item>*& head_ptr);
// Precondition: tail_ptr is the tail pointer of a linked list, with at
// least one node.
// Postcondition: The tail node has been removed and returned to the heap;
// tail_ptr is now the tail pointer of the new, shorter linked list.
template <class Item>
void list_tail_remove(node<Item>*& head_ptr);
// Precondition: previous_ptr points to a node in a linked list.
// Postcondition: A new node containing the given entry has been added
// after the node that previous_ptr points to.
template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry);
// Precondition: next_ptr points to a node in a linked list.
// Postcondition: A new node containing the given entry has been added
// before the node that next_ptr points to.
template <class Item>
void list_attach(node<Item>* next_ptr, const Item& entry);
// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The value returned is the number of nodes in the linked
// list.
template <class Item>
std::size_t list_length(const node<Item>* head_ptr);
// Precondition: head_ptr is the head pointer of a linked list, and
// position > 0.
// Postcondition: The return value is a pointer that points to the node at
// the specified position in the list. (The head node is position 1, the
// next node is position 2, and so on). If there is no such position, then
// the null pointer is returned.
template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position);
// Precondition: previous_ptr points to a node in a linked list, and this
// is not the tail node of the list.
// Postcondition: The node after previous_ptr has been removed from the
// linked list.
template <class Item>
void list_remove(node<Item>* previous_ptr);
// Precondition: current_ptr points to a node in a linked list, and this
// is not the head or tail node of the list.
// Postcondition: The given node has been removed from the
// linked list.
template <class Item>
void list_remove_current(node<Item>* current_ptr);
// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The return value is a pointer that points to the first
// node containing the specified target in its data member. If there is no
// such node, the null pointer is returned.
template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target);

// TWO-WAY ITERATORS to step through the nodes of a linked list
// A node_iterator of can change the underlying linked list through the
// * operator, so it may not be used with a const node. The
// node_const_iterator cannot change the underlying linked list
// through the * operator, so it may be used with a const node.

template <class Item>
class node_iterator : public std::iterator<std::forward_iterator_tag, Item> {
 public:
  node_iterator(node<Item>* initial = NULL) { current = initial; }
  Item& operator*() const { return current->data(); }
  // Prefix ++
  node_iterator& operator++() {
    current = current->next();
    return *this;
  }
  // Postfix ++
  node_iterator operator++(int) {
    node_iterator original(current);
    current = current->next();
    return original;
  }
  // Prefix --
  node_iterator& operator--() {
    current = current->prev();
    return *this;
  }
  // Postfix ++
  node_iterator operator--(int) {
    node_iterator original(current);
    current = current->prev();
    return original;
  }
  bool operator==(const node_iterator other) const {
    return current == other.current;
  }
  bool operator!=(const node_iterator other) const {
    return current != other.current;
  }

 private:
  node<Item>* current;
};

template <class Item>
class const_node_iterator
    : public std::iterator<std::forward_iterator_tag, const Item> {
 public:
  const_node_iterator(const node<Item>* initial = NULL) { current = initial; }

  const Item& operator*() const { return current->data(); }

  // Prefix ++
  const_node_iterator& operator++() {
    current = current->next();
    return *this;
  }
  // Postfix ++
  const_node_iterator operator++(int) {
    const_node_iterator original(current);
    current = current->next();
    return original;
  }
  // Prefix --
  const_node_iterator& operator--() {
    current = current->prev();
    return *this;
  }
  // Postfix --
  const_node_iterator operator--(int) {
    const_node_iterator original(current);
    current = current->prev();
    return original;
  }

  bool operator==(const const_node_iterator other) const {
    return current == other.current;
  }
  bool operator!=(const const_node_iterator other) const {
    return current != other.current;
  }

 private:
  const node<Item>* current;
};

}  // namespace main_savitch_6B

#include "node3.template"

```

#### **node3.template**

```cpp
// FILE: node3.template
// AUTHOR:  M Morella
// Based on node2.h, written by M. Main & W. Savitch

// Implementation for doubly-linked node class.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL and size_t

namespace main_savitch_6B {
template <class Item>
void list_clear(node<Item>*& head_ptr) {
  while (head_ptr != NULL) list_head_remove(head_ptr);
}

template <class Item>
void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr,
               node<Item>*& tail_ptr) {
  head_ptr = NULL;
  tail_ptr = NULL;

  // Handle the case of the empty list
  if (source_ptr == NULL) return;

  // Make the head node for the newly created list, and put data in it
  list_head_insert(head_ptr, source_ptr->data());
  tail_ptr = head_ptr;

  // Copy rest of the nodes one at a time, adding at the tail of new list
  source_ptr = source_ptr->next();
  while (source_ptr != NULL) {
    list_insert(tail_ptr, source_ptr->data());
    tail_ptr = tail_ptr->next();
    source_ptr = source_ptr->next();
  }
}

template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry) {
  node<Item>* old_head = head_ptr;
  node<Item>* new_node = new node<Item>(NULL, entry, old_head);
  if (old_head != NULL) {
    old_head->set_prev(new_node);
  }
  head_ptr = new_node;
}

template <class Item>
void list_head_remove(node<Item>*& head_ptr) {
  node<Item>* remove_ptr = head_ptr;
  head_ptr = head_ptr->next();
  if (head_ptr != NULL) {
    head_ptr->set_prev(NULL);
  }
  delete remove_ptr;
}

template <class Item>
void list_tail_insert(node<Item>*& tail_ptr, const Item& entry) {
  node<Item>* new_node = new node<Item>(tail_ptr, entry, NULL);
  if (tail_ptr != NULL) {
    tail_ptr->set_next(new_node);
  }
  tail_ptr = new_node;
}

template <class Item>
void list_tail_remove(node<Item>*& tail_ptr) {
  node<Item>* remove_ptr = tail_ptr;
  tail_ptr = tail_ptr->prev();
  if (tail_ptr != NULL) {
    tail_ptr->set_next(NULL);
  }
  delete remove_ptr;
}

template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry) {
  node<Item>* insert_ptr;
  insert_ptr = new node<Item>(previous_ptr, entry, previous_ptr->next());
  previous_ptr->set_next(insert_ptr);
}

template <class Item>
void list_attach(node<Item>* next_ptr, const Item& entry) {
  node<Item>* insert_ptr;
  insert_ptr = new node<Item>(next_ptr->prev(), entry, next_ptr);
  next_ptr->set_prev(insert_ptr);
}

template <class Item>
std::size_t list_length(const node<Item>* head_ptr) {
  const node<Item>* cursor;
  std::size_t answer;

  answer = 0;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->next()) ++answer;

  return answer;
}

template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position) {
  NodePtr cursor;
  SizeType i;

  assert(0 < position);
  cursor = head_ptr;
  for (i = 1; (i < position) && (cursor != NULL); ++i) cursor = cursor->next();
  return cursor;
}

template <class Item>
void list_remove(node<Item>* previous_ptr) {
  // function remains for backwards compatibility, but relies on
  list_remove_current(previous_ptr->next());
}

template <class Item>
void list_remove_current(node<Item>* current_ptr) {
  node<Item>* prev_ptr = current_ptr->prev();
  node<Item>* next_ptr = current_ptr->next();
  if (prev_ptr != NULL) {
    prev_ptr->set_next(next_ptr);
  }
  if (next_ptr != NULL) {
    next_ptr->set_prev(prev_ptr);
  }
  delete current_ptr;
}

template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target) {
  NodePtr cursor;

  for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
    if (target == cursor->data()) return cursor;
  return NULL;
}
}  // namespace main_savitch_6B
```

### Output

```text
$ make && ./main.out
g++ -Wall -o main.out main.cpp

Creating a new deque called d1.
d1.empty() : true
d1 has contents: { }
Pushing '3' to front... got { 3 }. Pass.
Pushing '2' to front... got { 2 3 }. Pass.
Pushing '1' to front... got { 1 2 3 }. Pass.
Pushing '4' to back... got { 1 2 3 4 }. Pass.
Pushing '5' to back... got { 1 2 3 4 5 }. Pass.
Pushing '6' to back... got { 1 2 3 4 5 6 }. Pass.

Creating d2, via copy constructor of d1 (`deque<int> d2(d1);`)...
d2.empty() : false
d2 has contents: { 1 2 3 4 5 6 }
Popping first item (1)... got { 2 3 4 5 6 }. Pass.
Popping first item (2)... got { 3 4 5 6 }. Pass.
Popping last item (6)...  got { 3 4 5 }. Pass.
Popping last item (5)...  got { 3 4 }. Pass.
Pushing '0' to back... got { 3 4 0 }. Pass.
Pushing '0' to back... got { 3 4 0 0 }. Pass.
Pushing '0' to back... got { 3 4 0 0 0 }. Pass.
Pushing '0' to back... got { 3 4 0 0 0 0 }. Pass.

Comparing d1 and d2 using != operator...
{ 1 2 3 4 5 6 } and { 3 4 0 0 0 0 } are not equal.

Reassigning d2 using = operator (`d2 = d1;`)...
d2 has contents: { 1 2 3 4 5 6 }
Comparing d1 and d2 using == operator...
{ 1 2 3 4 5 6 } and { 1 2 3 4 5 6 } are equal.
```
