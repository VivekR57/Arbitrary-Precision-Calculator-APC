# 🧮 Arbitrary Precision Calculator

The **Arbitrary Precision Calculator** is a **C-based** application designed to perform arithmetic operations on extremely large numbers that exceed the capacity of standard data types. The calculator implements a custom **doubly linked list** data structure to handle numbers of virtually unlimited size, supporting **addition**, **subtraction**, **multiplication**, and **division** operations with full sign handling.

---

## 🛠 Project Features

- **Arbitrary Precision:** Supports numbers with virtually unlimited digits, constrained only by system memory.
- **Arithmetic Operations:** Implements **addition**, **subtraction**, **multiplication**, and **division** for large numbers.
- **Custom Data Structure:** Uses a **doubly linked list**, with each node storing up to **4 digits** for efficiency.
- **Sign Handling:** Manages positive and negative numbers with appropriate arithmetic rules.
- **Error Handling:** Detects division by zero, input validation errors, and memory allocation failures.
- **Command-Line Interface:** Accepts input via **CLI** with validation and formatted output.

---

## 🧰 Technology Stack

- **Programming Language:** C
- **Data Structure:** Doubly Linked List
- **Input/Output:** Command-Line Interface
- **Memory Management:** Dynamic allocation for linked list nodes
- **Error Handling:** Validation and descriptive error messages

---

## 🔄 Project Workflow

1. **Input Validation:**
   - Checks for correct argument count.
   - Validates the arithmetic operator and numerical inputs.

2. **Number Representation:**
   - Converts input strings into a **doubly linked list** representation.
   - Splits numbers into chunks of **4 digits** per node.

3. **Operation Execution:**
   - Selects the appropriate arithmetic function based on the operator.
   - Handles sign logic for operations with different sign inputs.

4. **Result Display:**
   - Formats the output with correct sign and digit placement.
   - Prints the result in a human-readable format.

5. **Memory Cleanup:**
   - Frees all dynamically allocated memory to prevent leaks.

---

## 📂 File Structure

- `header.h` - Central header file with structure definitions and function prototypes.
- `calculator.c` - Main program file with operation selection logic.
- `addition.c` - Implements **addition** of large numbers.
- `subtraction.c` - Implements **subtraction** with sign and magnitude handling.
- `multiplication.c` - Uses the **long multiplication** algorithm for large numbers.
- `division.c` - Implements **long division**, including sign and edge case management.
- `create_list.c` - Functions to create and manipulate linked lists.
- `read_and_validation.c` - Handles input validation and parsing.

---

## 🚀 Future Enhancements

- **Floating-Point Support:** Extend functionality to handle **decimal precision**.
- **Additional Operations:** Implement **exponentiation**, **square roots**, and **modulus**.
- **Mathematical Expressions:** Add support for expressions with **operator precedence**.
- **Performance Optimizations:** Implement advanced algorithms like **Karatsuba** for multiplication.
- **User Interface:** Create an **interactive CLI** or **graphical UI** for better usability.
- **Memory Efficiency:** Introduce caching and **multi-threading** for large-scale calculations.

---

## 📧 Contact

For any questions, feel free to reach out:

- **Vivek**
- Email: [gopivivek57@gmail.com](mailto:gopivivek57@gmail.com)
- LinkedIn: [Vivek](https://www.linkedin.com/in/vivek57/)
