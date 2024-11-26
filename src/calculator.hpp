// Copyright (c) 2024 Lin Phone Pyae Han & Zaw Lin Than. All rights reserved

#pragma once

#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>

// ScientificCalculator: A class that implements a command-line scientific calculator
// Supports basic arithmetic operations, constants, and expression evaluation
class ScientificCalculator {
public:
    // Main run method to start the calculator interface
    // Handles user input, expression parsing, and calculation
    void run() const {
        std::string input;
        bool running = true;

        // Display calculator introduction and available operations
        std::cout << "\nScientific Calculator\n";
        std::cout << "====================\n";
        std::cout << "Available operations:\n";
        std::cout << "1. Basic arithmetic (+, -, *, /, ^)\n";
        std::cout << "2. Constants: pi, e\n";
        std::cout << "Enter 'q' to quit\n\n";

        while (running) {
            try {
                // Prompt for user input
                std::cout << "\nEnter expression or command: ";
                getline(std::cin, input);

                // Check for quit command
                if (input == "q" || input == "Q") {
                    running = false;
                    continue;
                }

                // Replace mathematical constants with their numeric values
                size_t pos;
                while ((pos = input.find("pi")) != std::string::npos) {
                    input.replace(pos, 2, std::to_string(PI));
                }
                while ((pos = input.find('e')) != std::string::npos) {
                    input.replace(pos, 1, std::to_string(E));
                }

                // Evaluate the input expression and display the result
                double result = evaluateExpression(input);
                std::cout << "Result: " << result << std::endl;
            }
            catch (const std::exception& e) {
                // Handle and display any errors during calculation
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }

private:
    // Mathematical constants
    const double PI = 3.14159265358979323846;
    const double E = 2.71828182845904523536;

    // Check if a character is a valid mathematical operator
    // Supports addition, subtraction, multiplication, division, and exponentiation
    static bool isOperator(const char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Determine the precedence of mathematical operators
    // Higher precedence means the operator is evaluated first
    // ^ (exponentiation) has the highest precedence
    // * and / have medium precedence
    // + and - have the lowest precedence
    static int getPrecedence(const char op)
    {
        if (op == '^')
        {
            return 3;
        }
        if (op == '*' || op == '/')
        {
            return 2;
        }
        if (op == '+' || op == '-')
        {
            return 1;
        }

        return 0;
    }

    // Perform calculation based on the given operator
    // Supports addition, subtraction, multiplication, division, and exponentiation
    // Includes error handling for division by zero
    static double calculate(const double a, const double b, const char op)
    {
        switch (op)
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0)
                {
                    throw std::runtime_error("Divide by zero");
                }
                return a / b;
            case '^':
                return pow(a, b);
            default:
                throw std::runtime_error("Invalid operator");
        }
    }

    // Convert infix expression to postfix notation (Shunting Yard algorithm)
    // This allows for proper handling of operator precedence and parentheses
    static std::queue<std::string> translateToPostfix(const std::string& expression) {
        std::stack<char> operations;
        std::queue<std::string> values;

        for (size_t i = 0; i < expression.length(); ++i)
        {
            // Skip whitespace
            if (expression[i] == ' ')
            {
                continue;
            }

            // Handle multi-digit numbers and decimal numbers
            if (isdigit(expression[i]) || expression[i] == '.')
            {
                std::string num;
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
                {
                    num += expression[i++];
                }
                --i; // Adjust for extra increment in the loop
                values.push(num);
            }

            // Handle opening parenthesis
            else if (expression[i] == '(')
            {
                operations.push(expression[i]);
            }

            // Handle closing parenthesis
            // Pop operators until matching opening parenthesis is found
            else if (expression[i] == ')')
            {
                while (!operations.empty() && operations.top() != '(')
                {
                    values.push(std::string(1, operations.top()));
                    operations.pop();
                }

                if (!operations.empty())
                {
                    operations.pop(); // Remove '('
                }
            }

            // Handle operators with precedence rules
            else if (isOperator(expression[i]))
            {
                // Pop operators with higher or equal precedence
                while (!operations.empty() && getPrecedence(operations.top()) >= getPrecedence(expression[i]))
                {
                    values.push(std::string(1, operations.top()));
                    operations.pop();
                }
                operations.push(expression[i]);
            }
        }

        // Pop remaining operators from the stack
        while (!operations.empty())
        {
            values.push(std::string(1, operations.top()));
            operations.pop();
        }

        return values;
    }

    // Evaluate a mathematical expression using postfix notation
    // Supports complex expressions with multiple operators and parentheses
    static double evaluateExpression(const std::string& expression)
    {
        // Convert infix expression to postfix
        std::queue<std::string> postfixQueue = translateToPostfix(expression);
        double result;
        std::stack<double> postfixStack;

        // Process postfix expression
        while (!postfixQueue.empty())
        {
            // If current token is an operator
            if (isOperator(postfixQueue.front()[0]))
            {
                // Ensure enough operands are available
                if (postfixStack.size() < 2)
                {
                    throw std::runtime_error("Invalid expression");
                }
                // Pop two operands and perform calculation
                double second = postfixStack.top(); postfixStack.pop();
                double first = postfixStack.top(); postfixStack.pop();
                result = calculate(first, second, postfixQueue.front()[0]);
                postfixQueue.pop();
                postfixStack.push(result);
            }
            else
            {
                // If token is a number, push to stack
                postfixStack.push(std::stod(postfixQueue.front()));
                postfixQueue.pop();
            }
        }

        return result;
    }
};