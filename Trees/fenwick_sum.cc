/*
    Fenwick Tree - Ranges sum update
*/

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    Fenwick(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;
        fenwick.resize(n + 1);
        for (int i = 0; i < n; i++) {
            init_fenwick(i + 1);
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        index++;
        while (index < fenwick.size()) {
            fenwick[index] += diff;
            index += lowbit(index);
        }
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }

private:
    vector<int> nums, fenwick;

    int lowbit(int x) {
        return x & (-x);
    }

    void init_fenwick(int f) {
        int val = nums[f-1];
        while (f < fenwick.size()) {
            fenwick[f] += val;
            f += lowbit(f);
        }
    }

    int sum(int f) {
        int res = 0;
        while (f > 0) {
            res += fenwick[f];
            f -= lowbit(f);
        }
        return res;
    }
};