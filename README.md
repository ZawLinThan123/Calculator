# Scientific Calculator Project

## Overview
A comprehensive C++ scientific calculator implementation with support for basic arithmetic operations, scientific functions, and complex mathematical expressions. The project demonstrates different data structure implementations (Stack and Doubly Linked List) for expression evaluation.

## Authors
- Lin Phone Pyae Han
- Zaw Lin Than

## Features

### Core Functionality
- Basic arithmetic operations (+, -, *, /, ^)
- Parentheses support for complex expressions
- Operator precedence handling
- Error handling and input validation

### Implementation Variants
1. Stack-based Implementation
    - Uses standard C++ stack for expression evaluation
    - Implements Shunting Yard algorithm for operator precedence
    - Efficient memory management using STL containers

2. Doubly Linked List Implementation
    - Custom doubly linked list data structure
    - Manual memory management
    - Bidirectional traversal capability
    - Flexible for modifications and extensions

## Technical Details

### Data Structures
1. Stack Version
    - Uses `std::stack` for operators and values
    - LIFO (Last In First Out) principle
    - Automatic memory management

2. Doubly Linked List Version
    - Custom `Node` structure
    - `DoublyLinkedList` template class
    - Manual memory management
    - Bidirectional node linking

### Algorithms
- Shunting Yard Algorithm for expression parsing
- Operator precedence handling
- Expression validation
- Error detection and handling

## Building and Running

### Prerequisites
- C++ compiler with C++11 support or higher
- Standard C++ libraries

### Compilation
```bash
# For Stack implementation
g++ calculator_stack.cpp -o calculator_stack

# For Doubly Linked List implementation
g++ calculator_dll.cpp -o calculator_dll
```

### Running the Program
```bash
./calculator_stack
# or
./calculator_dll
```

## Usage Examples
```cpp
// Basic arithmetic
Input: 2 + 3 * 4
Output: 14

// Expression with parentheses
Input: (2 + 3) * 4
Output: 20

// Complex expressions
Input: 2 * 3 + 4 * 5
Output: 26
```

## Current Development Status
- [x] Basic arithmetic operations
- [x] Expression parsing
- [x] Stack implementation
- [x] Doubly Linked List implementation
- [ ] Scientific functions (sin, cos, tan)
- [ ] Memory functions
- [ ] GUI interface
- [ ] Unit testing

## Future Enhancements
1. Additional Scientific Functions
    - Trigonometric functions
    - Logarithmic functions
    - Square root and power functions

2. User Interface Improvements
    - GUI implementation
    - Better error messages
    - Input validation

3. Additional Features
    - Memory functions (M+, M-, MR, MC)
    - History of calculations
    - Unit conversions
    - Different number systems (binary, hex)

## Contributing
This is an ongoing project by Lin Phone Pyae Han and Zaw Lin Than. If you'd like to contribute or have suggestions, please contact the authors.

## License
This project is currently under development and all rights are reserved to the authors.

## Contact
- Lin Phone Pyae Han
- Zaw Lin Than

## Acknowledgments
- Thanks to our instructors and mentors
- References to data structure and algorithm resources used in the project