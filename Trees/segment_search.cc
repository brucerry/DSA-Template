/*
    Segment Tree to search index j of nums2 for each nums1[i] where nums1[i] <= nums2[j].
    If found, mark nums2[j] as occupied. Otherwise, query() returns -1.
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
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
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
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int value) {
        if (start == end) {
            return (tree[node] >= value) ? start : -1;
        }
        int mid = (start + end) / 2;
        if (tree[2 * node + 1] >= value) {
            return query(2 * node + 1, start, mid, value);
        }
        return query(2 * node + 2, mid + 1, end, value);
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

    int query(int value) {
        return query(0, 0, n - 1, value);
    }
};

int search(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    SegmentTree segTree(nums2);

    for (int num : nums1) {
        int index = segTree.query(num);
        if (index == -1) {
            printf("Cannot find an unoccupied index j from nums2 where %d <= nums2[j]\n", num);
        } else {
            printf("Index %d of nums2 = %d >= %d, mark it as occupied", index, nums2[index], num);
            segTree.update(index, -1);
        }
    }

    return 0;
}
