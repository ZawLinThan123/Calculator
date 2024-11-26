//
// Created by Zaw Lin Than on 11/24/24.
//

#pragma once

#include <stack>
#include <queue>
#include <cmath> // CLion said math.h is deprecated and suggested to use cmath instead
#include <string>
#include <iostream>
#include <stdexcept>

class ScientificCalculator {
public:
    void run() {
        std::string input;
        bool running = true;

        std::cout << "\nScientific Calculator\n";
        std::cout << "====================\n";
        std::cout << "Available operations:\n";
        std::cout << "1. Basic arithmetic (+, -, *, /, ^)\n";
        std::cout << "2. Constants: pi, e\n";
        std::cout << "Enter 'q' to quit\n\n";

        while (running) {
            try {
                std::cout << "\nEnter expression or command: ";
                getline(std::cin, input);

                if (input == "q" || input == "Q") {
                    running = false;
                    continue;
                }

                // Replace constants with their values
                size_t pos;
                while ((pos = input.find("pi")) != std::string::npos) {
                    input.replace(pos, 2, std::to_string(PI));
                }
                while ((pos = input.find("e")) != std::string::npos) {
                    input.replace(pos, 1, std::to_string(E));
                }

                // Evaluate regular expression
                double result = evaluateExpression(input);
                std::cout << "Result: " << result << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }

private:
    const double PI = 3.14159265358979323846;
    const double E = 2.71828182845904523536;

    // Check if the character is an operator
    static bool isOperator(const char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Get operator precedence
    static int getPrecedence(const char op) {
        if (op == '^') {
            return 3;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        if (op == '+' || op == '-') {
            return 1;
        }
        return 0;
    }

    static double calculate(const double a, const double b, const char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0) {
                    throw std::runtime_error("Divide by zero");
                }
                return a / b;
            case '^':
                return pow(a, b);
            default:
                throw std::runtime_error("Invalid operator");
        }
    }

    static std::queue<std::string> translateToPostfix(const std::string& expression) {
        std::stack<char> operations;
        std::queue<std::string> values;

        for (size_t i = 0; i < expression.length(); ++i) {
            if (expression[i] == ' ') {
                continue;
            }

            if (isdigit(expression[i]) || expression[i] == '.') {
                // Handle multi-digit numbers and decimals
                std::string num;
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
                {
                    num += expression[i++];
                }
                --i; // Adjust for extra increment in the loop
                values.push(num);
            }

            else if (expression[i] == '(')
            {
                operations.push(expression[i]);
            }

            else if (expression[i] == ')') {
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

            else if (isOperator(expression[i]))
            {
                while (!operations.empty() && getPrecedence(operations.top()) >= getPrecedence(expression[i]))
                {
                    values.push(std::string(1, operations.top()));
                    operations.pop();
                }
                operations.push(expression[i]);
            }
        }

        // Pop remaining operators from the stack
        while (!operations.empty()) {
            values.push(std::string(1, operations.top()));
            operations.pop();
        }

        return values;
    }

    static double evaluateExpression(const std::string& expression)
    {
        std::queue<std::string> postfixQueue = translateToPostfix(expression);
        double result;
        std::stack<double> postfixStack;

        while (!postfixQueue.empty())
        {
            if (isOperator(postfixQueue.front()[0]))
            {
                if (postfixStack.size() < 2)
                {
                    throw std::runtime_error("Error: The expression is not a valid expression!");
                }
                double second = postfixStack.top(); postfixStack.pop();
                double first = postfixStack.top(); postfixStack.pop();
                result = calculate(first, second, postfixQueue.front()[0]);
                postfixQueue.pop();
                postfixStack.push(result);
            }
            else
            {
                postfixStack.push(std::stod(postfixQueue.front()));
                postfixQueue.pop();
            }
        }

        return result;
    }
};
