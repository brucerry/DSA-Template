/*
    Building the Prime Sieve
*/

#include <bits/stdc++.h>
using namespace std;

#define LARGEST_NUMBER ((int)1e9)

vector<int> build_sieve(int n = LARGEST_NUMBER) {
    vector<int> isprime (n + 1, true);
    for (int f = 2; f * f <= n; f++) {
        if (isprime[f]) {
            for (int x = f * f; x <= n; x += f) {
                isprime[x] = false;
            }
        }
    }
    return isprime;
}