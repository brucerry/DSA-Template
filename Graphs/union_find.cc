/*
    Union Find / Disjoint Union Set (DSU)
*/

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int group;
    vector<int> parent;

    UnionFind(int n) : group (n), parent (n) {
        iota(parent.begin(), parent.end(), 0);
    }

    bool unions(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return false;
        parent[par1] = par2;
        --group;
        return true;
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
};
