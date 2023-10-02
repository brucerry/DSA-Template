/*
    Kadane algorithm
    Finding the maximum subarray sum
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& nums) {
    int res = nums[0], cursum = 0;
    for (int num : nums) {
        cursum = max(cursum + num, num);
        res = max(res, cursum);
    }
    return res;
}