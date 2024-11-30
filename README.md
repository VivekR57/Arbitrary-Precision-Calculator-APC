Arbitrary-Precision Calculator (APC)

Introduction:
Arbitrary-precision arithmetic, also known as big-num or infinite-precision arithmetic, enables calculations on numbers with precision limited only by the system's memory. Unlike fixed-precision arithmetic (typically 8 to 64 bits), arbitrary-precision arithmetic is used in fields like cryptography and computing constants such as π to millions of digits. This project implements a calculator in C that performs mathematical operations on large numbers using linked lists to store digits, making it capable of handling numbers of virtually unlimited size.

Project Goal:
The goal is to implement basic arithmetic operations (addition, subtraction, multiplication, division, modulus, and exponentiation) on arbitrary-precision numbers. The calculator uses an Abstract Data Type (ADT) implemented as a linked list to store digits of large numbers and perform operations.

Operations:

Addition (+)
Subtraction (-)
Multiplication (*)
Division (/)
Modulus (%)
Exponentiation (^)
Each operation slices large numbers into chunks and stores them across different nodes in a linked list. The result of the operation is stored in a new linked list, and the output is printed.

User Interface:

Run the application by executing ./apc.
Input example: 1234567890121234518775261672673+718625634152778367635544816.
Output: The program calculates and displays the result.
