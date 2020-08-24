# Homework Assignment 1-1

Max Morella

**4.**

```cpp
assert(1 <= month && month <= 12)
```

**5.**

```cpp
// Precondition: x is greater than or equal to 0
// Postcondition: the return value is the square root of x
```

**11.**

a. $O(n^2)$

b. $O(n^2)$

c. $O(n^2)$

d. $O(n)$

e. $O(n^2)$

f. $O(\log_{10}(n))$

g. $O(\log_{10}(n))$

**14.** $O(n^2)$

**16.**

```c++
int n = 100; // <- change
int sum = 0;
for (int i = 1; i <= n; i++)
{
    sum += i;
}
std::cout << sum;
```

$O(n)$

## Lab Exercise 1 - ex_01.cpp

![Screenshot of ex_01.cpp executing in a terminal](https://i.imgur.com/sxogbNV.png)

```cpp
/** ex_01.cpp
 * Prints personal information about me, 
 * in stunning 4-bit color!
 * If your terminal or OS do not support 
 * ANSI escape sequences this will probably 
 * print garbage.
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
    std::cout << '\n'; 
    // print an extra line of separation between the invoking command 
    // and the output
    std::cout << BGRN + "Name" + ARRW + "M Morella (She/They)" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Hometown\t" + ARRW + "Alpharetta" + '\n';
    std::cout << BGRN + "High School\t" + ARRW + "Milton High School" + '\n';
    std::cout << BGRN + "Occupation\t" + ARRW 
                      + "Studying online, not getting the coronavirus." + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Comp Sci Courses I've Taken" + ARRW + '\n';
    std::cout << ASTX + "APCS\t\t- AP Computer Science" + '\n';
    std::cout << ASTX + "CSE 1322\t- Programming II" + '\n';
    std::cout << ASTX + "MATH 2202\t- Calculus II" + '\n';
    std::cout << ASTX + "MATH 2345\t- Discrete Mathematics" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Computers I Use" + ARRW + '\n';
    std::cout << ASTX + "Desktop \"Gaming\" PC\t"
               + BBLU + "[GTX 1060]\t(Windows 10)" + '\n';
    std::cout << ASTX + "Macbook Pro 2015 \t"
               + BBLU + "[i5-5287U]\t(macOS 10.15)" + '\n';
    std::cout << ASTX + "iPhone 11 \t\t"
               + BBLU + "[64 GB]\t\t(iOS 14 Beta)" + '\n';
    std::cout << ASTX + "Google Pixel XL  \t"
               + BBLU + "[128 GB]\t(Android 10)" + '\n';
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
```

## Lab Exercise 2 - ex_02.cpp

![The far less impressive results of executing ex_02.cpp in a terminal](https://i.imgur.com/Q2iLIiZ.png)



```cpp
/** ex_02.cpp
 * Max Dylan Morella
 * Homework Assignment 1-2 (Lab Assignments)
 * Exercise 2
 */

#include <iostream>

using namespace std;

int main()
{
    for (int i = 8; i >= 0; i -= 2)
    {
        for (int j = i; j >= 0; j -= 2)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
```