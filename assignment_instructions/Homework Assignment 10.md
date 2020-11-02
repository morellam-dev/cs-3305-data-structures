# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 10

The goal of this assignment is to reinforce tree implementations in C++.

### Requirements

#### Part 1

Carry out programming project #1 in Chapter 10 of the text on page 534.

Your solution will consist of a pair of files defining the expression tree class and a program
demonstrating the use of the class. The demo program should create at least two different
expression trees and evaluate them, printing the result of the evaluation. Include in the code a
comment about each tree that shows the expression in usual algebraic form. For one of your trees,
use the example given in the problem statement.

##### Programming Project #1

This project deals with a simple kind of expression tree, where there are two kinds of nodes:

(a) Leaf nodes, which contain a real number as their entry;
(b) Nonleaf nodes, which contain either the character `+` or the character `*` as their entry, and have exactly two children.

For this project, implement a class for expression trees, including operations for building expression trees. Also include a recursive function to “evaluate” a non-empty expression tree using these rules:

(a) If the tree has only one node (which must be a leaf), then the evaluation of the tree returns the real number that is the node’s entry;
(b) If the tree has more than one node, and the root contains `+`, then first evaluate the left  subtree, then evaluate the right subtree, and add the results. If the root contains `*`, then evaluate the two subtrees and multiply the results.

```text
   '*'
   / \
 '+'  14
 / \
3   7
```

For example, consider the small expression tree shown above. The left subtree evaluates to 3+7, which is 10. The right subtree evaluates to 14. So the entire tree evaluates to `10*14`, which is `140`.

#### Part 2

**You need download the BST project from our course website.**

Build a binary search tree with the following words. Insert them in an order so that the tree has as
small a depth as possible. (Consider the insertion order of the words) Print the tree:

```text
after
also
any
back
because
come
day
even
first
give
how
its
look
most
new
now
only
other
our
over
than
then
these
think
two
us
use
want
way
well
work
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
