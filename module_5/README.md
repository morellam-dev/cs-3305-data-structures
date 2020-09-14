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
  - Create a list header and insert the following data in order:
    - $23.5, 45.6, 67.7, 89.8, 12.0$
  - Print out the list using the function you wrote
  - Call the function `check_list1` with the list as argument. This
             will print a single message if successful. Otherwise the program will
             terminate.
  - Create a list with two pointers, one to the head and one to the tail.

    - Insert 23.5 into the list.
    - Then insert these elements in order at the tail of the list:
      - $45.6, 67.7, 123.5, 89.8, 12.0$
    - Print the list
    - Call the function `check_list2` with the list as argument
  - Declare head and tail pointers for another list
    - Use those pointers to make a copy of the first list you created
    - Print the list
    - Call the function `check_list1` with the list as argument.
    - Print out the data at the tail of the list, it should be $23.5$.
  - Remove the first item in the second list created above
    - Print the list
    - Call the function `check_list2B` with the list as argument
  - Continue with the same list and remove the third item in the list
    - Print the list
    - Call the function `check_list2C` with the list as argument.

- Here is the output from **one version of the exercise**. This uses a fancier version of the print list function (The result of Task 1 should be similar to this. The order of numbers for each test in below is the answer.)

```text
{12.9, 89.8, 67.7, 45.6, 23.5}
check_list1 done
{23.5, 45.6, 67.7, -123.5, 89.8, 12.9}
check_list2 done
at location 4 in list2 -123.
{12.9, 89.8, 67.7, 45.6, 23.5}
check_list
done at tail3:
23.
{45.6, 67.7, -123.5, 89.8, 12.9}
check_list2B done
{45.6, 67.7, 89.8, 12.9}
check_list2C done
```

## Task 2

Do **programming projects 2 and 7 on page 287 of textbook**. Put the required functions in
the **new created "main.cpp"** using the class **node1**. (You don’t need to modify node1. Just
use it)

- Writing functions for each project 2 and 7. (remove duplicates, rearrangement)
- Writing a ‘main’ function to test your functions. It is not necessary to make it to interact
    test.
- You can use the print_list() function from Task 1 to print your linked list.

Hint: use a scenario such as ‘create new list’, ‘input numbers to your linked list.’, ‘show the
list’, ‘remove duplicates’, ‘show the list’, ‘rearrange the list’, ‘show the list’.

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
