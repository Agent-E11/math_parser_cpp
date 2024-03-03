#include <algorithm>
#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<char, int> precedence;
    precedence['^'] = 4;
    precedence['*'] = 3;
    precedence['/'] = 3;
    precedence['+'] = 2;
    precedence['-'] = 2;

    std::string input;

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
        std::cout << i << ": " << input[i] << std::endl;
    }
}
