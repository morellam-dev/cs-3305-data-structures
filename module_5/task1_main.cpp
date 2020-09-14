#include <iostream>

#include "check_lists.h"
#include "node1.h"

using namespace main_savitch_5;

// Prints out the elements in the list separated by spaces all on one line
void list_print(node *head_ptr);

// MAIN METHOD

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
