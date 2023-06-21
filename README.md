# Monty Bytecode Interpreter

This repository contains a Monty bytecode interpreter written in the C programming language. The interpreter can read and execute Monty bytecode files, which contain a series of opcodes that manipulate a stack data structure.

The interpreter supports a variety of opcodes, including `push`, `pint`, `pop`, `swap`... each opcode performs a specific operation on the stack, such as pushing a new element onto the stack, printing the top element of the stack, or adding the top two elements of the stack.

The interpreter is designed to be robust and handle various edge cases, such as empty stacks and division by zero. It prints informative error messages and exits with the appropriate status code when it encounters an error.

To use the interpreter, compile the source code and run the resulting executable with the name of a Monty bytecode file as an argument. The interpreter will read and execute the opcodes in the bytecode file, manipulating the stack and printing output as specified by the opcodes.

This project was created as part of the ALX curriculum.
