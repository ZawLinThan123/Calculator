# Scientific Calculator Project

## Overview
A comprehensive C++ scientific calculator implementation that uses stack data structure for evaluating mathematical expressions. The calculator handles basic arithmetic operations and complex expressions.

## Authors
- Lin Phone Pyae Han
- Zaw Lin Than

## Features

### Core Functionality
- Basic arithmetic operations (+, -, *, /, ^)
- Parentheses support for complex expressions
- Operator precedence handling using stack
- Error handling and input validation
- Expression evaluation using Shunting Yard algorithm

### Technical Implementation
- Uses two stacks:
    - Number stack for operands
    - Operator stack for operations
- Implements operator precedence:
    - Level 3: Power (^)
    - Level 2: Multiplication (*), Division (/)
    - Level 1: Addition (+), Subtraction (-)
- Proper handling of parentheses
- Comprehensive error checking

## Technical Details

### Data Structures
- `std::stack` for operators and values
- LIFO (Last In First Out) principle for expression evaluation
- Efficient memory management using STL containers

### Algorithm
The calculator uses the Shunting Yard algorithm to handle operator precedence:
1. Scan expression from left to right
2. If number: push to number stack
3. If operator: compare precedence with top of operator stack
    - Higher precedence: push to operator stack
    - Lower/equal precedence: evaluate operators in stack first
4. If opening parenthesis: push to operator stack
5. If closing parenthesis: evaluate until matching opening parenthesis

## Building and Running

### Prerequisites
- C++ compiler with C++11 support or higher
- Standard C++ libraries

### Compilation
```bash
g++ calculator.cpp -o calculator
```

### Running the Program
```bash
./calculator
```

## Usage Examples
```cpp
// Basic arithmetic
Input: 2 + 3 * 4
Output: 14

// Expression with parentheses
Input: (2 + 3) * 4
Output: 20

// Power operation
Input: 2 ^ 3 + 1
Output: 9
```

## Current Development Status
- [x] Basic arithmetic operations
- [x] Expression parsing with Shunting Yard algorithm
- [x] Stack-based implementation
- [x] Operator precedence handling
- [x] Parentheses support
- [ ] Scientific functions (sin, cos, tan)
- [ ] Memory functions
- [ ] Error history logging

## Future Enhancements
1. Scientific Functions
    - Trigonometric functions
    - Logarithmic functions
    - Square root and power functions

2. Calculator Features
    - Memory functions (M+, M-, MR, MC)
    - History of calculations
    - Better error messages
    - Input validation improvements

## Contributing
This is an ongoing project by Lin Phone Pyae Han and Zaw Lin Than. If you'd like to contribute or have suggestions, please contact the authors.

## License
This project is currently under development and all rights are reserved to the authors.

## Contact
- Lin Phone Pyae Han
- Zaw Lin Than

## Acknowledgments
- Thanks to our instructors and mentors