#ifndef QuickUnionUF_H
#define QuickUnionUF_H

#include<vector>

class QuickUnionUF {
private:
    // access to component id (site indexed)
    std::vector<int> id;

public:
    /* initialize union-find data structure with N singleton objects (0 to N - 1) */
    explicit QuickUnionUF(int N) : id(N) {
        // : id(N) is the same as initializing id[] in the function body
        for (int i = 0; i < N; i++) {
            // each object has a unique id at first
            id[i] = i;
        }
    }

    /* returns true if p and q are in the same component, false otherwise */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    /* returns id of parent root node */
    int find(int i) {
        // while child_id != id[parent], as in, as long as we didn't reach root node
        while (i != id[i]) {
            i = id[i];
        }
        // at this point, i = id[root_node]
        return i;
    }

    /* adds connection between p and q */
    void make_union(int p, int q) {
        int i = find(p);
        int j = find(q);
        // connects the root node of p to the root node of q
        id[i] = j;
    }
};

#endif

