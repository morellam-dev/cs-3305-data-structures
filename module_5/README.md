# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 5

The goal of this assignment is to reinforce linked lists in C++.

When you use `node1` class at the other source code file, you must `#include “node1.h”` and
write `using namespace main_savitch_5;` after all of the includes.

You need to do the same ways for the linked list toolkit (`check_lists`)

## Task 1

Get familiar with the methods in the linked lists toolkit

- **Create a project** for this lab:
  - Get the files `node1.h` and `node1.cpp` that contain the linked list toolkit
       and add them to the project.
  - Include the files `check_lists.cpp` and `check_lists.h` in the project.
  - **Create a C++ file** that will contain a **`main` program**.
- **Create a function** that will print a list out, given the header node. Here is the function
    header:
  - `void list_print(node * head_ptr)`
  - Place this function before the `main` function in your program.
  - The function should print out the elements in the list separated by spaces all on one line
  - The function should print an end of line after the list data is printed.

- **Carry out the following steps** in the program, that is, in the function `main`:
  - Create a list header and insert the following data in order: $23.5, 45.6, 67.7,
       89.8, 12$
  - Print out the list using the function you wrote
  - Call the function `check_list1` with the list as argument. This
             will print a single message if successful. Otherwise the program will
             terminate.
  - Create a list with two pointers, one to the head and one to the tail.

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
