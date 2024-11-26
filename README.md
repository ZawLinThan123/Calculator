# Scientific Calculator Project

## Overview
A sophisticated C++ scientific calculator that uses stack data structures and the Shunting Yard algorithm to evaluate complex mathematical expressions with proper operator precedence.

## Authors
- Lin Phone Pyae Han
- Zaw Lin Than

## Features

### Core Functionality
- Basic arithmetic operations (+, -, *, /, ^)
- Support for mathematical constants (pi, e)
- Parentheses support for complex expressions
- Operator precedence handling
- Error handling for divide by zero and invalid expressions
- Interactive command-line interface

### Technical Highlights
- Implements Shunting Yard algorithm for expression parsing
- Supports multi-digit and decimal number parsing
- Handles operator precedence:
    - Level 3: Exponentiation (^)
    - Level 2: Multiplication (*), Division (/)
    - Level 1: Addition (+), Subtraction (-)
- Proper handling of parentheses
- Comprehensive error checking

## Technical Implementation

### Key Methods
- `run()`: Main interactive calculator interface
- `translateToPostfix()`: Converts infix expressions to postfix notation
- `evaluateExpression()`: Processes and calculates expression results
- `calculate()`: Performs actual mathematical operations

### Data Structures
- `std::stack` for operator management
- `std::queue` for postfix expression processing
- Efficient memory management using STL containers

### Mathematical Constants
- π (pi): 3.14159265358979323846
- e: 2.71828182845904523536

### Error Handling

- Divide by zero protection
- Invalid expression detection
- Runtime error management

## Building and Running

### Prerequisites
- C++ compiler with C++11 support or higher
- Standard C++ libraries

### Compilation
```bash
g++ main.cpp -o calculator
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

## Development Status
- [x] Basic arithmetic operations
- [x] Expression parsing
- [x] Operator precedence
- [x] Error handling
- [ ] Advanced scientific functions
- [ ] Memory functionality

## Planned Enhancements
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
- References to stack data structure and Shunting Yard algorithm resources