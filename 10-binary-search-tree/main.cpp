#include <string>

#include "bst.h"
using namespace std;

/* A function that constructs Balanced Binary Search Tree from a sorted array */
void insert_inorder(binary_search_tree<string> &bst, string arr[], int start,
                    int end) {
  if (start > end) return;
  int mid = (start + end) / 2;
  bst.insert(arr[mid]);
  insert_inorder(bst, arr, start, mid - 1);
  insert_inorder(bst, arr, mid + 1, end);
}

int main() {
  binary_search_tree<string> bst;
  string data[]{"after", "also",  "any",   "back",  "because", "come", "day",
                "even",  "first", "give",  "how",   "its",     "look", "most",
                "new",   "now",   "only",  "other", "our",     "over", "than",
                "then",  "these", "think", "two",   "us",      "use",  "want",
                "way",   "well",  "work"};
  size_t size = 31;
  insert_inorder(bst, data, 0, size - 1);
  std::cout << bst << "\n";
  std::cout << "Depth: " << check_balanced(bst.get_root()) << "\n";
  return 0;
}