/*
    This code source:
    https://github.com/ncduy0303/Competitive-Programming/blob/master/String%20Processing/Z-algo%20(Z%20function).cpp
*/

// Given a string s (with length n) and a pattern p (with length m), find all the occurrence of p in s
// Time complexity: O(n + m)
// Problem link: https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;
 
// f[i] = length of the longest common prefix between s and the substring s[i...n-1]
vector<int> z_func(string& s) {
    int n = s.size();
    vector<int> f (n); // f[0] = 0 by default
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            f[i] = min(r - i + 1, f[i - l]);
        while (i + f[i] < n && s[f[i]] == s[i + f[i]]) {
            f[i]++;
        }
        if (i + f[i] - 1 > r) {
            l = i;
            r = i + f[i] - 1;
        }
    }
    return f;
}
 
int count_occurs(string s, string pattern) {
    string ps = pattern + "#" + s;
    int n = pattern.size();
    int m = s.size();
    int nm = ps.size();
    vector<int> f = z_func(ps);
    int res = 0;
    for (int i = n + 1; i < nm; i++) {
        res += f[i] == n;
    }
    return res;
}
