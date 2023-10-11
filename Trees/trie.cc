/*
    Trie - prefix tree
    Implementing with lower-case letters
*/

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* children[26] = {};
    bool is_end = false;

    Trie() {
        
    }

    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new Trie();
            cur = cur->children[c - 'a'];
        }
        cur->is_end = true;
    }

    Trie* search_prefix(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            if (!cur->children[c - 'a'])
                return nullptr;
        }
        return cur;
    }

    bool search_(string word) {
        Trie* res = search_prefix(word);
        return res and res->is_end;
    }
};