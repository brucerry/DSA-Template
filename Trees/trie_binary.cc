/*
    Trie - prefix tree
    Implementing with binary in a prefix tree
*/

#include <bits/stdc++.h>
using namespace std;

#define NUM_BIT 32

struct Trie {
    Trie* children[2] = {};

    Trie() {
        
    }

    void insert(long num) {
        Trie* cur = this;
        for (int i = NUM_BIT - 1; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!cur->children[bit])
                cur->children[bit] = new Trie();
            cur = cur->children[bit];
        }
    }

    long find_possible(long target) {
        long res = 0;
        Trie* cur = this;
        for (int i = NUM_BIT - 1; i >= 0; i--) {
            int bit = (target >> i) & 1;
            if (!cur->children[bit]) {
                cur = cur->children[bit^1];
                res |= (bit ^ 1) << i;
            }
            else {
                cur = cur->children[bit];
                res |= bit << i;
            }
        }
        return res;
    }
};
