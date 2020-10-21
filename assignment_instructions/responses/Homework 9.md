# CS 3305 Data Structures

## Homework Assignment 9

M Morella

### Screenshot

![Screenshot of main.cpp executing](https://i.imgur.com/sn48iET.png)

### **main.cpp**

```cpp
#include <cmath>     // for std::max
#include <iostream>  // for std::cout
#include <cassert>   // for assert

// ..
```
The rest of main.cpp is unchanged, except the function implementations detailed below.

#### 1. `depth` function

```cpp
// Returns the maximum of the depths of the left and right subtrees,
template <class T>
int depth(binary_tree_node<T> *root) {
  if (!root) {
    return -1;
  }
  int left_depth = depth(root->left());
  int right_depth = depth(root->right());
  return 1 + std::max(left_depth, right_depth);
}
```

#### 2. `max` function

```cpp
// Returns the largest value in the tree
template <class T>
T max(binary_tree_node<T> *root) {
  assert(root != NULL);
  T result = root->data();
  if (root->left()) {
    const T left_max = max(root->left());
    result = std::max(result, left_max);
  }
  if (root->right()) {
    T right_max = max(root->right());
    result = std::max(result, right_max);
  }
  return result;
}
```

#### 3. `tree_sum` function

```cpp
// returns the sum of the values in all the nodes in the tree
double tree_sum(binary_tree_node<double> *root) {
  if (!root) {
    return 0;
  }
  double l_sum = tree_sum(root->left());
  double r_sum = tree_sum(root->right());
  return root->data() + l_sum + r_sum;
}
```

#### 4. `tree_average` function

```cpp
// returns the average of the values in all the nodes in the tree
double tree_average(binary_tree_node<double> *root) {
  return tree_sum(root) / tree_size(root);
}
```

#### 5. `tree_is_balanced` function

```cpp
// returns whether the tree is balanced
// i.e. the depth of each subtree differs by at most 1, and each subtree is balanced
template <class T>
bool tree_is_balanced(binary_tree_node<T> *root) {
  if (!root || root->is_leaf()) {
    return true;
  }
  int left_depth = depth(root->left());
  int right_depth = depth(root->right());
  if (std::abs(left_depth - right_depth) > 1) {
    return false;
  }
  return tree_is_balanced(root->left()) && tree_is_balanced(root->right());
}
```

### Output

Output is consistent with the test results given in the assignment instructions.

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

sum of s3: 12.9191
average of s3: 0.226651
size of s3: 57
sum of b1: 11018.4
average of b1: 47.493
size of b1: 232
sum of b2: 29775
average of b2: 48.8917
size of b2: 609

s1 is balanced? 1
s2 is balanced? 1
s3 is balanced? 0
s4 is balanced? 0
s5 is balanced? 1
b1 is balanced? 1
b2 is balanced? 1
```
