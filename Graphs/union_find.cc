/*
    Union Find / Disjoint Union Set (DSU)
*/

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int groups;
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        groups = n;
        for (int i = 0; i < n; i++) {
            parent.emplace_back(i);
        }
        rank.resize(n, 1);
    }

    bool unions(int node1, int node2) {
        int par1 = find(node1);
        int par2 = find(node2);
        if (par1 == par2)
            return false;
        if (rank[par1] > rank[par2]) {
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }
        else {
            rank[par2] += rank[par1];
            parent[par1] = par2;
        }
        groups--;
        return true;
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }
};