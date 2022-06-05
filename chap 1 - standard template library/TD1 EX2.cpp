#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

typedef std::pair<int, std::string> pair;

void display(const std::vector<pair> &vector) {
    for (auto &pair: vector) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

bool contains(const std::vector<pair> &vector, const std::string &string) {
    for (auto &pair: vector)
        if (pair.second == string)
            return true;
    return false;
}

bool contains(const std::vector<pair> &vector, int key) {
    for (auto &pair: vector)
        if (pair.first == key)
            return true;
    return false;
}

int main() {
    std::ifstream input_file;
    std::string file_path = "../input.txt";
    input_file.open(file_path);
    if (!input_file) {
        std::cerr << "could not open text file." << std::endl;
        return 1;
    } else {
        std::cout << "reading from file " << file_path << std::endl;
    }

    std::vector<pair> vector;
    int key;
    std::string value;
    while (input_file >> key >> value) {
        // vector.push_back(std::make_pair(key, value));
        // or
        vector.emplace_back(key, value);
        // emplace_back accepts arguments of the constructor of the type
        // so instead of redundantly placing a constructor for a std::pair<int, std::string>
        // just use int, std::string
    }
    std::cout << "displaying the vector" << std::endl;
    display(vector);

    // ------- #2 SORT VECTOR IN ASCENDING ORDER ACCORDING TO THE KEYS ------- //
    std::cout << "sorting the vector" << std::endl;
    std::sort(vector.begin(), vector.end());
    std::cout << "displaying the vector" << std::endl;
    display(vector);

    // To use a custom sorting parameter, for example based on strings, you do the following
    // first create a function
    //    bool compare_string(pair &p1, pair &p2) {
    //        return p1.second < p2.second;
    //    }
    // then, use the function as the third parameter for std::sort
    //    std::sort(vector.begin(), vector.end(), compare_string);

    // ------- #3 READ A STRING THAT CONTAINS SPACES  ------- //
    std::cout << "input which person you would like to add a family name to: ";
    std::string user_input_person;
    std::cin >> user_input_person;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    while (!contains(vector, user_input_person)) {
        std::cout << "that person doesn't exist. Try again: " << std::endl;
        display(vector);
        std::cin >> user_input_person;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    }

    std::cout << "enter family name you would like to add to " << user_input_person << ": ";
    std::string family_name;
    std::getline(std::cin, family_name);
    std::cout << "length of family name " << family_name << ": " << family_name.length() << std::endl;

    std::cout << "appending " << family_name << " to " << user_input_person << std::endl;
    for (auto &pair: vector) {
        if (pair.second == user_input_person) {
            pair.second += " " + family_name;
            break;
        }
    }
    //    or using iterators
    //    for (std::vector<pair>::iterator it = vector.begin(); it != vector.end(); it++) {
    //        if (it->second == user_input_person) {
    //            it->second += " " + family_name;
    //            break;
    //        }
    //    }
    display(vector);

    // ------- #5 SEARCH FOR A KEY AND ERASE THE ASSOCIATED PAIR  ------- //
    key = -99;
    while (!contains(vector, key)) {
        std::cout << "enter key of a pair to erase: ";
        std::cin >> key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!std::cin) {
            std::cin.clear();
            std::cerr << "please enter an integer only.";
            continue;
        } else if (!contains(vector, key)) {
            std::cout << "that key doesn't exist. try again:" << std::endl;
            display(vector);
        }
    }

    std::cout << "erasing pair with key " << key << std::endl;
    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (it->first == key) {
            std::cout << "deleted pair (" << key << ", " << it->second << ")" << std::endl;
            vector.erase(it);
            break;
        }
    }
    display(vector);
    return 0;
}
