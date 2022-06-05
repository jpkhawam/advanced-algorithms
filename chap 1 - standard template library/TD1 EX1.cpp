#include <iostream>
#include <random>
#include <vector>
#include <algorithm> // for std::reverse(), std::find(), std::max_element(), std::min_element(), std::sort(), etc

void display_vector(std::vector<int> &vector) {
    for (int &it : vector) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void display_vector_reverse(std::vector<int> &vector) {
    for (auto it = vector.rbegin(); it != vector.rend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool comparison(int a, int b) { return a > b }

int main() {
    int vector_length = -1;
    while (vector_length < 1) {
        std::cout << "Enter number of elements in vector > 0: ";
        std::cin >> vector_length;
        std::cout << std::endl;
    }

    std::vector<int> vector(vector_length);

    for (int &i : vector) {
        i = rand() % 191 + 10;
    }

    // ----------- #1 DISPLAY VECTOR USING ITERATORS ----------- //
    std::cout << "displaying vector using iterators : ";
    display_vector(vector);
    // ----------- #2 DISPLAY VECTOR IN REVERSE  ----------- //
    std::cout << "displaying vector in reverse using iterators : ";
    display_vector_reverse(vector);

    std::cout << std::endl << std::endl;

    // ----------- #3 REVERSE THE VECTOR ----------- //
    std::cout << "reversing the vector : ";
    std::reverse(vector.begin(), vector.end());
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #4 FIND A GIVEN ELEMENT ----------- //
    int number_to_find{-1};
    while (number_to_find < 10 || number_to_find > 200) {
        std::cout << "Enter a number to find (10 < input < 200): ";
        std::cin >> number_to_find;
        std::cout << std::endl;
    }

    // there are multiple ways of searching for an element
    std::vector<int>::iterator iterator;

    /** METHOD 1: std::find() **/
    iterator = std::find(vector.begin(), vector.end(), number_to_find);

    /** METHOD 2: std::lower_bound() **/
    iterator = std::lower_bound(vector.begin(), vector.end(), number_to_find);

    if (iterator == vector.end() && *vector.end() != number_to_find)
        std::cout << "The number " << number_to_find << " was not found using iterators" << std::endl;
    else
        std::cout << "The number " << number_to_find << " was found using iterators" << std::endl;

    /** METHOD 3: std::binary_search() **/
    if (std::binary_search(vector.begin(), vector.end(), number_to_find))
        std::cout << "The number " << number_to_find << " was not found using binary search" << std::endl;
    else
        std::cout << "The number " << number_to_find << " was found using binary search" << std::endl;

    std::cout << std::endl << std::endl;

    // ----------- #5 FIND MIN/MAX ELEMENTS ----------- //
    std::cout << "Max element is " << *std::max_element(vector.begin(), vector.end()) << std::endl;
    std::cout << "Minimum element is " << *std::min_element(vector.begin(), vector.end()) << std::endl;

    std::cout << std::endl << std::endl;

    // ----------- #6 SORT VECTOR IN ASCENDING ORDER ----------- //
    std::cout << "Sorting vector in ascending order" << std::endl;
    std::sort(vector.begin(), vector.end());
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #7 ERASE AN ELEMENT ----------- //
    int number_to_erase{-1};
    while (number_to_erase < 10 || number_to_erase > 200) {
        std::cout << "Enter a number to erase (10 < input < 200): ";
        std::cin >> number_to_erase;
        std::cout << std::endl;
    }

    int count = 0;
    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (*it == number_to_erase) {
            // erase() returns an iterator pointing to the next element (or end())
            it = vector.erase(it);
            count++;
        }
    }
    if (*vector.end() == number_to_erase) {
        vector.pop_back();
        count++;
    }
    std::cout << "deleted " << count << " elements" << std::endl;
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #8 SHUFFLE THE VECTOR ----------- //
    std::cout << "shuffling the vector" << std::endl;
    // this was removed in C++17
    // std::random_shuffle(vector.begin(), vector.end());
    // use this instead
    std::shuffle(vector.begin(), vector.end(), std::mt19937(std::random_device()()));
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #9 SORT THE VECTOR IN DESCENDING ORDER ----------- //
    std::cout << "sorting the vector in descending order" << std::endl;
    // either user defined comparison
    std::sort(vector.begin(), vector.end(), comparison);
    // or std::greater<>
    sort(vector.begin(), vector.end(), std::greater<>());
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #10 DETERMINE THE Kth SMALLEST ELEMENT FOR K = 4 ----------- //
    // std::nth_element() sorts a sequence just enough to find a particular position
    display_vector(vector);
    std::nth_element(vector.begin(), vector.begin() + 3, vector.end());
    std::cout << "The 4th smallest element is " << *(vector.begin() + 3) << std::endl; // std::cout << vector[3];
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #11 FIND THE MEDIAN ELEMENT IN THE VECTOR ----------- //
    display_vector(vector);
    std::nth_element(vector.begin(), vector.begin() + vector.size() / 2, vector.end());
    std::cout << "The median element is " << *(vector.begin() + vector.size() / 2) << std::endl;
    // std::cout << vector[vector.size() / 2];
    display_vector(vector);

    std::cout << std::endl << std::endl;

    // ----------- #11 FIND ELEMENTS IN A GIVEN RANGE ----------- //
    int left_value, right_value{-1};
    while (!std::binary_search(vector.begin(), vector.end(), left_value) ||
           !std::binary_search(vector.begin(), vector.end(), right_value)) {
        std::cout << "Enter range [left:right]: ";
        std::cin >> left_value >> right_value;
        std::cout << std::endl;
    }
    std::vector<int>::iterator left, right;
    left = lower_bound(vector.begin(), vector.end(), left_value);
    right = upper_bound(vector.begin(), vector.end(), right_value);
    std::cout << *left << " " << *right << std::endl;
    // [left,right], right included here
    for (iterator = left; iterator != right; iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;
    // to not include right, it != r - 1; or (it != r && *it != right)

    return 0;
}

