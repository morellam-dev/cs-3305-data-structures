#include <iostream>

#include "node1.h"

using namespace main_savitch_5;

// Prints out the elements in the list separated by spaces all on one line
void list_print(node *head_ptr);

// Removes all but the first of each value from the list.
// Precondition: head_ptr is a head pointer of a linked list of items, and
// these items can be compared with an equality (==) operator
// Postcondition: head_ptr points to the head of a linked list with exactly one
// instance of every value in the given list.
// The original linked list is no longer available.
void list_remove_duplicates(node *&head_ptr);

// Precondition: head_ptr is a head pointer of  a linked list of items, and
// these items can be compared with a less-than operator.
// Postcondition: head_ptr points to the head of a linked list with exactly
// the same entries (including repetitions if any), but the entries in this
// list are sorted from smallest to largest. The original linked list is no
// longer available.
void sort_list(node *&head_ptr);

int main(int argc, char const *argv[]) {
  // task 2 tests
  std::cout << "\n=== TASK 2 DEMOS ===\n\n";
  node *list2 = new node(23.5);
  list_head_insert(list2, 67.7);
  list_head_insert(list2, 89.8);
  list_head_insert(list2, 45.6);
  list_head_insert(list2, 67.7);
  list_head_insert(list2, -123.5);
  list_head_insert(list2, 89.8);
  list_head_insert(list2, 12.9);
  list_head_insert(list2, 12.9);
  node *list1 = new node(1.0);
  list_head_insert(list1, 2.0);
  list_head_insert(list1, 1.0);
  list_head_insert(list1, 2.0);
  list_head_insert(list1, 1.0);
  list_head_insert(list1, 5.0);
  list_head_insert(list1, 2.0);
  list_head_insert(list1, 3.0);
  list_head_insert(list1, 4.0);
  list_head_insert(list1, 2.0);
  list_head_insert(list1, 4.0);
  std::cout << "list1: ";
  list_print(list1);
  std::cout << "after remove duplicates: ";
  list_remove_duplicates(list1);
  list_print(list1);
  std::cout << "after sorting: ";
  sort_list(list1);
  list_print(list1);
  std::cout << "\n";
  std::cout << "list2: ";
  list_print(list2);
  std::cout << "after sorting list2: ";
  sort_list(list2);
  list_print(list2);
  std::cout << "after remove duplicates: ";
  list_remove_duplicates(list2);
  list_print(list2);
  return 0;
}

// Implementations

void list_print(node *head_ptr) {
  std::cout << "{";
  for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
    std::cout << cursor->data();
    if (cursor->link() != NULL) {
      std::cout << ", ";
    } else {
      std::cout << "}";
    }
  }
  std::cout << "\n";
}

void list_remove_duplicates(node *&head_ptr) {
  // for each existing node...
  for (node *cur = head_ptr; cur != NULL; cur = cur->link()) {
    node *search = cur;
    while (search != NULL) {
      while (search->link() != NULL && search->link()->data() == cur->data()) {
        list_remove(search);
      }
      search = search->link();
    }
  }
}

// Helper function for selective sort method
// Searches the given linked list for the largest value, which
// Finds the node with the largest value, unlinks it, and returns a pointer to
// that node.
node *list_yank_largest(node *&head_ptr) {
  node *prev = new node(-1, head_ptr);
  node::value_type biggest_value = prev->link()->data();
  for (node *cursor = head_ptr; cursor != NULL && cursor->link() != NULL;
       cursor = cursor->link()) {
    node::value_type value = cursor->link()->data();
    if (value > biggest_value) {
      prev = cursor;
      biggest_value = value;
    }
  }
  node *largest = prev->link();
  if (largest == head_ptr) {
    head_ptr = largest->link();
  } else {
    prev->set_link(prev->link()->link());
  }
  return largest;
}

void sort_list(node *&head_ptr) {
  node *new_head_ptr = NULL;  // create a second list
  while (head_ptr != NULL) {  // while the first list still has some elements...
    node *largest =
        list_yank_largest(head_ptr);  // find the largest item, and unlink it.
    largest->set_link(new_head_ptr);
    new_head_ptr = largest;
  }
  head_ptr = new_head_ptr;
}