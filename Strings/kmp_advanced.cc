#include <bits/stdc++.h>
using namespace std;

/*
    KMP - Knuth–Morris–Pratt algorithm

    Parameters:
        - s: The target string
        - sub: The target substring

    Returns:
        A vector which contains all indices (in ascending order) of 's' where the 'sub' is a substring of 's' to start at

    Time:
        O(s + sub)

    Space:
        O(s + sub)
*/
vector<int> kmp(string& s, string& sub) {
    string tmp = sub + '#' + s;
    vector<int> dp (tmp.size());
    for (int i = 1; i < tmp.size(); i++) {
        int cur = dp[i - 1];
        while (cur and tmp[i] != tmp[cur]) {
            cur = dp[cur - 1];
        }
        dp[i] = cur + (tmp[i] == tmp[cur]);
    }
    vector<int> k;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] >= sub.size()) {
            k.emplace_back(i - 2 * sub.size());
        }
    }
    return k;
}