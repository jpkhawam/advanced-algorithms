#include <iostream>
#include <fstream>
#include <vector>

class WeightedQuickUnionUF {
private:
    std::vector<int> id;   // component id
    std::vector<int> size; // size of each set (for largest set size)
    std::vector<int> rank; // height of each set (for union)
    int number_of_sets;

public:
    explicit WeightedQuickUnionUF(int UF_SIZE) : id(UF_SIZE) {
        for (int i = 0; i < UF_SIZE; i++) {
            id[i] = i;
        }
        size.assign(UF_SIZE, 1);
        rank.assign(UF_SIZE, 0);
        number_of_sets = UF_SIZE;
    }

    /* returns true if p and q are in the same component, false otherwise */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    // find WITH path compression
    int find(int i) {
        // follow links to find a root.
        while (i != id[i]) {
            // give each found node id of grandparent to flatten the tree
            // if there is no grandparent and the parent is root node, id[id[i]] == i
            id[i] = id[id[i]];
            // and jump directly to grandparent
            i = id[i];
        }
        return i;
    }

    void make_union(int first, int second) {
        int first_root = find(first);
        int second_root = find(second);
        if (first_root == second_root) {
            return;
        }

        if (rank[first_root] > rank[second_root]) {
            id[second_root] = first_root;
            size[first_root] += size[second_root];
        } else {
            id[first_root] = second_root;
            size[second_root] += size[first_root];
            if (rank[first_root] == rank[second_root]) {
                // if both trees have the same height, the height of their sum only increases by 1
                // (height of second tree + the root node of first tree)
                rank[second_root]++;
            }
        }
        number_of_sets--;
    }

    int size_of(int i) {
        return size[find(i)];
    }

    int rank_of(int i) {
        return rank[i];
    }

    int get_number_of_sets() const {
        return number_of_sets;
    }

    int largest_set_size() {
        int max_set_size{};
        for (int current_set_size: size) {
            if (current_set_size > max_set_size) {
                max_set_size = current_set_size;
            }
        }
        return max_set_size;
    }
};

int main() {
    std::ifstream file_input;
    file_input.open("in_UF.txt");
    if (!file_input) {
        std::cerr << "error opening file" << std::endl;
        return 1;
    }

    int UF_SIZE = 10;
    WeightedQuickUnionUF unionFind(UF_SIZE);
    int p{}, q{};

    while (file_input >> p >> q) {
        if (unionFind.connected(p, q)) {
            std::cout << p << " and " << q << " already connected" << std::endl;
            continue;
        } else {
            unionFind.make_union(p, q);
            std::cout << p << " " << q << " now connected" << std::endl;
            std::cout << "number of components: " << unionFind.get_number_of_sets() << std::endl;
            std::cout << "size of component " << p << ": " << unionFind.size_of(p) << std::endl;
            std::cout << "id of " << p << ": " << unionFind.find(p) << std::endl;
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "total number of components: " << unionFind.get_number_of_sets() << std::endl;
    std::cout << "i id size rank" << std::endl;
    for (int i = 0; i < UF_SIZE; i++) {
        std::cout << i << ": "
                  << unionFind.find(i) << " "
                  << unionFind.size_of(i) << " "
                  << unionFind.rank_of(i)
                  << std::endl;
    }
    std::cout << "largest set size: " << unionFind.largest_set_size() << std::endl;
    return 0;
}

