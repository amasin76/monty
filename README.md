# Monty Bytecode Interpreter

This repository contains a Monty bytecode interpreter written in the C programming language. The interpreter can read and execute Monty bytecode files, which contain a series of opcodes that manipulate a stack data structure.

The interpreter supports a variety of opcodes, including `push`, `pint`, `pop`, `swap`... each opcode performs a specific operation on the stack, such as pushing a new element onto the stack, printing the top element of the stack, or adding the top two elements of the stack.

The interpreter is designed to be robust and handle various edge cases, such as empty stacks and division by zero. It prints informative error messages and exits with the appropriate status code when it encounters an error.

## usage
1- compile
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
2- run
```bash
./monty <file>
```

This project was created as part of the ALX curriculum.
