/** Write a program that fills a vector of integers with n random values in the interval [10, 200],
then removes them from vector and inserts them in a FIFO queue, then removes them from
queue and inserts them in a stack, then removes them from the stack and puts the even values
in a maximum priority queue and the odd numbers in a minimum priority queue, then prints
the content of each queue. **/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>

constexpr int LENGTH = 5;
constexpr int UPPER_BOUND = 200;
constexpr int LOWER_BOUND = 10;
typedef std::priority_queue<int, std::vector<int>, std::greater<>> minimum_priority_queue;

void display(std::queue<int> queue) {
    while(!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}

template<typename T>
void display_ds(T data_structure) {
    while(!data_structure.empty()) {
        std::cout << data_structure.top() << " ";
        data_structure.pop();
    }
}

int main() {
    srand(time(nullptr));

    // ------------ VECTOR ------------ //
    std::vector<int> vector;
    for (int i = 0; i < LENGTH; i++) {
        int current_number = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
        vector.push_back(current_number);
    }
    std::cout << "vector: ";
    for (auto x: vector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // ------------ VECTOR -> QUEUE ------------ //
    std::queue<int> queue;
    while(!vector.empty()) {
        int current_number = vector.back();
        vector.pop_back();
        queue.push(current_number);
    }
    std::cout << "queue: ";
    display(queue);  // to go through the elements, you must pop the head element
    // therefore it is better to just copy the queue to a function and display it
    std::cout << std::endl;

    // ------------ QUEUE -> STACK ------------ //
    std::stack<int> stack;
    while(!queue.empty()) {
        int current_number = queue.front();
        queue.pop();
        stack.push(current_number);
    }
    std::cout << "stack: ";
    display_ds(stack); // display_ds<std::stack<int>>(stack);
    std::cout << std::endl;

    // ------------ STACK -> PRIORITY QUEUES ------------ //
    std::priority_queue<int> max_priority_queue;
    minimum_priority_queue min_priority_queue;
    while(!stack.empty()) {
        int current_number = stack.top();
        stack.pop();
        if (current_number % 2 == 0) {
            max_priority_queue.push(current_number);
        } else {
            min_priority_queue.push(current_number);
        }
    }
    std::cout << "maximum priority queue (even numbers): ";
    display_ds(max_priority_queue); // display_ds<std::priority_queue<int>>(max_priority_queue);
    std::cout << std::endl;
    std::cout << "minimum priority queue (odd numbers): ";
    display_ds(min_priority_queue); // display_ds<minimum_priority_queue>(min_priority_queue);
    // or display_ds<std::priority_queue<int, std::vector<int>, std::greater<>>>(min_priority_queue);
    std::cout << std::endl;
    return 0;
}

