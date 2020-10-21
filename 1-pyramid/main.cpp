/** main.cpp
 * Max Dylan Morella
 * Homework Assignment 1-2 (Lab Assignments)
 * Exercise 2
 */

#include <iostream>

int main() {
  for (int i = 8; i >= 0; i -= 2) {
    for (int j = i; j >= 0; j -= 2) {
      std::cout << j << " ";
    }
    std::cout << "\n";
  }
}