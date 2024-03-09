#include <iostream>
#include <map>
#include <vector>

namespace tools {
    template <typename T>
    void print_vec(std::vector<T> v) {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
    //void print_vec(std::vector<T> v);

    void print_map(std::map<char, int> m);

    bool map_contains(std::map<char, int> m, char c);
}
