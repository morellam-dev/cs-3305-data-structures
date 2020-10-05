// node3.h (part of the namespace main_savitch_6B)
// AUTHOR: M Morella, based on code provided by M. Main & W. Savitch.
// PROVIDES: A template class for a node in a doubly linked list, helper
// functions for manipulating linked lists, and a bidirectional node iterator.
// The node_iterator is a forward iterators with two constructors: (1) A
// constructor (with a node<Item>* parameter) that attaches the iterator to the
// specified node in a linked list, and (2) a default constructor that creates a
// special iterator that marks the position that is beyond the end of a linked
// list. There is also a const_node_iterator for use with const node<Item>*.
#pragma once

#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

namespace main_savitch_6B {
template <class Item>
class node {
 public:
  // TYPEDEF for the node<Item> template class:
  typedef Item value_type;
  // Postcondition: The node now contains the specified new next.
  // NOTE: The default value for the init_data is obtained from the default
  // constructor of the Item.
  node(const Item& init_data = Item(), node* init_next = NULL,
       node* init_prev = NULL) {
    data_field = init_data;
    next_field = init_next;
    prev_field = init_prev;
  }
  // @returns a reference the stored Item of this node.
  Item& data() { return data_field; }
  // @returns a node pointer to the next linked node.
  node* next() { return next_field; }
  // @returns a node pointer to the previously linked node.
  node* prev() { return prev_field; }

  // CONST GETTER METHODS

  // @returns a reference to the stored Item of this node.
  const Item& data() const { return data_field; }
  // @returns a node pointer to the next linked node.
  const node* next() const { return next_field; }
  // @returns a node pointer to the previously linked node.
  const node* prev() const { return prev_field; }

  // MODIFIER METHODS

  // Postcondition: This node now stores the given Item.
  void set_data(const Item& new_data) { data_field = new_data; }
  // Postcondition: The node now links to the specified next node.
  void set_next(node* new_next) { next_field = new_next; }
  // Postcondition: The node now links to the specified prevous node.
  void set_prev(node* new_prev) { next_field = new_prev; }

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
