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