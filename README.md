# cs-3305-data-structures

Code written for CS 3305 - Data Structures in C++

## Disclaimer

This repository contains solutions to school-assigned homework and lab assignments, and should be used only for reference and educational purposes. Plagiarism or uncredited copying of code is in violation of the College of Computing's policy, and is discouraged.

## Execution

Run `make` to build the makefile in each project directory. By default, all binaries will use the `.out` extension, which is ignored by this repository, and easy to erase.

Modules which only generate one binary will generate a `main.out`. Otherwise, they will be named descriptively.

```sh
cs-3305/module_1$ make CXX="g++-10"
# g++ -Wall -o about_me.out ex_01.cpp
# g++ -Wall -o pyramid.out ex_02.cpp
cs-3305/module_1$ ls *.out
# about_me.out  pyramid.out
cs-3305/module_1$ ./pyramid.out
# 8 6 4 2 0
# 6 4 2 0
# 4 2 0
# 2 0
# 0
$ rm **.out
# clean up all .out files.
```

### macOS Compilation Note

Xcode Developer Tools ship with `clang++` installed as `g++`. Installing the GNU compiler collection through Homebrew installs version 10 of g++ as `/usr/local/bin/g++-10` to avoid conflicts.

In future versions, you may need to call g++-11 or later.

```sh
$ brew install gcc
# installs g++-10 and gcc-10 to /usr/local/bin/
$ /usr/bin/g++ --version
# Apple clang version 12.0.0 (clang-1200.0.32.2)
$ /usr/local/bin/g++-10 --version
# g++-10 (Homebrew GCC 10.2.0) 10.2.0
```