#include <iostream>
#include <queue>
#include <fstream>
#include <string>

typedef std::pair<int, std::string> pair;

class compare {
public:
    bool operator()(const pair &a, const pair &b) {
        return a.second > b.second;
    }
};

int main() {
    std::priority_queue<pair, std::vector<pair>, std::greater<>> priority_queue;
    // or
    // std::priority_queue<pair, std::vector<pair>, compare> priority_queue;

    std::ifstream input_file;
    input_file.open("input.txt");
    if (!input_file) {
        std::cerr << "error opening the file" << std::endl;
        return 1;
    }

    int key{};
    std::string string;
    while (input_file >> key >> string) {
        priority_queue.push(std::make_pair(key, string));
        // or
        // priority_queue.emplace(key, string);
    }
    while (!priority_queue.empty()) {
        std::cout << priority_queue.top().first << " " << priority_queue.top().second << std::endl;
        priority_queue.pop();
    }
    return 0;
}

