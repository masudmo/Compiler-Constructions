# compilerBauSystem
All homework solutions:
 • must be implemented in C* in the selfie.c file,
 • must compile without warnings with starc and execute with mipster on travis,
 • must not break any existing selfie functionality,
 • must be ready for presentation on your machine in class, and
 • must include a short .md or .txt file that explains *what* was done, *why* it was done that way, and *any problems* encountered (no code pasting here).

*Assignment #0:*
1. create a student github account with your e-address (@stud.sbg.ac.at), you will receive a collaboration request and have your selfie’s private repository.
2. edit `selfie.c` such that your name is output as `This is Firstname Lastname's Selfie`
3. push your changes to github
4. *bonus:* create a test folder with some cstar examples to challenge your selfie skills.

*Assignment #1:*
Deadline: Wednesday, March 21, 6 pm.
1. Create a branch named `hw1` based on your `master` branch.
2. Implement in *mipster* the two logical bitwise shift instructions of RISC-V called `sll`, and `srl` according to the RISC-V standard. Use the selfie library functions for bitwise shifting and the selfie interface functions for decoding to implement these new instructions.
3. Make sure that the selfie disassembler and debugger produce proper output for these instructions. The binary test file `shiftTest.m` is given as example and should exit with value 0.
4. Replace your `Makefile` and `.travis.yml`with the next given files (to speed up travis build).
5. Push your changes into github and make sure they build on travis-ci.

Assignment #2:
Deadline: Wednesday, April 11, 6 pm.
*Scanning, parsing, and code generation for `<<` and `>>` operators:*
1. Create a branch named `hw2` based on `hw1`.
2. Implement in `starc` the two bitwise operators of C mentioned above by extending the scanner and parser of `starc` accordingly.
• Add unique tokens for the new symbols `<<` and `>>` and extend the scanner in such a way that `starc` recognises them. Make sure that the scanner properly distinguishes `<` from `<<` and `>` from `>>`.
• Add a new production rule for the new symbols to the C* grammar (in the *grammar.md* file) such that their precedence is between `+` and `<` as specified for C operators.
• Add a procedure for parsing the new symbols to `starc` according to the new production rule (*hint:* use a copy of the procedure for parsing simple expressions as template).
• Test your implementation on syntactically correct as well as syntactically incorrect C* programs using the new operators.
3. Implement in `starc` the code generation for the new operators `<<` and `>>`.
• Use the logical bitwise shift instructions of *Assignment#1*.
• Avoid using `*`, `/` and `twoToThePowerOf` procedure for left and right shifts.
4. `Makefile` is same as `hw1` (It has to be exactly the same).
5. Push your changes into github and make sure they build on travis-ci.
*bonus:* Replace all uses of `leftShift` and `rightShift` procedures in `selfie.c` with `<<` and `>>` operators. This means that instead of using `leftShift(n, b)` you have to use `n << b` in all occurrences (in particular in the implementation of the RISC-U shift instructions) respectively `rightShift(n, b)` and `n >> b`.

Assignment #3:
Deadline: Wednesday, May 2, 6 pm.
*Multi-dimensional arrays:*
1. Create a branch named `hw3` based on `hw2`.
2. Extend the C* grammar.
• Define the rule `selector = { "[" simpleExpression "]" } .` for array managements.
• Add `selector` non-terminal at the right place in `cstar`, `statement`, `variable` and `factor` rules to handle array declaration and access.
3. Implement parsing and code generation.
 • In array declarations, the size of each dimension should be a constant.
 • In array accesses, the correct address should be computed.
 • Make sure assignments into arrays are supported, e.g. `a[i] = x;`.
4. Modify selfie such that
 • the `power_of_two_table` variable is declared and accessed as a one-dimensional array of integers.
 • the `REGISTERS` variable is declared and accessed as a two-dimensional array. The first dimension should contain abbreviated name as they are in the code and second dimension should contain the complete name of each register. For example, `REGISTERS[ABBR][REG_AT] = (uint64_t) "$at"` and `REGISTERS[NAME][REG_AT] = (uint64_t) "assembler temporary"` where `ABBR = 0` and `NAME = 1`. _ps: to find out the full name of registers, google it._
5. Push your changes to github and make sure they build on travis-ci.
*bonus*: handle array initialisation values.


Milestone#3.1:
Deadline: Wednesday, April 25, 6 pm.
*Arrays:*
1. Create a branch named `hw3` based on `hw2`.
2. Extend the C* grammar.
 • Define the rule `selector = { "[" simpleExpression "]" } .` for array managements.
 • Add `selector` non-terminal at the right place in `cstar`, `statement`, and `factor` rules to handle array declaration and access.
3. Implement parsing and code generation.
 • In array declarations, the size of *the* dimension should be a constant.
 • In array accesses, the correct address should be computed.
 • Make sure assignments into arrays are supported, e.g. `a[i] = x;`.
4. Modify selfie such that
 • the `power_of_two_table` variable is declared and accessed as a one-dimensional array of integers.
5. Push your changes to github and make sure they build on travis-ci.
*bonus*: handle array initialisation values.


Homework Assignment 4:
_Deadline_:   Wednesday, May 16, 6 pm.
_Milestone_: 1) 2) 3) Wednesday, May 9, 6 pm.
*Structures:*
1. Create a branch named `hw4` based on `hw3`.
2. Extend the C* grammar with structures.
3. Implement `struct` definitions.
4. Implement global and local declarations of type pointer to `struct` and `struct` accesses (`->` operator).
5. Make sure that array of struct is working.
6. Modify selfie such that
 • the `symbol_table` variable is declared and accessed as a `struct`.
7. Push your changes to github and make sure they build on travis-ci.


Assignment 5:
_Deadline_:   Wednesday, May 30, 6 pm.
_Milestone_: 1) 2) 3) Wednesday, May 23, 6 pm.
*For loop:*
1. Create a branch named `hw5` based on `hw4`.
2. Extend and complete the C* grammar with `for` statement with the rule:
for = "for" "(" assignment ";" expression ";" assignment ")" ( statement | "{" { statement } "}" ).
We assume that the header assignments do not declare new variables.
3. Implement the `for` loop parsing.
4. Implement code generation.
5. Make sure that for loop statement is working by initialising the `power_of_two_table` using such a loop.
6. Push your changes to github and make sure they build on travis-ci.


Project topics:
_Deadline:_ Friday, July 13th:
 • 1) String management as `char*` data type.
 • 2) Logical operators with `lazy` evaluation.
 • 3) `Printf` and variable parameters length.
 • 4) Local variables initialisation.
 • 5) `Spike` support.
   a) back-end risc-v
   b) binary translator
 • 6)  `x86` support.
 • 7) `WebAssembly` support.
