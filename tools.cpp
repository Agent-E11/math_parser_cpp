#include <iostream>
#include <map>

#include "tools.h"

namespace tools {
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
}
