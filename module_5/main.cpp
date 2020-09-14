#include <iostream>

#include "check_lists.h"
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
  // TASK 1 CODE
  std::cout << "\n=== TASK 1 OUTPUTS ===\n\n";
  // LIST 1
  node *list1 = new node(23.5);
  list_head_insert(list1, 45.6);
  list_head_insert(list1, 67.7);
  list_head_insert(list1, 89.8);
  list_head_insert(list1, 12.9);
  list_print(list1);
  check_list1(list1);

  // LIST 2
  node *list2 = new node(23.5);
  node *tail2 = list2;
  list_insert(tail2, 45.6);
  tail2 = tail2->link();
  list_insert(tail2, 67.7);
  tail2 = tail2->link();
  list_insert(tail2, -123.5);
  tail2 = tail2->link();
  list_insert(tail2, 89.8);
  tail2 = tail2->link();
  list_insert(tail2, 12.9);
  tail2 = tail2->link();
  std::cout << "list2: ";
  list_print(list2);
  check_list2(list2);
  std::cout << "at location 4 in list2: " << list_locate(list2, 4)->data()
            << "\n";
  // above instruction is not given, but present in the sample output

  // LIST 3
  node *list3;
  node *tail3;
  list_copy(list1, list3, tail3);
  std::cout << "list3: ";
  list_print(list3);
  check_list1(list3);
  std::cout << "at tail3: " << tail3->data() << "\n";

  // BACK TO LIST 2 ?:s
  list_head_remove(list2);
  list_print(list2);
  check_list2B(list2);
  list_remove(list_locate(list2, 2));
  // instructions say to remove 3rd item,
  // but -123.5 is actually 2nd item at this point
  list_print(list2);
  check_list2C(list2);

  // TASK 2 TESTS
  std::cout << "\n=== TASK 2 OUTPUTS ===\n\n";
  node *list4 = new node(1.0);
  list_head_insert(list4, 2.0);
  list_head_insert(list4, 1.0);
  list_head_insert(list4, 2.0);
  list_head_insert(list4, 1.0);
  list_head_insert(list4, 5.0);
  list_head_insert(list4, 2.0);
  list_head_insert(list4, 3.0);
  list_head_insert(list4, 4.0);
  list_head_insert(list4, 2.0);
  list_head_insert(list4, 4.0);
  std::cout << "list4: ";
  list_print(list4);
  std::cout << "after sorting: ";
  sort_list(list4);
  list_print(list4);
  std::cout << "after remove duplicates: ";
  list_remove_duplicates(list4);
  list_print(list4);

  std::cout << "list3: ";
  list_print(list3);
  std::cout << "after sorting list3: ";
  sort_list(list3);
  list_print(list3);
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
// Finds the node with the largest value, unlinks it, and returns a pointer to that node.
node *list_yank_largest(node *&head_ptr) {
  node *prev = new node(-1, head_ptr);
  node::value_type biggest_value = prev->link()->data();
  for (node *cursor = head_ptr; cursor != NULL && cursor->link() != NULL; cursor = cursor->link()) {
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
  node *new_head_ptr = NULL;      // create a second list
  while (head_ptr != NULL) {  // while the first list still has some elements...
    node *largest = list_yank_largest(head_ptr); // find the largest item, and unlink it.
    largest->set_link(new_head_ptr);
    new_head_ptr = largest;
  }
  head_ptr = new_head_ptr;
}
