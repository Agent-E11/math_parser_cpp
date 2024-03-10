#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <format> // FIXME: Find out how to use format

#include "tools.h"

// TODO: Use a struct to represent a token instead of a uint64_t

enum TOKEN_TYPE : uint64_t {
    NUM  = 0x0,
    OP   = 0x1,
    ID   = 0x2,
    FUNC = 0x3,
};

std::vector<uint64_t> tokenize(std::string expr) {
    std::vector<uint64_t> tokens = {};
    uint64_t token;

    for (int i = 0; i < expr.length(); i++) {
        token = 0;

        char c = expr[i];
        //std::cout << i << ": " << c << std::endl;

        if (isdigit(c)) {
            token |= TOKEN_TYPE::NUM << 61;
            std::cout << "digit: `" << c << "`" << std::endl;
        } else if (isalpha(c)) {
            token |= TOKEN_TYPE::ID << 61;
            std::cout << "alpha: `" << c << "`" << std::endl;
        } else if (c == '^'
            || c == '*'
            || c == '/'
            || c == '+'
            || c == '-'
        ) {
            token |= TOKEN_TYPE::OP << 61;
            std::cout << "oper : `" << c << "`" << std::endl;
        } else if (c == ' ') {
            std::cout << "space: `" << c << "`" << std::endl;
        } else {
            std::cout << "not v: `" << c << "`" << std::endl;
        }
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::vector<uint64_t> tokens = tokenize("y = mx+b; 546sdfg8sd978");

    std::cout << std::endl;
    for (uint64_t t : tokens)
        std::cout << std::setw(16) << std::format("{:x}", t) << std::endl;
}
