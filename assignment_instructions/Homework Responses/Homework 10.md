# CS 3305 Data Structures

M Morella

## Homework Assignment 10

### Part 1

![Output of 10-expression-trees/main.cpp](https://i.imgur.com/F8cbsW7.png)

#### `expression_tree.h`

```cpp
// FILE: expression_tree.h
// A class which implements simple expression trees which can be generated from
// a string, and recursively printed and evaluated.
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>  // for ostream
#include <string>    // for string

#include "bintree.h"

namespace exprtree {

typedef BinaryTreeNode<std::string> Node;

class ExpressionTree {
 public:
  // Builds an ExpressionTree by parsing a string e.g. "1 * 3 = 5". All operands
  // and operators must be separated by spaces. Supported operators are "*" and
  // "+"
  ExpressionTree(std::string expr);
  ~ExpressionTree() { tree_clear(root); }
  // Evaluates the expression contained in the tree.
  int evaluate();
  friend std::ostream &operator<<(std::ostream &out,
                                  const ExpressionTree &tree);
  Node *get_root() { return root; }

 private:
  Node *root;
};

std::ostream &operator<<(std::ostream &out, const Node *root);

// Helper function: recursively evaluate the expression
int evaluate_tree(Node *root);

// Given an iterable list of tokens {"1", "+", "1"}, generate a binary tree
template <typename It>
Node *build_from_list(It first, It last) {
  if (first == last) return NULL;
  // Find the first "*"
  It it = std::find(first, last, "+");
  // If none, find the first "*"
  if (it == last) it = std::find(first , last, "*");
  // If none, this is a leaf.
  if (it == last) it = first;
  return new Node(*it, build_from_list(first, it), build_from_list(++it, last));
}
// Given a string formatted like "
Node *build_from_string(const std::string &str);
}  // namespace exprtree

#endif  // EXPRESSION_TREE_H
```

#### `expression_tree.cpp`

```cpp
#include "expression_tree.h"

#include <vector>  // for std::vector

namespace exprtree {

ExpressionTree::ExpressionTree(std::string expr)
    : root{build_from_string(expr)} {}

int ExpressionTree::evaluate() { return evaluate_tree(root); }

int evaluate_tree(Node *root) {
  if (root->data() == "*")
    return evaluate_tree(root->left()) * evaluate_tree(root->right());
  if (root->data() == "+")
    return evaluate_tree(root->left()) + evaluate_tree(root->right());
  else
    return std::stoi(root->data());
}

std::ostream &operator<<(std::ostream &out, const Node *root) {
  if (!root) return out;
  if (root->is_leaf()) return out << root->data();
  return out << "(" << root->left() << root->data() << root->right() << ")";
}
std::ostream &operator<<(std::ostream &out, const ExpressionTree &tree) {
  return out << tree.root;
}

Node *build_from_string(const std::string &str) {
  // parse the given string, separating spaces.
  std::vector<std::string> tokens;
  size_t start = 0;
  size_t end;
  do {
    end = str.find(' ', start);
    tokens.push_back(str.substr(start, end - start));
    start = end + 1;
  } while (end != str.npos);
  return build_from_list(tokens.begin(), tokens.end());
}
}  // namespace exprtree
```

#### `main.cpp`

```cpp
#include "expression_tree.h"

using namespace exprtree;

int main() {
  // Sample usage of ExpressionTree
  std::string s1 = "3 + 7 * 14";
  std::cout << "Generating an ExpressionTree from '" << s1 << "'\n";
  ExpressionTree e1(s1);
  std::cout << e1 << " = " << e1.evaluate() << '\n';

  std::string s2 = "1 + 2 * 3";
  std::cout << "Generating an ExpressionTree from '" << s2 << "'\n";
  ExpressionTree e2(s2);
  std::cout << e2 << " = " << e2.evaluate() << '\n';
}
```

#### Output

```text
Generating an ExpressionTree from '3 + 7 * 14'
(3+(7*14)) = 101
Generating an ExpressionTree from '1 + 2 * 3'
(1+(2*3)) = 7
```

### Part 2

![Output of 10-binary-search-tree/main.cpp](https://i.imgur.com/QKgW0ma.png)

#### `main.cpp`

```cpp
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
```

#### Output

```text
[[[[[ after ] also [ any ]] back [[ because ] come [ day ]]] even [[[ first ] give [ how ]] its [[ look ] most [ new ]]]] now [[[[ only ] other [ our ]] over [[ than ] then [ these ]]] think [[[ two ] us [ use ]] want [[ way ] well [ work ]]]]]
Depth: 4
```
