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
