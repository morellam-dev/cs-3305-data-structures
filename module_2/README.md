# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 2

## Objectives

The goal of assignment is to reinforce the beginning C++ concepts and efficiency of algorithms
concepts, and to reinforce the implementation of Object Oriented concepts in C++.

## Requirements

1. For each of the following code fragments, give an analysis of the running time (Big-Oh notation) (1 points each total 5 points)

**a.**

```cpp
sum = 0;
for (int i = 0; i < n; i++)
  sum++;
```

**b.**

```cpp
sum = 0;
for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    sum++;
```

**c.**

```cpp
sum = 0;
for (int i = 0; i < n; i++)
  for (int j = 0; j < n * n; j++)
    sum++;
```

**d.**

```cpp
sum = 0;
for(int i = 0; i < n; i++)
  for(int j = 0; j < i; j++)
    sum++;
```

**e.**

```cpp
sum = 0;
for(int i = 0; i < n; i++)
  for(int j = 0; j < i * i; j++)
    for(int k = 0; k < j; k++)
      sum++;
```

1. **(Programming)** Construct a class that will model a bank account. A bank account will know the balance and the owner of the account. In addition to creating a bank account, money can be deposited in the account, withdrawn from the account, the owner can be changed, the account can be queried to find the current balance, and it can be queried to find the current owner. Also construct a test program which will test whether your implementation of this class is correct. (5 points)

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
