#include <iostream>
#include <vector>
#include <fstream>

int main() {
    // PART 1 - INITIALIZE A NxM MATRIX TO 0 USING VECTORS
    std::vector<std::vector<int>> zeroes;
    int m = 3, n = 4;
    zeroes.assign(n, std::vector<int>(m, 0));
    // display the matrix
    //    for (int i = 0; i < zeroes.size(); i++) {
    //        for (int j = 0; j < zeroes.at(i).size(); j++) {
    //            std::cout << zeroes.at(i).at(j) << " ";
    //        }
    //        std::cout << std::endl;
    //    }

    // PART 2 - READ MATRIX FROM FILE
    std::vector<std::vector<int>> matrix;
    std::ifstream input_file;
    input_file.open("input.txt");
    if (!input_file) {
        std::cerr << "could not open file" << std::endl;
        return 1;
    }

    int number_of_rows{};
    input_file >> number_of_rows;
    matrix.assign(number_of_rows, std::vector<int>());

    while (!input_file.eof()) {
        int current_row{};
        int current_column_length{};
        input_file >> current_column_length;
        for (int i = 0; i < current_column_length; i++) {
            int input{};
            input_file >> input;
            matrix.at(current_row).push_back(input);
        }
        current_row++;
    }

    for (auto &row: matrix) {
        for (int column: row) {
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

