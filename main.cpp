#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

void print_vec(std::vector<char> v) {
    std::cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::map<char, int> precedence;
    precedence['('] = 5; // Adding parentheses to precedence might break something down the road
    precedence[')'] = 5;
    precedence['^'] = 4;
    precedence['*'] = 3;
    precedence['/'] = 3;
    precedence['+'] = 2;
    precedence['-'] = 2;

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
        std::cout << i << ": " << input[i] << std::endl;

        if (std::isalnum(c)) {
            out_queue.push_back(c);
        } else if (precedence.count(c)) {
            op_stack.push_back(c);
        } else {
            std::cout << "is invalid" << std::endl;
        }
        std::cout << "Stack: "; print_vec(op_stack);
        std::cout << "Queue: "; print_vec(out_queue);
    }
}
