Instructions
------------------
See `asn1.pdf` for the instructions for the assignment.

Key Files
------------------
These are the key files for the first assignment of CPSC 2720.

`lib/` - contains the static libraries that you will test in this assignment:
   * `libshapes-bugs.a` - a static library containing the implementation of the classes that you will be testing in this assignment.
   * `libshapes-clean.a` - a static library containing bug-free implementation of the classes for checking that your unit tests are correct.

`include/` - contains the header files for the classes that you will test.

`test/` - contains the test runner and an example test suite to get you started.

`Makefile` - A Makefile for:
   * Creating executables that use either the "clean" or "buggy" libraries.
   * Running static analysis.
   * Running style analysis.
   * Checking for memory leaks.


Running Tests
----------------
To run the tests, execute the following:

`./tests_clean` (runs the tests with the 'clean' library)

`./tests_bugs` (runs the tests with the 'buggy' library)

The provided test suite will fail and you will see the following output:

```
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TestQuadrilateral
[ RUN      ] TestCoord.output
test/TestQuadrilateral.cpp:10: Failure
Failed
[  FAILED  ] TestQuadrilateral.output (0 ms)
[----------] 1 test from TestQuadrilateral (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 0 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] TestQuadrilateral.output

 1 FAILED TEST
```

Where to go from here
----------------
From here, you will create test suites and unit tests to test the provided libraries. 
The 'buggy' library contains bugs, so not all of your unit tests should pass.