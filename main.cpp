#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include <vector>

#include "tools.h"

// TODO: Add support for functions
// !(x) = Factorial of x
// etc.
//
// TODO: Add support for multi-digit numbers

std::vector<char> infix_to_postfix(std::vector<char> expr) {
    const std::map<char, int> precedence = {
        {'^', 4},
        {'*', 3},
        {'/', 3},
        {'+', 2},
        {'-', 2}
    };
    
    std::vector<char> op_stack = {};
    std::vector<char> out_queue = {};

    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (std::isalnum(c)) {
            // If it is alphanumeric, push it to the output
            out_queue.push_back(c);
        } else if (tools::map_contains(precedence, c)) {
            // If it is an operator

            // Pop operators from the stack to the output, if:
            // - The stack is not empty
            // - The operator has a greater precedence
            // - The operator is not '('
            while (
                !op_stack.empty()
                && op_stack.back() != '('
                && precedence.at(c) <= precedence.at(op_stack.back())
            ) {
                out_queue.push_back(op_stack.back());
                op_stack.pop_back();
            }
            // Add current operator to stack
            op_stack.push_back(c);
        } else if (c == '(') {
            // If it is a '(', add it to the stack
            op_stack.push_back(c);
        } else if (c == ')') {
            // If it is a ')'
            
            // Pop all operators to the stack until '('
            while (
                !op_stack.empty()
                && op_stack.back() != '('
            ) {
                out_queue.push_back(op_stack.back());
                op_stack.pop_back();
            }
            // If the stack is empty, then there were mismatched parentheses
            if (op_stack.empty()) {
                std::cout << "Error: mismatched parentheses" << std::endl;
                exit(1); // FIXME: Error should be handled better
            }
            op_stack.pop_back(); // Remove '('
        } else {
            // If it is none of the above conditions,
            // then it is invalid, ignore it
            std::cout << c << "is an invalid character. Ignoring" << std::endl;
        }
    }

    return out_queue;
}

int main() {
    std::vector<char> op_stack = {};
    std::vector<char> out_queue = {};

    std::string input;
    std::cout << "Input math expression: ";
    std::getline(std::cin, input);

    { // Remove spaces
        int len = input.length();
        int space_count = std::count(input.begin(), input.end(), ' ');
        auto _ = remove(input.begin(), input.end(), ' ');
        input.resize(len - space_count);
    }

    // Convert string to vector<char>
    std::vector<char> infix_expr(input.begin(), input.end());

    // Convert to postfix
    std::vector<char> postfix_expr = infix_to_postfix(infix_expr);

    // Convert vector<char> to string
    std::string postfix_str(postfix_expr.begin(), postfix_expr.end());


    std::cout << "Infix: " << input << std::endl;
    std::cout << "Postfix: " << postfix_str << std::endl;
}
