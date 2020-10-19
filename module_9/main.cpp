#include <cmath>     // for std::max
#include <iostream>  // for std::cout

#include "bintree.h"
#include "build_tree.h"
using namespace std;

// Returns the maximum of the depths of the left and right subtrees,
template <class T>
int depth(binary_tree_node<T> *root) {
  if (!root) {
    return -1;
  }
  int left_depth = depth(root->left());
  int right_depth = depth(root->right());
  return 1 + std::max(left_depth, right_depth);
}
// Returns the largest value in the tree
template <class T>
T max(binary_tree_node<T> *root) {
}
// returns the sum of the values in all the nodes in the tree
double tree_sum(binary_tree_node<double> *root) {
}
// returns the average of the values in all the nodes in the tree
double tree_average(binary_tree_node<double> *root) {
}
// returns whether the tree is balanced
// i.e. the depth of each subtree differs by at most 1, and each subtree is balanced
template <class T>
bool tree_is_balanced(binary_tree_node<T> *root) {
}

template <class T>
void printItem(T item) {
  cout << item << " ";
}

int main() {
  binary_tree_node<int> *s1 = sample1();
  cout << "size of s1: " << tree_size(s1) << endl;
  cout << "depth of s1: " << depth(s1) << endl;
  cout << "max of s1: " << max(s1) << endl;

  binary_tree_node<int> *s2 = sample2();
  cout << "size of s2: " << tree_size(s2) << endl;
  cout << "depth of s2: " << depth(s2) << endl;
  cout << "max of s2: " << max(s2) << endl;

  binary_tree_node<double> *s3 = sample3();
  cout << "size of s3: " << tree_size(s3) << endl;
  cout << "depth of s3: " << depth(s3) << endl;
  cout << "max of s3: " << max(s3) << endl;

  binary_tree_node<double> *s4 = sample4();
  cout << "size of s4: " << tree_size(s4) << endl;
  cout << "depth of s4: " << depth(s4) << endl;
  cout << "max of s4: " << max(s4) << endl;

  cout << endl;

  cout << "sum of s3: " << tree_sum(s3) << endl;
  cout << "average of s3: " << tree_average(s3) << endl;
  cout << "size of s3: " << tree_size(s3) << endl;

  binary_tree_node<string> *s5 = sample5();
  binary_tree_node<double> *b1 = sample_bal1();

  cout << "sum of b1: " << tree_sum(b1) << endl;
  cout << "average of b1: " << tree_average(b1) << endl;
  cout << "size of b1: " << tree_size(b1) << endl;

  binary_tree_node<double> *b2 = sample_bal2();

  cout << "sum of b2: " << tree_sum(b2) << endl;
  cout << "average of b2: " << tree_average(b2) << endl;
  cout << "size of b2: " << tree_size(b2) << endl;

  cout << endl;
  cout << "s1 is balanced? " << tree_is_balanced(s1) << endl;
  cout << "s2 is balanced? " << tree_is_balanced(s2) << endl;
  cout << "s3 is balanced? " << tree_is_balanced(s3) << endl;
  cout << "s4 is balanced? " << tree_is_balanced(s4) << endl;
  cout << "s5 is balanced? " << tree_is_balanced(s5) << endl;
  cout << "b1 is balanced? " << tree_is_balanced(b1) << endl;
  cout << "b2 is balanced? " << tree_is_balanced(b2) << endl;
}
