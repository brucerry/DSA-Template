/*
    Least Recently Used (LRU) Cache
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node* left, *right;

    Node() : key(0), value(0), left(nullptr), right(nullptr) {}
    Node(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}
    Node(int key, int value, Node* left, Node* right) : key(key), value(value), left(left), right(right) {}
};

struct LRUCache {
    LRUCache(int capacity) {
        this->capacity = capacity;
        LRU = new Node(0, 0, nullptr, MRU);
        MRU = new Node(0, 0, LRU, nullptr);
    }
    
    int get(int key) {
        if (cache.count(key) == 0)
            return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if (cache.size() > capacity) {
            cache.erase(LRU->right->key);
            remove(LRU->right);
        }
    }

private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* LRU, *MRU;

    void insert(Node* node) {
        node->left = MRU->left;
        node->right = MRU;
        node->left->right = MRU->left = node;
    }

    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        node->left = node->right = nullptr;
    }
};