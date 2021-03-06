// FILE: node1.h
// PROVIDES: A class for a node in a linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*).
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#pragma once

#include <cstdlib>  // Provides size_t and NULL

namespace main_savitch_5 {
class node {
 public:
  // TYPEDEF

  // Each node of the list contains a piece of data and a pointer to the
  // next node. The type of the data is defined as node::value_type in a
  // typedef statement. The value_type may be any
  // of the built-in C++ classes (int, char, ...) or a class with a copy
  // constructor, an assignment operator, and a test for equality (x == y).
  typedef double value_type;

  // CONSTRUCTOR

  // Postcondition: The node contains the specified data and link.
  // NOTE: The default value for the init_data is obtained from the default
  // constructor of the value_type. In the ANSI/ISO standard, this notation
  // is also allowed for the built-in types, providing a default value of
  // zero. The init_link has a default value of NULL.
  node(const value_type &init_data = value_type(), node *init_link = NULL) {
    data_field = init_data;
    link_field = init_link;
  }
  // Member functions

  // Postcondition: The node now contains the specified new data.
  void set_data(const value_type &new_data) { data_field = new_data; }
  // Postcondition: The node now contains the specified new link.
  void set_link(node *new_link) { link_field = new_link; }
  // Postcondition: The return value is the data from this node.
  value_type data() const { return data_field; }
  // Member function to retrieve the current link (const)
  // Postcondition: The return value is the link from this node.
  const node *link() const { return link_field; }
  // Member function to retrieve the current link (non-const)
  // Postcondition: The return value is the link from this node.
  node *link() { return link_field; }

 private:
  value_type data_field;
  node *link_field;
};

// FUNCTIONS for the linked list toolkit

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The value returned is the number of nodes in the linked
// list.
std::size_t list_length(const node *head_ptr);

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: A new node containing the given entry has been added at
// the head of the linked list; head_ptr now points to the head of the new,
// longer linked list.
void list_head_insert(node *&head_ptr, const node::value_type &entry);

// Precondition: previous_ptr points to a node in a linked list.
// Postcondition: A new node containing the given entry has been added
// after the node that previous_ptr points to.
void list_insert(node *previous_ptr, const node::value_type &entry);

// (non-const version. See the note in node1.h)
// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The pointer returned points to the first node containing
// the specified target in its data member. If there is no such node, the
// null pointer is returned.
node *list_search(node *head_ptr, const node::value_type &target);

// (const version. See the note in node1.h)
// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The pointer returned points to the first node containing
// the specified target in its data member. If there is no such node, the
// null pointer is returned.
const node *list_search(const node *head_ptr, const node::value_type &target);

// Precondition: head_ptr is the head pointer of a linked list, and
// position > 0.
// Postcondition: The pointer returned points to the node at the specified
// position in the list. (The head node is position 1, the next node is
// position 2, and so on). If there is no such position, then the null
// pointer is returned.
node *list_locate(node *head_ptr, std::size_t position);

// Precondition: head_ptr is the head pointer of a linked list, and
// position > 0.
// Postcondition: The pointer returned points to the node at the specified
// position in the list. (The head node is position 1, the next node is
// position 2, and so on). If there is no such position, then the null
// pointer is returned.
const node *list_locate(const node *head_ptr, std::size_t position);

// Precondition: head_ptr is the head pointer of a linked list, with at
// least one node.
// Postcondition: The head node has been removed and returned to the heap;
// head_ptr is now the head pointer of the new, shorter linked list.
void list_head_remove(node *&head_ptr);

// Precondition: previous_ptr points to a node in a linked list, and this
// is not the tail node of the list.
// Postcondition: The node after previous_ptr has been removed from the
// linked list.
void list_remove(node *previous_ptr);

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: All nodes of the list have been returned to the heap,
// and the head_ptr is now NULL.
void list_clear(node *&head_ptr);

// Precondition: source_ptr is the head pointer of a linked list.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers for
// a new list that contains the same items as the list pointed to by
// source_ptr. The original list is unaltered.
void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr);
}  // namespace main_savitch_5
