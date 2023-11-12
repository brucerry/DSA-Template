/*
    pow(x, n, mod) in O(logn) time
    Take mod during the process
*/

#include <bits/stdc++.h>
using namespace std;

long pow(long x, long n, long mod = 1e9+7) {
    long res = 1, p = x % mod;
    while (n) {
        if (n & 1) {
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        n >>= 1;
    }
    return res;
}