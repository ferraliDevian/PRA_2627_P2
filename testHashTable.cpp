
#include <iostream>
#include <stdexcept>
#include "HashTable.h"

int main() {
    HashTable<int> dict(3);

    std::cout << dict << std::endl;
    std::cout << "dict.capacity(): " << dict.capacity() << std::endl;
    std::cout << "dict.entries(): " << dict.entries() << std::endl << std::endl;

    std::string keys[] = {"One", "Two", "Three", "Four", "Five", "Six"};
    for (int i = 0; i < 6; i++) {
        std::cout << "dict.insert('" << keys[i] << "', " << i + 1 << ") ..." << std::endl;
        dict.insert(keys[i], i + 1);
    }
    std::cout << std::endl << std::endl << dict << std::endl;

    std::cout << "dict.search('One'): " << dict.search("One") << std::endl;
    std::cout << "dict['Four']: " << dict["Four"] << std::endl;
    std::cout << "dict.remove('Three'): " << dict.remove("Three") << std::endl;
    std::cout << std::endl << std::endl << dict << std::endl;

    try {
        dict.insert("One", 1);
    } catch (std::runtime_error &e) {
        std::cout << "dict.insert('One') => throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        dict.search("Ten");
    } catch (std::runtime_error &e) {
        std::cout << "dict.search('Ten') => throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        dict.remove("Ten");
    } catch (std::runtime_error &e) {
        std::cout << "dict.remove('Ten') => throwed std::runtime_error: " << e.what() << std::endl;
    }

    return 0;
}
