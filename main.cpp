#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include <vector>

void print_vec(std::vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    //std::cout << std::endl;
}

void print_map(std::map<char, int> m) {
    std::cout << std::endl << "{" << std::endl;
    for (const auto& elem : m) {
        std::cout << "    " << elem.first << " = " << elem.second << std::endl;
    }
    std::cout << "}" << std::endl;
}

bool map_contains(std::map<char, int> m, char c) {
    return m.find(c) != m.end();
}

int main() {
    const std::map<char, int> precedence = {
        {'^', 4},
        {'*', 3},
        {'/', 3},
        {'+', 2},
        {'-', 2}
    };

    std::string input;

    std::vector<char> op_stack = {};
    std::vector<char> out_queue = {};

    std::cout << "Input math expression: ";

    std::getline(std::cin, input);

    std::cout << "Input: " << input << std::endl;

    { // Remove spaces
        int len = input.length();

        int space_count = std::count(input.begin(), input.end(), ' ');

        auto _ = remove(input.begin(), input.end(), ' ');

        input.resize(len - space_count);
    }

    std::cout << "Input: " << input << std::endl;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        // print_map(precedence);
        // std::cout << i << ": " << input[i] << "\t";

        if (std::isalnum(c)) {
            out_queue.push_back(c);
        } else if (map_contains(precedence, c)) {
            std::cout << "c: " << c << "\t";
            // std::cout << "p[c]: " << precedence.at(c) << "\t";
            std::cout << "p.c: " << precedence.count(c) << "\t";
            while (!op_stack.empty() && precedence.at(c) <= precedence.at(op_stack.back()) && op_stack.back() != '(') {
                out_queue.push_back(op_stack.back());
                op_stack.pop_back();
            }
            op_stack.push_back(c);
        } else if (c == '(') {
            op_stack.push_back(c);
        } else if (c == ')') {
            while (!op_stack.empty() && op_stack.back() != '(') {
                if (op_stack.empty()) {
                    std::cout << "Error: mismatched parentheses" << std::endl;
                    return 1;
                }
                out_queue.push_back(op_stack.back());
                op_stack.pop_back();
            }
            op_stack.pop_back(); // Remove '('
        } else {
            std::cout << "is invalid" << std::endl;
        }
        std::cout << "Stack: "; print_vec(op_stack);
        std::cout << "\tQueue: "; print_vec(out_queue);
        std::cout << std::endl;
    }
    // Add the rest of the operators to the output
    std::cout << "moving operators" << std::endl;
    while (!op_stack.empty()) {
        if (op_stack.back()) {
            std::cout << "Error: mismatched parentheses" << std::endl;
            return 1;
        }
        out_queue.push_back(op_stack.back());
        op_stack.pop_back();
    }
    std::cout << "done moving operators" << std::endl;
    std::cout << "Stack: "; print_vec(op_stack);
    std::cout << "\t\t\tQueue: "; print_vec(out_queue);
}
