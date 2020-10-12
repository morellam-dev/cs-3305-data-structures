/**
 * @file    ex_01.cpp
 * @author  M Morella
 * @brief   Prints personal information about me, in stunning 4-bit color!
 *
 * Execute binary with -c flag to enable ANSI color in output.
 */

#include <iostream>
#include <string>

#include "colors.h"

using std::cout;
using std::string;

#define ARRW YELLOW << " → " << RESET
#define BOLD BOLDGREEN
#define BOLD2 BOLDBLUE
#define ASTX YELLOW << " * " << RESET

int main(int argc, char *argv[]) {
  // check for -c flag, then enable or disable color constants.
  // print an accented arrow for separating strings

  cout << '\n';
  cout << BOLD << "My Name" << ARRW << "M Morella (She/They)\n"
       << BOLD << "Major" << ARRW << "Computer Science\n"
       << BOLD << "Occupation" << ARRW << "Student\n"
       << '\n';
  cout << BOLD << "CS Courses I've Taken" << ARRW << '\n'
       << ASTX << "     APCS - AP Computer Science\n"
       << ASTX << " CSE 1322 - Programming II\n"
       << ASTX << "MATH 2202 - Calculus II\n"
       << ASTX << "MATH 2345 - Discrete Mathematics\n"
       << '\n';
  cout << BOLD << "Computers I Use" << ARRW << '\n'
       << ASTX << "Desktop Gaming PC\t" << BOLD2 << "[x4 860k]\t(Windows 10)\n"
       << ASTX << "Macbook Pro 2015\t" << BOLD2 << "[i5-5287U]\t(macOS 10.15)\n"
       << ASTX << "Apple iPhone 11\t" << BOLD2
       << "[A13 + 64 GB]\t(iOS 14 Beta)\n"
       << '\n';
  cout << BOLD << "Hobbies" << ARRW << '\n'
       << ASTX << "Music\n"
       << ASTX << "Programming\n"
       << ASTX << "Cooking\n"
       << '\n'
       << BOLD << "After I graduate, I hope to" << ARRW << '\n'
       << ASTX << "Be employed.\n";
  std::cout << "\n";
  return 0;
}