# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 6

The purpose of this lab is to reinforce linked-list version of the bag template class with an iterator in C++. You need to use **BagTemplatewithIterator** project posted on the course website.

* You can refer how to use Template using BagTemplatewithIterator Project. You need to add functions for requirement 1, 2. For requirement 3, you should write a new main function instead of given main.cpp in the zip file.

### Requirements

#### 1. Print a range

Write a bag member function with two parameters. The two parameters are `Item`s `x` and `y`. The function should write to the console each `Item` in the `bag` that are between the first occurrence of `x` and the first occurrence of `y`. You may assume that items can be compared for equality using `==.`
Use the following header for the function:

```cpp
void print_value_range(const Item& x, const Item& y);
```

`print_value_range` can be interpreted in a number of ways, but use the following points. This should make the implementation a little easier.

* Print the `Item`s from `x` to `y` including the start but not including the end.
* If there is no element in the bag that has value `x`, print nothing
* Otherwise, if there is no element in the bag, after `x`, that has the value `y`, then print from `x` to the end of the list
* Print the values on one line separated by space. Put an end of line after the values are all printed.

Here are some examples:

```cpp
// b1 = Bag [1,2,3,4,5,6,7]
b1.print_value_range(2, 5)
// -> "2 3 4" + endl

b1.print_value_range(2, 78)
// -> "2 3 4 5 6 7" + endl

b1.print_value_range(8, 5)
// -> "" (no output)
```

#### 2. Remove Repetitions

Write a member function that deletes all repetitions from the `bag`. In your implementation, assume that items can be compared for equality using `==.`

Use the following header for the function:

```cpp
void remove_repetitions()
```

Here is a brief outline of an algorithm:

* A node pointer `p` steps through the bag
* For each Item, define a new pointer `q` equal to `p`
* While the `q` is not the last `Item` in the bag,
  * If the next `Item` has data equal to the data in `p`, remove the next `Item`.
  * Otherwise move `q` to the next Item in the bag.

#### 3. Test Program

Write a new test program to test the above two member functions.

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
