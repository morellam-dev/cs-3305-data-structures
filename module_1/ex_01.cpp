/** ex_01.cpp
 * Prints personal information about me, in stunning 4-bit color!
 * If your terminal or OS do not support ANSI escape sequences this will probably print garbage.
 * 
 * Max Morella
 * Homework Assignment 1-2 (Lab Assignments)
 * Exercise 1
 */

#include <iostream>
#include <string>

/* CONSTANTS FOR ANSI CODES */

// ANSI code to reset color
const std::string RSET = "\e[0m";
// ANSI code to make text use bold green
const std::string BGRN = RSET + "\e[1;" + (std::to_string(32)) + "m";
// ANSI code to make text use blue
const std::string BBLU = RSET + "\e[1;" + (std::to_string(34)) + "m";
// ANSI code to make text use an accent color (33=yellow)
const std::string ACNT = RSET + "\e[" + (std::to_string(33)) + "m";

/* CONSTANTS FOR TYPOGRAPHY */

// prints an accented bullet point for items in a list
const std::string ASTX = ACNT + " * " + RSET;
// print an accented arrow for separating strings
const std::string ARRW = ACNT + " → " + RSET;

/* MAIN PROGRAM */

int main()
{
    std::cout << '\n'; // print an extra line of separation between the invoking command and the output
    std::cout << BGRN + "Name" + ARRW + "M Morella (She/They)" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Hometown\t" + ARRW + "Alpharetta" + '\n';
    std::cout << BGRN + "High School\t" + ARRW + "Milton High School" + '\n';
    std::cout << BGRN + "Occupation\t" + ARRW + "Studying online, not getting the coronavirus." + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Comp Sci Courses I've Taken" + ARRW + '\n';
    std::cout << ASTX + "APCS\t\t- AP Computer Science" + '\n';
    std::cout << ASTX + "CSE 1322\t- Programming II" + '\n';
    std::cout << ASTX + "MATH 2202\t- Calculus II" + '\n';
    std::cout << ASTX + "MATH 2345\t- Discrete Mathematics" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Computers I Use" + ARRW + '\n';
    std::cout << ASTX + "Desktop \"Gaming\" PC\t" + BBLU + "[GTX 1060]\t(Windows 10)" + '\n';
    std::cout << ASTX + "Macbook Pro 2015 \t" + BBLU + "[i5-5287U]\t(macOS 10.15)" + '\n';
    std::cout << ASTX + "iPhone 11 \t\t" + BBLU + "[64 GB]\t\t(iOS 14 Beta)" + '\n';
    std::cout << ASTX + "Google Pixel XL  \t" + BBLU + "[128 GB]\t(Android 10)" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Hobbies of Mine" + ARRW + '\n';
    std::cout << ASTX + "Singing in Choir" + '\n';
    std::cout << ASTX + "Playing and Developing Video Games" + '\n';
    std::cout << ASTX + "Cooking Food" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "After I graduate, I hope to" + ARRW + "Be employed.";
    std::cout << '\n'; // be kind, newline.
    std::cout << '\n'; // and a second one, just for looks
    return 0;
}