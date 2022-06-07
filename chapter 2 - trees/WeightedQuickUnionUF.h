#ifndef wQuickUnionUF_H
#define wQuickUnionUF_H

#include <vector>

class WeightedQuickUnionUF {
private:
    std::vector<int> id;   // access to component set id
    std::vector<int> size; // size of root of component

public:
    /* initialize union-find data structure with N objects (0 to N - 1) */
    explicit WeightedQuickUnionUF(int N) : id(N), size(N) {
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
        for (int i = 0; i < N; i++) {
            size[i] = 1;
        }
    }

    /* returns true if p and q are in the same component, false otherwise */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    /* component identifier for i (0 to N - 1) */
    int find(int i) {
        // follow links to find a root.
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }

    int find_path_compression(int i) {
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

    /* adds connection between p and q*/
    void make_union(int p, int q) {
        int i = find_path_compression(p);
        int j = find_path_compression(q);
        if (i == j) {
            // if i and j already belong to the same group there is nothing to do
            return;
        }
        // link the smaller tree to the bigger tree
        // and increase the size of the bigger tree with the size of the smaller tree
        if (size[i] < size[j]) {
            id[i] = j;
            size[j] += size[i];
        } else {
            id[j] = i;
            size[i] += size[j];
        }
    }
};

#endif

