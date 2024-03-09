#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "tools.h"

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
            tokens.push_back(TOKEN_TYPE::NUM);
            std::cout << "digit: `" << c << "`" << std::endl;
        } else if (isalpha(c)) {
            tokens.push_back(TOKEN_TYPE::ID);
            std::cout << "alpha: `" << c << "`" << std::endl;
        } else if (c == '^'
            || c == '*'
            || c == '/'
            || c == '+'
            || c == '-'
        ) {
            tokens.push_back(TOKEN_TYPE::OP);
            std::cout << "oper : `" << c << "`" << std::endl;
        } else if (c == ' ') {
            std::cout << "space: `" << c << "`" << std::endl;
        } else {
            std::cout << "not v: `" << c << "`" << std::endl;
        }
    }

    return tokens;
}

int main() {
    tools::print_vec(tokenize("y = mx+b; 546sdfg8sd978"));
}
