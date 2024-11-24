//
// Created by Zaw Lin Than on 11/24/24.
//

#pragma once

#include <stack>
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

    // Check if token is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    // Get operator precedence
    int getPrecedence(char op) {
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

    double calculate(double a, double b, char op) {
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

    double evaluateExpression(std::string expr) {
        std::stack<double> values;
        std::stack<char> ops;

        for (size_t i = 0; i < expr.length(); i++) {
            if (expr[i] == ' ') {
                continue;
            }

            // Handle numbers
            if (isdigit(expr[i]) || expr[i] == '.') {
                std::string num;
                while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                    num += expr[i++];
                }
                i--;
                values.push(stod(num));
            }

            // Handle parentheses
            else if (expr[i] == '(') {
                ops.push(expr[i]);
            }
            else if (expr[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    double b = values.top();
                    values.pop();
                    double a = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(calculate(a, b, op));
                }
                if (!ops.empty()) {
                    ops.pop();
                }
            }

            else if (isOperator(expr[i])) {
                while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(expr[i])) {
                    double b = values.top();
                    values.pop();
                    double a = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(calculate(a, b, op));
                }
                ops.push(expr[i]);
            }
        }

        while (!ops.empty()) {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(calculate(a, b, op));
        }

        return values.top();
    }
};
