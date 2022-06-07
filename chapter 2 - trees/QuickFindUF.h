#ifndef QuickFindUF_H
#define QuickFindUF_H
// or #pragma once

#include <vector>

class QuickFindUF {
private:
    // access to component id (site indexed)
    std::vector<int> id;

public:
    /* initialize union-find data structure with N singleton objects (0 to N - 1) */
    explicit QuickFindUF(int N) : id(N) {
        // : id(N) is the same as initializing id[] in the function body
        for (int i = 0; i < N; i++) {
            // each object has a unique id at first
            id[i] = i;
        }
    }

    /* returns true if p and q are in the same component, false otherwise */
    bool connected(int p, int q) {
        // checks id of each object
        return find(p) == find(q);
    }

    /* component identifier for p (0 to N - 1) */
    int find(int p) {
        return id[p];
    }

    /* adds connection between p and q */
    // traverses id[] and changes all ids of objects in the same set as p to that of q
    void make_union(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int &i: id) {
            if (i == pid) {
                i = qid;
            }
        }
    }
};

#endif

