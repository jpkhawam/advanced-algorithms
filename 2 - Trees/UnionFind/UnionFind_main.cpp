#include <iostream>
#include <limits>
#include "WeightedQuickUnionUF.h"

int main() {
    int size{-1};
    std::cout << "input size of union find data structure: ";
    while (size < 1) {
        std::cin >> size;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!std::cin || size < 1) {
            std::cin.clear();
            std::cerr << "please a positive integer only." << std::endl;
            std::cout << std::endl << "input size of union find data structure (>0): ";
            size = -1;
        }
    }

    WeightedQuickUnionUF unionFind(size);

    std::cout << std::endl << "input two numbers (p, q) to connect: ";
    int p, q;
    // invalid input breaks the loop since it makes std::cin fail
    while (std::cin >> p >> q) {
        // empty the buffer if extra input exists
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (p < 0 || p > size || q < 0 || q > size) {
            std::cout << std::endl << "input two numbers (p, q)  (>=0 and < " << size << ") to connect: ";
            continue;
        }
        else if (unionFind.connected(p, q)) {
            std::cout << p << ", " << q << " are already connected";
            std::cout << std::endl << "input two numbers (p, q) to connect: ";
            continue;
        } else {
            unionFind.make_union(p, q);
            std::cout << p << ", " << q << " are now connected";
            std::cout << std::endl << "input two numbers (p, q) to connect: ";
        }
    }
    return 0;
}

