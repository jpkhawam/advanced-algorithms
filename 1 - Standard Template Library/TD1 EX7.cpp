#include <iostream>
#include <bitset>

constexpr int LENGTH = 32;

int main() {
    // ----------- #1 ----------- //
    std::bitset<LENGTH> bset1;
    std::bitset<LENGTH> bset2(20);
    std::bitset<LENGTH> bset3(std::string("1100"));

    std::cout << "bset1: " << bset1 << std::endl;
    std::cout << "bset2: " << bset2 << std::endl;
    std::cout << "bset3: " << bset3 << std::endl;

    // ----------- #2 ----------- //
    std::bitset<8> set8;
    set8.set(1, 1);
    set8.set(4, 1);
    std::cout << "set8: " << set8 << std::endl;

    // ----------- #3 ----------- //
    std::cout << "number of set bits in set8: " << set8.count() << std::endl;
    std::cout << "number of unset bits in set8: " << set8.size() - set8.count() << std::endl;

    // ----------- #4 ----------- //
    std::cout << "set8 bit by bit: ";
    for (int i = set8.size() - 1; i >= 0; i--) {
        std::cout << set8[i];
    }
    std::cout << std::endl;

    // ----------- #5 ----------- //
    if (set8.any()) {
        std::cout << "at least one bit is set in set8" << std::endl;
    } else if (set8.none()) {
        std::cout << "no bit is set in set8" << std::endl;
    }

    // ----------- #6 ----------- //
    if (set8.all()) {
        std::cout << "all the bits in set8 are set" << std::endl;
    }

    // ----------- #7 ----------- //
    std::cout << "setting all bits in set8 to 1, and bit 4 to 0" << std::endl;
    set8.set();
    set8.set(4, 0);
    std::cout << "set8: " << set8 << std::endl;

    // ----------- #8 ----------- //
    std::cout << "resetting all bits in set8 to 0" << std::endl;
    set8.reset();
    std::cout << "set8: " << set8 << std::endl;

    // ----------- #9 ----------- //
    std::cout << "flipping all the bits in set8" << std::endl;
    set8.flip();
    std::cout << "set8: " << set8 << std::endl;

    // ----------- #10 ----------- //
    int number_to_convert = 640;
    std::cout << number_to_convert << " in binary is " << std::bitset<8>(number_to_convert) << std::endl;
}

