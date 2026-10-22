#include <iostream>
#include <stdexcept>
#include "BSTreeDict.h"

int main() {
    std::cout << "Creating BSTreeDict<int> dict ..." << std::endl << std::endl;
    BSTreeDict<int> dict;

    std::cout << "dict.entries(): " << dict.entries() << std::endl;
    std::cout << "cout << dict: " << std::endl << dict << std::endl << std::endl;

    std::string keys[] = {"c", "f", "a", "b", "d", "e"};
    int vals[] = {3, 6, 1, 2, 4, 5};
    for (int i = 0; i < 6; i++) {
        std::cout << "dict.insert('" << keys[i] << "', " << vals[i] << ") ..." << std::endl;
        dict.insert(keys[i], vals[i]);
    }

    std::cout << std::endl << "cout << dict: " << std::endl << dict << std::endl << std::endl;

    std::cout << "dict.search('a'): " << dict.search("a") << std::endl;
    std::cout << "dict['d']: " << dict["d"] << std::endl;
    std::cout << "dict.remove('c'): " << dict.remove("c") << std::endl << std::endl;
    std::cout << dict << std::endl << std::endl;

    try {
        dict.insert("a", 1);
    } catch (std::runtime_error &e) {
        std::cout << "dict.insert('a') => OK! throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        dict.search("j");
    } catch (std::runtime_error &e) {
        std::cout << "dict.search('j') => OK! throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        dict.remove("c");
    } catch (std::runtime_error &e) {
        std::cout << "dict.remove('c') => OK! throwed std::runtime_error: " << e.what() << std::endl;
    }

    return 0;
}
