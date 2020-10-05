# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 7

### Requirements

The goal of this assignment is to reinforce using linked list to implement **template queue class** in C++. Specifically, the assignment is to create a dynamic implementation of a **deque using the linked list implementation**. The header file for the deque is `deque.h`. Remember to use the template node class (`node2.h`, `node2.template`). Write a **test program** to test the deque class you implemented.

#### Hints

- A description of deque is written in Section 8.4 of the textbook.
- You need to write two files:
  - `deque.template` for the implementation of the deque class
  - `main.cpp` for the testing program.
- Don't forget about `using namespace main_savitch_6B` if you use node2 in your code.
- You can implement with a doubly linked list. To make it doubly linked, you can modify `node2.h` and `node2.template`.
- To implement, template `<class T>` is used instead of `<class Item>`
  - Instead of the word `Item`, you must use `T`.

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
