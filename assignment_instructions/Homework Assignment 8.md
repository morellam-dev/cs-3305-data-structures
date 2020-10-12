# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 8

The goal of this assignment is to reinforce recursive thinking in C++.

### Requirements

#### Part 1 - Section Numbers

Write a function with this prototype:

```cpp
#include <string>
void numbers(ostream& outs, const string& prefix, unsigned int levels);
```

The function prints output to the `ostream outs`. The output consists of the string prefix
followed by "section numbers" of the form 1.1., 1.2., 1.3., and so on. The levels argument
determines how may levels the section numbers have. For example, if levels is 2, then the
section numbers have the form x.y. If levels is 3, then section numbers have the form x.y.z.
The digits permitted in each level are always '1' through '9'. As an example, if prefix is the
string "THERBLIG" and levels is 2, then the function would start by printing:

```text
// start of output
THERBLIG1.1.
THERBLIG1.2.
THERBLIG1.3.
// …
THERBLIG9.7.
THERBLIG9.8.
THERBLIG9.9.
// end of output
```

The stopping case occurs when levels reaches zero (in which case the prefix is printed
once by itself followed by nothing else).

The string class from `<string>` has many manipulation functions, but you'll need only the
ability to make a new string which consists of prefix followed by another character (such as
'1') and a period ('.'). If s is the string that you want to create and c is the digit character (such as '1'), then the following statement will correctly form s:

```text
s = (prefix + c) + '.';
```

This new string s can be passed as a parameter to recursive calls of the function.

#### Part 2 – A Fractal Pattern

Examine this pattern of asterisks and blanks, and write a recursive function that can
generate patterns such as this:

```text
*
* *
  *
* * * *
    *
    * *
      *
* * * * * * * *
        *
        * *
          *
        * * * *
            *
            * *
              *
```

With recursive thinking, the function needs only seven or eight lines of code (including two
recursive calls). Your prototype should look like this:

```cpp
void pattern(ostream& outs, unsigned int n, unsigned int i);
// Precondition: n is a power of 2 greater than zero.
// Postcondition: A pattern based on the above example has been
// printed to the ostream outs. The longest line of the pattern has
// n stars beginning in column i of the output. For example,
// The above pattern is produced by the call pattern(cout, 8, 0).
```

Hints: You do not need to check the precondition. Think about how the pattern is a fractal.
Can you find two smaller versions of the pattern within the large pattern? Here is some code
that may be useful within your function:

```cpp
// A loop to print exactly i spaces:
for (k = 0; k < i; k++) outs << ' ';
// A loop to print n asterisks, each one followed by a
space: for (k = 0; k < n; k++) outs << "* ";
```

## Submitting Assignment

**When we have only nonprogramming assignment,**

Please submit **One document .doc** file by including the following:

1. Both Typed or Handwritten answers for the questions are allowed.
2. Take a picture of your handwrtten answers, and add it to .doc file is allowed.

**When we have programming assignment,**

Please submit **One Compressed .zip** file by including the following:

1. Copy and Paste your source codes & screenshots of your output in MS Word .doc;
2. Include, all your source codes (.cpp file & all the associated program files) in the .zip file;
3. Be sure to include **// comments** in your files documenting your name, the assignment number.
4. Submit your assignment **.zip file** through D2L [http://d2l.kennesaw.edu/](http://d2l.kennesaw.edu/) dropbox using the appropriate assignment link.
