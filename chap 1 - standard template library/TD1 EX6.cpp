#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

void display(const std::map<int, std::string> &map) {
    for (const auto &it: map) {
        std::cout << it.first << " " << it.second << std::endl;
    }
}

template<typename T>
void display(const T &t) {
    for (const auto &element: t) {
        std::cout << element << " ";
    }
}

int main() {
    std::ifstream file_input;
    file_input.open("input.txt");
    if (!file_input) {
        std::cerr << "error opening the file" << std::endl;
        return 1;
    }

    std::map<int, std::string> map;
    // to make it an ordered map, std::map<int, std::string, std::greater<>>
    int key;
    std::string string;
    while (file_input >> key >> string) {
        map.insert(std::make_pair(key, string));
    }
    display(map);

    std::cout << map[77] << std::endl;
    map[120] = "new word";
    std::cout << map[120] << std::endl;
    std::cout << map[119] << std::endl;

    std::set<int> set;
    std::set<int, std::greater<>> ordered_set;

    for (auto &it: map) {
        set.insert(it.first);
        ordered_set.insert(it.first);
    }

    display<std::set<int>>(set);
    display<std::set<int, std::greater<>>>(ordered_set);

    map.erase(77);
    set.erase(77);

    map[78] = "new name";
    // or
    map.erase(78);
    map.insert(std::make_pair(78, "new item"));
    // or
    std::map<int, std::string>::iterator it;
    it = map.find(78);
    if (it != map.end() || map.end()->first == 78) {
        it->second = "modified value";
    } else {
        std::cout << "not found" << std::endl;
    }

    map.erase(map.begin(), map.end());
    // or
    set.clear();

    return 0;
}

