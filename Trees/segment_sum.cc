/*
    Segment Tree for Range Sum
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node + 1, start, mid, left, right);
        int rightQuery = query(2 * node + 2, mid + 1, end, left, right);
        return leftQuery + rightQuery;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

int range_sum() {
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segTree(arr);
    
    cout << "Sum of range [1,3]: " << segTree.query(1, 3) << endl;
    segTree.update(2, 10);
    cout << "Sum of range [1,3] after update: " << segTree.query(1, 3) << endl;
    
    return 0;
}
