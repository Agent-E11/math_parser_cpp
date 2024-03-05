#include <vector>
#include <iostream>
#include <map>

namespace tools {
    void print_vec(std::vector<char> v) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
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
}
