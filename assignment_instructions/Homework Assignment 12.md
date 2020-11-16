# CS 3305 Data Structures

Instructor: Seokjun Lee

## Homework Assignment 12

The purpose of this lab is to help reinforce sorting algorithms implementations in C++.
You need download Sorting project from course website.

### Requirements

1. **Merge Sort: Do the programming problems 6 on page 681 of the text.**

   On page 651, we discussed problems with the dynamic memory usage of mergesort. One solution to the problem is to rewrite the
mergesort according to the following specification:

   ```cpp
   void mergesort(int data[], size_t first_index, size_t last_index, int temp[]);
   // Precondition: data[first_index] through
   // data[last_index] are array elements in no
   // particular order. The temp array has
   // locations temp[first_index] through
   // temp[last_index].
   // Postcondition: The elements
   // data[first_index] through data[last_index]
   // have been rearranged so that they are
   // ordered from smallest to largest. The array
   // elements temp[first_index] through
   // temp[last_index] have been used as
   // temporary storage and now contain a
   // copy of data[first_index] through
   // data[last_index].
   ```

1. **Do the programming problem 13 on page 682 of the text.
   Write testing program to test the implemented functions**

   In 1959, the American computer scientist Donald Shell invented a technique that can be used to speed up many different sorting algorithms. For this project, you will apply Shell’s method to insertion sort.

   The basis of the technique is to get the items to move in big steps (rather than shifting elements to the next-higher index). These big-step shifts are done early in the algorithm, and they tend to put the array in nearly sorted order. Later in the algorithm, we use smaller steps (all the way down to steps of size one, just like an ordinary insertionsort). But by the time that the small steps are being taken, the array is nearly sorted, and that’s a situation where insertionsort is efficient.

   The choice of the various step sizes affects the performance of the algorithm, but one sequence that is empirically good starts at n/2, and each subsequent step size is about the previous size divided by 2.2.

   The overall pseudocode is given here:

   1. LET ss = N/2;
   2. WHILE (ss > 0):
      a. Do an insertionsort on the elements `data[0]`, `data[ss]`, `data[2*ss]`...
      b. Also do an insertionsort on `data[1]`, `data[ss+1]`, `data[2*ss+1]`...
      c. And on `data[2]`, `data[ss+2]`, `data[2*ss+2]`...
      d. And so on. The last little insertionsort that you do starts at data[ss-1].
      e. SET `ss = ss/2.2`, rounded to nearest integer;

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
