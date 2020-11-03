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