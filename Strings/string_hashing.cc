/*
    This code source:
    https://github.com/ncduy0303/Competitive-Programming/blob/master/String%20Processing/String%20Hashing%20(Rabin-Karp).cpp
*/

// String Hashing 
// Consider carefully the choice of 'base' and 'mod'
// 'base' should be greater than the number of characters in the input alphabet 
// 'mod' should be a large prime like 1e9 + 7

// should always convert 'a' into 1 instead 0
// should randomise the value of 'base' to avoid hacking
// should use > 1 'base' to reduce collision rate

// Example of string hashing (Rabin-Karp) to count the number of positions where the pattern occurs in the given string
// Problem link: https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
using namespace std;

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
    return uniform_int_distribution(l, r)(rng);
}

const int BASE = rand(300, 1e9);
const int NUM_MOD = 2;
const long long MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash {
    vector<long long> H[NUM_MOD], P[NUM_MOD];
    Hash(string s) {
        for (int i = 0; i < NUM_MOD; i++) {
            P[i].push_back(1);
            H[i].push_back(0);
        }
        for (char c : s) {
            for (int i = 0; i < NUM_MOD; i++) {
                P[i].push_back(P[i].back() * BASE % MODS[i]);
                H[i].push_back((H[i].back() * BASE + c) % MODS[i]);
            }
        }
    } 
    array<long long, NUM_MOD> operator()(int l, int r) {
        array<long long, NUM_MOD> res;
        for (int i = 0; i < NUM_MOD; i++) {
            res[i] = (H[i][r + 1] - H[i][l] * P[i][r + 1 - l]) % MODS[i];
            if (res[i] < 0)
                res[i] += MODS[i];
        }
        return res;
    }
};

int count_occurs(string s, string pattern) {
    int n = s.size();
    int m = pattern.size();
    Hash hs(s), ht(pattern);
    int res = 0;
    for (int i = 0, j = m - 1; j < n; i++, j++) {
        res += (hs(i, j) == ht(0, m - 1));
    }
    return res;
}
