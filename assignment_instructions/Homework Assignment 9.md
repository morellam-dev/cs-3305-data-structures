# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 9

The purpose of this lab is to reinforce tree，and binary tree implementations and
recursive thinking in C++.

### Requirements

You need download the BinaryTree project from our course website.

```cpp
BinaryTree/
- bintree.h         // Binary tree implementation header.
- bintree.template  // Binary tree implementation.
- build_tree.cpp    // Sample tree building header
- build_tree.h      // Sample tree building header
- main.cpp          // All the functions are declared. Write the body of functions.
```

### Implement the following methods in the main.cpp

#### 1. `depth` function

a. If root is NULL, return -1.
b. Otherwise, determine the maximum of the depths of the left and right subtrees, add 1 and return.

```cpp
template <class T>
int depth(binary_tree_node<T> *root)
```

#### 2. `max` function

a. Assert that root is not NULL
b. Get the max in the left subtree, the max in the right subtree, and the data value in root. Ignore a subtree if it is empty.
c. Return the largest of those three values.

```cpp

template <class T>
T max(binary_tree_node<T> *root)
```

##### Test Results

Testing the above two functions. Here are the results from the first four sample trees:

```text
size of s1: 3
depth of s1: 1
max of s1: 3
size of s2: 12
depth of s2: 3
max of s2: 12
size of s3: 57
depth of s3: 10
max of s3: 0.462529
size of s4: 67
depth of s4: 11
max of s4: 0.488894
```

#### 3. `tree_sum` function

```cpp
// returns the sum of the values in all the nodes in the tree
double tree_sum(binary_tree_node<double> *root)
```

#### 4. `tree_average` function

```cpp
// returns the average of the values in all the nodes in the tree
double tree_average(binary_tree_node<double> *root)
```

#### 5. `tree_is_balanced` function

Returns true if and only if the tree is balanced. This
means that the absolute value of the difference in depth between the two subtrees of root is
no more than 1. It also means that both the left and the right subtree are also balanced. An
empty tree is considered to be balanced.

a. If root is empty, the tree is balanced
b. Otherwise, if either the right or the left subtree is not balanced, then the tree is not
balanced
c. Otherwise, if the difference in depths between the left and right subtrees is greater
than one then the tree is not balanced
d. Otherwise, the tree is balanced

```cpp
template <class T>
bool tree_is_balanced(binary_tree_node<T> *root)
```

##### Test Results

```text
Testing the above three functions. Here are the results from the seven sample trees:
sum of s3 12.9191
average of s3 0.226651
size of s3 57
sum of b1 11018.4
average of b1 47.493
size of b1 232
sum of b2 29775
average of b2 48.8917
size of b2 609
s1 is balanced? 1
s2 is balanced? 1
s3 is balanced? 0
s4 is balanced? 0
s5 is balanced? 1
b1 is balanced? 1
b2 is balanced? 1
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
