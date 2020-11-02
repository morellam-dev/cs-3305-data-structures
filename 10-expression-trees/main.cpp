#include "expression_tree.h"

using namespace exprtree;

int main() {
  // Sample usage of ExpressionTree
  ExpressionTree e("3 + 7 * 14");
  std::cout << e << '\n';
  std::cout << e.evaluate() << '\n'; // -> 140
}