# qe - Library for Quantum Computing in C++

You need it fast? Welcome. 

Here we start gathering some useful classes and algorithms for computing quantum-info related things. 

- **Quantum Circuit**. Generation, iteration, depth-computation. 
- **Matrices**. Dense, fixed-size and dynamic matrices, manipulation, matrix views. 
- **Graphs**. Graph templates, local complementation, transformations. 
- **Binary**. $\mathbb{F}_2$ numbers, binary phases (mod 4). 
- **Pauli**. 


## Installation/Setup

The project uses CMake and can be built without any dependencies or integration into other projects. 
However, it can also be integrated as a submodule into another CMake-based project. 
This will prevent this library's `CMakeLists.txt` file to search for Catch2 (see below), to enable `USE_FOLDERS` and to remove the option for unit testing which will then need to be given by the top-level project. 


## Tests

This library features unit tests with [Catch2](https://github.com/catchorg/Catch2). 
The unit tests can be built by setting `UNIT_TESTING=ON` when running CMake or running CMake with the flag `-DUNIT_TESTING=ON`. 
Ensure that you have Catch2 installed and that it can be found in CMake by `find_package(Catch2 3 REQUIRED)`. 
If folders in the IDE are enabled, the tests are put into a folder named `Unit Tests`. 

When writing own unit tests,
- write one `.cpp` test file per library header file
- whose name is based on the header file and ends on `_tests`,
- pay attention to test every function and feature and
- put the test files into a directory named `tests` next to the libraries `src` directory.

In general, each source file should have a test file (except where similar files can be tested more easily in one unit).

## License

This repository is licensed under the [MIT License][license]

[repository]: https://github.com/Mc-Zen/qe
[license]: https://github.com/Mc-Zen/qe/blob/main/LICENSE.txt