#include <iostream>
#include <string>
#include <stdexcept>
#include "BSTree.h"

void title(const std::string &t) {
    std::cout << t << std::endl << std::string(t.size(), '-') << std::endl;
}

void show(BSTree<int> &bst, bool withSearch = false, int e = 0) {
    std::cout << "bstree.size(): " << bst.size() << std::endl;
    if (withSearch)
        std::cout << "bstree.search(" << e << "): " << bst.search(e) << std::endl;
    std::cout << "cout << bstree: " << std::endl << bst << std::endl << std::endl;
}

int main() {
    std::cout << "Creating BSTree<int> bstree ..." << std::endl << std::endl;
    BSTree<int> bstree;
    show(bstree);

    int vals[] = {15, 7, 3, 11, 9, 18, 21, 20};
    for (int v : vals) {
        title("bstree.insert(" + std::to_string(v) + ")");
        bstree.insert(v);
        show(bstree, true, v);
    }

    try {
        bstree.search(0);
        std::cout << "bstree.search(0) => ERROR! It did not throw std::runtime_error." << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "bstree.search(0) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        bstree.search(9);
        std::cout << "bstree.search(9) => OK! It did not throw std::runtime_error." << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "bstree.search(9) => ERROR! It throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        bstree.insert(9);
        std::cout << "bstree.insert(9) => ERROR! It did not throw std::runtime_error." << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "bstree.insert(9) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }
    try {
        bstree.remove(50);
        std::cout << "bstree.remove(50) => ERROR! It did not throw std::runtime_error." << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "bstree.remove(50) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    int dels[] = {9, 11, 7, 15};
    for (int v : dels) {
        title("bstree.remove(" + std::to_string(v) + ")");
        bstree.remove(v);
        show(bstree);
        title("bstree.insert(" + std::to_string(v) + ")");
        bstree.insert(v);
        show(bstree);
    }

    return 0;
}
