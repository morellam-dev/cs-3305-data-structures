# cs-3305-data-structures

Code written for CS 3305 - Data Structures in C++

## Disclaimer

This repository contains solutions to school-assigned homework and lab assignments, and should be used only for reference and educational purposes. Plagiarism or uncredited copying of code is in violation of the College of Computing's policy, and is discouraged.

## Execution

These programs were originally written to be compiled individually through an interactive terminal, specifically using g++-10. However, for convenience, I have created an extremely naive makefile which compiles every module into a separate executable in the `out` directory.

```sh
bash$ make
# ... make output ...
bash$ ls out/
# ... list of executables ...
bash$ ./out/1_2_pyramid
8 6 4 2 0
6 4 2 0
4 2 0
2 0
0

$ make clean
rm -r ./out/
```
