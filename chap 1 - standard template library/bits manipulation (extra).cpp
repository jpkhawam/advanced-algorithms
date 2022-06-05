#include <iostream>
#include <cmath>
#include <stack>

#define is_on(S, index) ((S) & (1 << (index)))
#define set_bit(S, index) (S |= (1 << index))
#define clear_bit(S, index) (S &= ~(1 << index))
#define toggle_bit(S, index) (S ^= (1 << index))
#define low_bit(S) (S & (-S))
#define set_all(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define is_power_of_two(S) (!(S & (S - 1)))
#define nearest_power_of_two(S) ((int) pow(2.0, (int) ((log((double) S) / log(2.0)) + 0.5)))
#define turn_off_last_bit(S) ((S) & (S - 1))
#define turn_on_last_zero(S) ((S) | (S + 1))
#define turn_off_last_consecutive_bits(S) ((S) & (S + 1))
#define turn_on_last_consecutive_zeroes(S) ((S) | (S - 1))

void print_set(int vS) { // in binary representation
    std::cout << "S = " << vS << " = ";
    std::stack<int> stack;
    while (vS) {
        stack.push(vS % 2), vS /= 2;
    }
    // to reverse the print order
    while (!stack.empty()) {
        std::cout << stack.top() << " ", stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    int S, T;

    std::cout << "#1 Representation (all indexing are 0-based and counted from right)" << std::endl;
    S = 34;
    print_set(S);
    std::cout << std::endl;

    std::cout << "#2 Multiply S by 2, then divide S by 4 (2x2), then by 2" << std::endl;
    S = 34;
    print_set(S);
    S = S << 1;
    print_set(S);
    S = S >> 2;
    print_set(S);
    S = S >> 1;
    print_set(S);
    std::cout << std::endl;

    std::cout << "#3 Set/turn on the 3-th item of the set" << std::endl;
    S = 34;
    print_set(S);
    set_bit(S, 3);
    print_set(S);
    std::cout << std::endl;

    std::cout << "#4 Check if the 3-th and then 2-nd item of the set is on?" << std::endl;
    S = 42;
    print_set(S);
    T = is_on(S, 3);
    std::cout << "T = " << (T ? "ON" : "OFF") << std::endl;
    T = is_on(S, 2);
    std::cout << "T = " << (T ? "ON" : "OFF") << std::endl;

    std::cout << "#5 Clear/turn off the 1-st item of the set" << std::endl;
    S = 42;
    print_set(S);
    clear_bit(S, 1);
    print_set(S);
    std::cout << std::endl;

    std::cout << "#6 Toggle the 2-nd item and then 3-rd item of the set" << std::endl;
    S = 40;
    print_set(S);
    toggle_bit(S, 2);
    print_set(S);
    toggle_bit(S, 3);
    print_set(S);
    std::cout << std::endl;

    printf("#7 Check the first bit from right that is on\n");
    S = 40;
    print_set(S);
    T = low_bit(S);
    printf("T = %d (this is always a power of 2)\n", T);
    S = 52;
    print_set(S);
    T = low_bit(S);
    printf("T = %d (this is always a power of 2)\n", T);
    std::cout << std::endl;

    printf("#8 Turn on all bits in a set of size n = 6\n");
    set_all(S, 6);
    print_set(S);
    std::cout << std::endl;

    std::cout << "#9 Other tricks " << std::endl;
    std::cout << "8 % 4 = " << modulo(8, 4) << std::endl;
    std::cout << "7 % 4 = " << modulo(7, 4) << std::endl;
    std::cout << "6 % 4 = " << modulo(6, 4) << std::endl;
    std::cout << "5 % 4 = " << modulo(5, 4) << std::endl;

    std::cout << "is 9 power of two? " << is_power_of_two(9) << std::endl;
    std::cout << "is 8 power of two? " << is_power_of_two(8) << std::endl;
    std::cout << "is 7 power of two? " << is_power_of_two(7) << std::endl;

    for (int i = 0; i <= 16; i++) {
        std::cout << "Nearest power of two of " << i << " is " << nearest_power_of_two(i) << std::endl;
    }

    std::cout << "S = 40, turn off last bit in S, S = " << turn_off_last_bit(40) << std::endl;
    std::cout << "S = 41, turn on last zero in S, S = " << turn_on_last_zero(41) << std::endl;
    std::cout << "S = 39, turn off last consecutive bits in S, S = " << turn_off_last_consecutive_bits(39) << std::endl;
    std::cout << "S = 36, turn on last consecutive zeroes in S, S = " << turn_on_last_consecutive_zeroes(36) << std::endl;

    return 0;
}

